#include "IMU_Task.h"
#include "VT13.h"

#define correct_Time_define 1000    //上电去0飘 1000次取平均
#define temp_times 300       //探测温度阈值
#define Destination_TEMPERATURE 45.0f
#define IMU_GRAVITY_MPS2 9.80665f
#define IMU_STATIONARY_GYRO_ABS_MAX 0.03f
#define IMU_STATIONARY_ACCEL_NORM_MIN ((IMU_GRAVITY_MPS2 * 0.85f) * (IMU_GRAVITY_MPS2 * 0.85f))
#define IMU_STATIONARY_ACCEL_NORM_MAX ((IMU_GRAVITY_MPS2 * 1.15f) * (IMU_GRAVITY_MPS2 * 1.15f))
#define IMU_AUTO_REZERO_MIN_TICKS 200
#define IMU_AUTO_REZERO_ALPHA 0.005f
float imu=0;
/**
  * @brief          bmi088温度控制
  * @param[in]      argument: NULL
  * @retval         none
  */
void IMU_Temperature_Ctrl(IMU_Data_t *IMU, pid_type_def *imu_temp_pid)
{
	uint16_t tempPWM;
	//pid calculate. PID计算
	PID_calc(imu_temp_pid, IMU->temp, Destination_TEMPERATURE);
	if (imu_temp_pid->out < 0.0f)
	{
		imu_temp_pid->out = 0.0f;
	}
	tempPWM = (uint16_t)imu_temp_pid->out;
	SPI1_imu_pwm_set(tempPWM);
	
}

static void IMU_GyroZeroSample(IMU_Data_t *IMU)
{
    IMU->gyro_correct[0]+= IMU->gyro[0];
    IMU->gyro_correct[1]+= IMU->gyro[1];
    IMU->gyro_correct[2]+= IMU->gyro[2];

    IMU->correct_times++;
    if(IMU->correct_times>=correct_Time_define)
    {
        IMU->gyro_correct[0]/=correct_Time_define;
        IMU->gyro_correct[1]/=correct_Time_define;
        IMU->gyro_correct[2]/=correct_Time_define;

        IMU->attitude_flag=2; //go to 2 state
    }
}

static uint8_t IMU_IsStationary(const IMU_Data_t *IMU)
{
    float gx = fabsf(IMU->gyro[0]);
    float gy = fabsf(IMU->gyro[1]);
    float gz = fabsf(IMU->gyro[2]);
    if (gx > IMU_STATIONARY_GYRO_ABS_MAX || gy > IMU_STATIONARY_GYRO_ABS_MAX || gz > IMU_STATIONARY_GYRO_ABS_MAX)
    {
        return 0;
    }

    float ax = IMU->accel[0];
    float ay = IMU->accel[1];
    float az = IMU->accel[2];
    float accel_norm_sq = ax * ax + ay * ay + az * az;
    return (accel_norm_sq >= IMU_STATIONARY_ACCEL_NORM_MIN && accel_norm_sq <= IMU_STATIONARY_ACCEL_NORM_MAX) ? 1 : 0;
}

static void IMU_TryRezeroWhenStationary(IMU_Data_t *IMU, uint8_t trigger)
{
    static uint8_t stable_ticks = 0;
    static uint8_t last_trigger = 0;

    if (IMU_IsStationary(IMU))
    {
        if (stable_ticks < 50)
        {
            stable_ticks++;
        }
    }
    else
    {
        stable_ticks = 0;
    }

    if (trigger && !last_trigger && stable_ticks >= 50)
    {
        IMU->attitude_flag = 1;
        IMU->correct_times = 0;
        IMU->gyro_correct[0] = 0.0f;
        IMU->gyro_correct[1] = 0.0f;
        IMU->gyro_correct[2] = 0.0f;
    }

    last_trigger = trigger;
}

static void IMU_AutoRezeroWhenStationary(IMU_Data_t *IMU)
{
    static uint16_t stable_ticks = 0;

    if (IMU_IsStationary(IMU))
    {
        if (stable_ticks < 1000)
        {
            stable_ticks++;
        }
    }
    else
    {
        stable_ticks = 0;
    }

    if (stable_ticks >= IMU_AUTO_REZERO_MIN_TICKS)
    {
        float alpha = IMU_AUTO_REZERO_ALPHA;
        IMU->gyro_correct[0] = (1.0f - alpha) * IMU->gyro_correct[0] + alpha * IMU->gyro[0];
        IMU->gyro_correct[1] = (1.0f - alpha) * IMU->gyro_correct[1] + alpha * IMU->gyro[1];
        IMU->gyro_correct[2] = (1.0f - alpha) * IMU->gyro_correct[2] + alpha * IMU->gyro[2];
    }
}

void INS_Task(IMU_Data_t *IMU, pid_type_def *imu_temp_pid)
{
    static uint32_t count = 0;
    static uint8_t pause_last = 0;
    static uint8_t manual_rezero = 0;

    // ins update
    if ((count % 1) == 0)
    {
        BMI088_read(IMU->gyro, IMU->accel, &IMU->temp);

        uint8_t pause_now = (uint8_t)(VT13_DBUS.Remote.fn_2 != 0);
        IMU_TryRezeroWhenStationary(IMU, pause_now);
        if (pause_now && !pause_last && IMU->attitude_flag == 1)
        {
            manual_rezero = 1;
        }
        pause_last = pause_now;

        if (IMU->attitude_flag == 2 && !manual_rezero)
        {
            IMU_AutoRezeroWhenStationary(IMU);
        }
        
        if(IMU->attitude_flag==2)  //ekf的姿态解算
        {
			IMU->gyro[0]-=IMU->gyro_correct[0];   //减去陀螺仪0飘
			IMU->gyro[1]-=IMU->gyro_correct[1];
			IMU->gyro[2]-=(IMU->gyro_correct[2]+imu);
          
			//===========================================================================
			//ekf姿态解算部分
			//HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);
			IMU_QuaternionEKF_Update(
				IMU->gyro[0],IMU->gyro[1],IMU->gyro[2],
				IMU->accel[0],IMU->accel[1],IMU->accel[2]);
			
			//=============================================================================== 
			//ekf获取姿态角度函数
			IMU->pitch=Get_Pitch(); //获得pitch
			IMU->roll=Get_Roll();//获得roll
			IMU->yaw=Get_Yaw();//获得yaw
            IMU->YawTotalAngle=Get_YawTotalAngle();
			memcpy(IMU->q, QEKF_INS.q, 16);
			
			//==============================================================================
        }
        else if(IMU->attitude_flag==1)   //状态1 开始1000次的陀螺仪0飘初始化
        {
            if (manual_rezero)
            {
                IMU_GyroZeroSample(IMU);
                if (IMU->attitude_flag == 2)
                {
                    manual_rezero = 0;
                }
            }
#ifdef User_Debug
            if (!manual_rezero)
            {
                IMU_GyroZeroSample(IMU);
            }
#endif

#ifdef User_Release
            if (!manual_rezero)
            {
               IMU->gyro_correct[0] = 0.00326608913;
               IMU->gyro_correct[1] = -0.00281442143;
               IMU->gyro_correct[2] = 0.00124636071;
               IMU->attitude_flag=2; //go to 2 state
            }
#endif
        }
    }
// temperature control
    if ((count % 10) == 0)
    {
        // 100hz 的温度控制pid
        IMU_Temperature_Ctrl(IMU, imu_temp_pid);
        static uint32_t temp_Ticks=0;
#ifdef User_Debug
        if((fabsf(IMU->temp-Destination_TEMPERATURE)<0.5f)&&IMU->attitude_flag==0) //接近额定温度之差小于0.5° 开始计数
//         if(IMU->attitude_flag==0)
#endif
#ifdef User_Release
        if(IMU->attitude_flag==0)//快速初始化
#endif
        {
          temp_Ticks++;
          if(temp_Ticks>temp_times)   //计数达到一定次数后 才进入0飘初始化 说明温度已经达到目标
          {
              IMU->attitude_flag=1;  //go to correct state
          }
        }
    }
    count++;
}

