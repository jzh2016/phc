#include "sys.h"


void Led_Init()
{
	GPIO_InitTypeDef GPIO_InitStrcture;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStrcture.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStrcture.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStrcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrcture);	
	GPIO_SetBits(GPIOA,GPIO_Pin_12);
}


void Led_Flash()
{
	static int number;
	static int state;//¼ÇÂ¼LED×´Ì¬£¬1ÎªµãÁÁ
	if(state==1)
	{
		if(++number==100)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_12);
			state=0;
			number=0;
		}
	}
		else
		{
			if(++number==500)
			{
				GPIO_SetBits(GPIOA,GPIO_Pin_12);
				state=1;
				number=0;
			}
		}			
}