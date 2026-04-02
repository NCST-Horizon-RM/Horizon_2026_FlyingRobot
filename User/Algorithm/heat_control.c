#include <heat_control.h>
static const LevelConfig_t Level_Table[11] = {
    {100, 20},  // Level 1: 上限50, 冷却40/s
    {110, 30},  // Level 2: 上限100, 冷却60/s
    {120, 40},
    {130, 50},
    {140, 60},
    {150, 70},
    {160, 80},
    {170, 90},
    {180, 100},
    {200, 120},
		{1000,1000}
};
HeatObserver_t g_heat_watcher;
/**
 * @brief 更新机器人等级参数
 * @param level 传入最新等级
 */
void Update_Robot_Level(uint8_t level) {
    if (level < 1) level = 1;
    if (level > 11) level = 11;
    
    g_heat_watcher.current_level = level;
    // 从查表获取对应等级的属性
    g_heat_watcher.heat_limit = Level_Table[level - 1].heat_limit;
    g_heat_watcher.cooling_rate = Level_Table[level - 1].cooling_rate;
}

/**
 * @brief 实时热量预测更新 
 * @param current_motor_pos 电机当前编码器累加位置 
 * @param current_ms 当前系统时间戳
 */
void Update_Heat_Predictor(int32_t current_motor_pos, uint32_t current_ms) {
    // 1. 计算时间步长
    float dt = (current_ms - g_heat_watcher.last_update_time) / 1000.0f;
    g_heat_watcher.last_update_time = current_ms;
    
    // 如果是第一次运行或dt异常，跳过增量计算
    if (dt <= 0 || dt > 0.5f) return; 

    // 2. 计算发弹增量
    int32_t delta_pos = current_motor_pos - g_heat_watcher.last_motor_pos;
    if (delta_pos < 0) delta_pos = -delta_pos; // 绝对值处理
    
    float shots_fired = (float)delta_pos / MOTOR_TICKS_PER_SHOT;
    g_heat_watcher.last_motor_pos = current_motor_pos;

    // 3. 热量更新核心公式
    // 热量 = 现有热量 + (新发数 * 单发热量) - (当前等级冷却值 * 时间增量)
    g_heat_watcher.local_heat += (shots_fired * Q_PER_SHOT);
    g_heat_watcher.local_heat -= (g_heat_watcher.cooling_rate * dt);

    // 边界限制：热量不为负
    if (g_heat_watcher.local_heat < 0) g_heat_watcher.local_heat = 0;
		g_heat_watcher.remain_heat=(float)g_heat_watcher.heat_limit - g_heat_watcher.local_heat;
		g_heat_watcher.shots_allowed=g_heat_watcher.remain_heat/ Q_PER_SHOT;
		    // 状态切换判定
    if (g_heat_watcher.shots_allowed >= 3.0f) {
			  g_heat_watcher.state=1;
       // 可以发射
    } 
		else {
			  g_heat_watcher.state=0;
        // 不可以发射
    }
}

/**
 * @brief 裁判系统权威数据校准
 */
void Calibrate_Heat_With_Referee(uint16_t ref_heat) {
    g_heat_watcher.local_heat = (float)ref_heat;
}

