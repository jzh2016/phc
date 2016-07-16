#ifndef __CONTORL_H
#define __CONTROL_H
#include "sys.h"
void TIM3_IRQHandler();
void EXTI9_5_IRQHandler();
int PID_VControl(int Encodera,int Encoder_Target);
int velocity(int encodera);
int PID_BControl(float Angel,float Gyro);
int myabs(int pwm);
int XianFu(int moto1);
void Set_Pwm(int moto1,int moto2);
void Get_Angle(u8 way);
#endif