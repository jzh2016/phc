#include "sys.h"
void EncoderL_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	TIM2->CR1|=1<<0;
	TIM2->CCMR1|=1<<0;//CI1映射在T11
	TIM2->CCMR1|=1<<8;
  TIM2->CCER &=0xFFFD;           //IC1不反向
  TIM2->CCER &=0xFFDF;           //IC2不反向
	TIM2->SMCR|=3<<0;
	TIM2->ARR=65535;

	
}
void EncoderR_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	TIM4->CR1|=1<<0;
	TIM4->CCMR1|=1<<0;//CI1映射在T11
	TIM4->CCMR1|=1<<8;
  TIM4->CCER &=0xFFFD;           //IC1不反向
  TIM4->CCER &=0xFFDF;           //IC2不反向
	TIM4->SMCR|=3<<0;
	TIM4->ARR=65535;
	//TIM4->ARR = ENCODER_TIM_PERIOD-1;//设定计数器自动重装值 
	
	
	
	
}
int Get_Encoder(int a)
{
	int Encoder;
	switch(a)
	{
		case(2):Encoder=(short)TIM2->CNT;  TIM2->CNT=0;  break;
		case(4):Encoder=(short)TIM4->CNT;  TIM4->CNT=0;  break;
		default:  Encoder=0;
		
	}
	return Encoder;
	

}