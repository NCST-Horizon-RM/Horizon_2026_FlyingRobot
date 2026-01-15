## 无人机云台

> f4 c 板框架移植
> 
### 记录
2026.1.15 
注意和视觉通讯的yaw pitch在获取时均为
```c
 VisionRx->PitchAngle = Union_temp.Data_f;
 VisionRx->YawAngle = Union_temp.Data_f;
```
发送时均为
```c
VisionTxData.PitchAngle = -PitchAngle;
VisionTxData.YawAngle = -YawAngle;
```

### 坑
注意pid限幅 dt 

### 安装
桨叶电机线序 在桨叶电机的 电调正放置，电机转子孔位朝上时 三相线依次对应
