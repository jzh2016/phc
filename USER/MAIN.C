#include "sys.h"
u8 Flag_Qian,Flag_Hou,Flag_Left,Flag_Right;
int main(void)
{
	delay_init();
	JTAG_Set(JTAG_SWD_DISABLE);     //=====关闭JTAG接口
	JTAG_Set(SWD_ENABLE);	//=====打开SWD接口 可以利用主板的SWD接口调试
	Led_Init();
	//Motor_Init();
	PWM_Init();
	EncoderR_Init();
	EncoderL_Init();
	OLED_Init();
	IIC_Init(); //=====IIC初始化
  MPU6050_initialize();  	//=====MPU6050初始化	
	DMP_Init();	
	delay_ms(300);
	//Tim3_Init(49,7199);//5ms进入一次中断 
	MiniBalance_EXTI_Init();
	while(1)
	{	
	 oled_show();
	}
	
	
	
	
}