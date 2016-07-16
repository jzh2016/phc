#include "sys.h"
u8 Flag_Qian,Flag_Hou,Flag_Left,Flag_Right;
int main(void)
{
	delay_init();
	JTAG_Set(JTAG_SWD_DISABLE);     //=====�ر�JTAG�ӿ�
	JTAG_Set(SWD_ENABLE);	//=====��SWD�ӿ� �������������SWD�ӿڵ���
	Led_Init();
	//Motor_Init();
	PWM_Init();
	EncoderR_Init();
	EncoderL_Init();
	OLED_Init();
	IIC_Init(); //=====IIC��ʼ��
  MPU6050_initialize();  	//=====MPU6050��ʼ��	
	DMP_Init();	
	delay_ms(300);
	//Tim3_Init(49,7199);//5ms����һ���ж� 
	MiniBalance_EXTI_Init();
	while(1)
	{	
	 oled_show();
	}
	
	
	
	
}