#include "sys.h"
int Encoder;               //编码器的脉冲计数
int Encoder4;
int Moto1; 
int Moto2;
float Angle_Balance,Gyro_Balance;

int target=0;//控制速度为0

void EXTI9_5_IRQHandler()
{
	if(PBin(5)==0)
	{
		//TIM3->SR&=0XFFFE;
		EXTI_ClearITPendingBit(EXTI_Line5);
		Led_Flash();
		Encoder=-Get_Encoder(2);
		Encoder4=Get_Encoder(4);
		Get_Angle(1);
		Moto1=velocity(Encoder+Encoder4)+PID_BControl(Angle_Balance,Gyro_Balance);
  	Moto2=velocity(Encoder+Encoder4)+PID_BControl(Angle_Balance,Gyro_Balance);
		Moto1=XianFu(Moto1);
		Moto2=XianFu(Moto2);
	  Set_Pwm(Moto1,Moto2);


		
		
	
	}
	
}
int XianFu(int moto1)
{
	if(moto1>7200)moto1=7100;
	if(moto1<-7200)moto1=-7100;
	return moto1;
	
}
/*void Set_Pwm_L(int moto1)
{
			if(moto1<0)	 	 PBout(15)=0,			PBout(14)=1;
			else 	         PBout(15)=1,			PBout(14)=0;
			TIM1->CCR1=myabs(moto1);
}
void Set_Pwm_R(int moto2)
{
		  if(moto2>0)	PBout(13)=1,			PBout(12)=0;
			else        PBout(13)=0,			PBout(12)=1;
			TIM1->CCR4=myabs(moto2);	
}*/
void Set_Pwm(int moto1,int moto2)
{
			if(moto1<0)			PBout(15)=1,			PBout(14)=0;
			else 	         PBout(15)=0,			PBout(14)=1;
			TIM1->CCR1=myabs(moto1)+400;
		  if(moto2<0)	PBout(13)=0,			PBout(12)=1;
			else        PBout(13)=1,			PBout(12)=0;
			TIM1->CCR4=myabs(moto2)+400;	
}

int myabs(int pwm)
{
	int pwm_Return;
	if(pwm<0)
	{
		pwm_Return=-pwm;

	}
		
	else 
	{
		pwm_Return=pwm;


		
		
	}
	return pwm_Return;
	
	
	
}
int PID_BControl(float Angel,float Gyro)
{
	float Kp=100,Kd=0.4;
	static float Bias;
	static int pwm;
	Bias=Angel-(0);
	pwm=Kp*Bias+Kd*Gyro;
	return pwm;	
}
/*int PID_VControl(int Encodera,int Encoder_Target)
{
	static int Bias,LastBias,pwm,Bias_Least;
	 float Kp=50,Ki=50/200;
	Bias=Encodera-Encoder_Target;
	pwm+=(Kp)*(Bias-LastBias)+(Ki)*Bias;//左轮前进正反馈;
	LastBias=Bias;
	return pwm;			
}*/
int velocity(int encodera)
{  
     static float Velocity,Encoder_Least,Encoder,Movement;
	  static float Encoder_Integral,Target_Velocity=130;
	  float kp=80,ki=kp/200;
	Movement=30;
		Encoder_Least =(encodera)-0;                    //===获取最新速度偏差==测量速度（左右编码器之和）-目标速度（此处为零） 
		Encoder *= 0.7;		                                                //===一阶低通滤波器       
		Encoder += Encoder_Least*0.3;	                                    //===一阶低通滤波器    
		Encoder_Integral +=Encoder;                                       //===积分出位移 积分时间：10ms
		Encoder_Integral=Encoder_Integral-Movement;                       
		if(Encoder_Integral>15000)  	Encoder_Integral=15000;             //===积分限幅
		if(Encoder_Integral<-15000)	Encoder_Integral=-15000;              //===积分限幅	
		Velocity=Encoder*kp+Encoder_Integral*ki;                          //===速度控制	     
	  return Velocity;
}
void Get_Angle(u8 way)
{ 
		float Accel_Y,Accel_X,Accel_Z,Gyro_Y,Gyro_Z;
	  if(way==1)                           //===DMP的读取在数据采集中断提醒的时候，严格遵循时序要求
		{	
					Read_DMP();                      //===读取加速度、角速度、倾角
					Angle_Balance=Pitch;             //===更新平衡倾角
					Gyro_Balance=gyro[1];            //===更新平衡角速度
					//Gyro_Turn=gyro[2];               //===更新转向角速度
				  //Acceleration_Z=accel[2];         //===更新Z轴加速度计

		}	
		
			
}
