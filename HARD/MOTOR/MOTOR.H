#ifndef __MOTOR_H
#define __MOTOR_H
#include "sys.h"
void PWM_Init();
void Motor_Init();
void MiniBalance_Motor_Init(void);
void MiniBalance_PWM_Init(u16 arr,u16 psc);
#endif