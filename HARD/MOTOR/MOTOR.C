#include "sys.h"



void PWM_Init()
{
	//配置TIM1
	TIM_TimeBaseInitTypeDef 	TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef 	TIM_OCInitStrycture;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=7199;
	TIM_TimeBaseInitStructure.TIM_Prescaler=0;//不分频
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
	
	
	//配置TIM1OC1,4
	TIM_OCInitStrycture.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStrycture.TIM_OutputState=TIM_OutputState_Enable;	
	TIM_OCInitStrycture.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC1Init(TIM1,&TIM_OCInitStrycture);
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);

	TIM_OCInitStrycture.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStrycture.TIM_OutputState=TIM_OutputState_Enable;	
	TIM_OCInitStrycture.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC4Init(TIM1,&TIM_OCInitStrycture);
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);
	
	//TIM1->CR1|=1<<0;//是使能计数器
	//TIM1->CR1|=1<<7;//APRE使能
	//TIM1->BDTR |= 1<<15; //TIM1必须有这句话才能输出pwm	
	TIM_ARRPreloadConfig(TIM1, ENABLE);			                   // 使能TIM1重载寄存器ARR  
  TIM_Cmd(TIM1, ENABLE); 
	TIM_CtrlPWMOutputs(TIM1, ENABLE); 	
}

void Motor_Init()
{
	//IO管脚配置
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//复用管脚配置
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_11;//GPIOA8,11复用输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}
	


	
	
	
	
	
	
	
	
	
