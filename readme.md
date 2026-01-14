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
