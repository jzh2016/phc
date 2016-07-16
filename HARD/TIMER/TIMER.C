#include "sys.h"

void Tim3_Init(int arr,int psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//��ʹ��ʱ��
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//����TIM3
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=arr;
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	//����NVIC
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	
	//TIM3�ж������ͼ�������
	TIM3->DIER|=1<<0;   //���������ж�				
	TIM3->DIER|=1<<6;   //���������ж�	   
	TIM3->CR1|=0x0001;    //ʹ�ܶ�ʱ��
	
	
	
	
	
}