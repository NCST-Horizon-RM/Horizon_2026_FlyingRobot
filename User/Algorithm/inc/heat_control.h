#ifndef __HEAT_CONTROL_H
#define __HEAT_CONTROL_H
#define Q_PER_SHOT 10.0f          // 17mm弹丸每发热量
#define MOTOR_TICKS_PER_SHOT 36864 // 示例：M2006(36:1减速比)拨一发对应的tick数
#include <stdint.h>

typedef struct {
    uint16_t heat_limit;    // 该等级热量上限
    uint16_t cooling_rate;  // 该等级每秒冷却值
} LevelConfig_t;


typedef struct {
    float local_heat;           // 本地预测热量
    int32_t last_motor_pos;     // 上一次记录的电机总位置
    uint32_t last_update_time;  // 上次更新时间戳(ms)
    
    uint8_t current_level;      // 当前等级
    uint16_t heat_limit;        // 当前等级对应的上限
    uint16_t cooling_rate;      // 当前等级对应的冷却
	  uint8_t state;
	  float remain_heat;          //剩余热量
	  float shots_allowed;        //剩余发弹量
} HeatObserver_t;


void Update_Robot_Level(uint8_t level);
void Update_Heat_Predictor(int32_t current_motor_pos, uint32_t current_ms);
void Calibrate_Heat_With_Referee(uint16_t ref_heat);

#endif