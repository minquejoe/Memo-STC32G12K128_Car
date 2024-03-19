#include "motor.h"
#include "delay.h"
#include "motor.h"
#include "delay.h"
#include "timer.h"
#include "LED.h"

/***************************电机端口定义*************************************/
sbit LH_B=P2^0;
sbit LH_F=P2^1;

sbit RH_F=P2^2;
sbit RH_B=P2^3;

sbit RQ_F=P1^4;
sbit RQ_B=P1^5;

sbit LQ_F=P1^6;
sbit LQ_B=P1^7;

//========================================================================
// 函数: void Motor_Init_Port(void)
// 描述: 延时函数。
// 参数: 初始化电机端口
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注:
//========================================================================
void Motor_Init_Port(void)
{
  P2M0 |= 0x0F;
  P2M1 |= 0x00;

  P1M0 |= 0xF0;
  P1M1 |= 0x00;

  delay_ms(50); //等待稳定
}
//========================================================================
// 函数: void Car_Forword(void)
// 描述: 前进
// 参数:  pwm_perent 占空比百分比
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注:
//========================================================================
void Car_Forword(uint8 pwm_perent)//前进
{

  PWM_Count = pwm_perent;

  LH_B=0;
  LH_F=1;

  RH_F=0;
  RH_B=1;

  RQ_F=0;
  RQ_B=1;

  LQ_F=0;
  LQ_B=1;
	
	LED_L = 0;
	LED_R = 0;
	
}
//========================================================================
// 函数: void Car_Back(void)
// 描述: 后退
// 参数: pwm_perent 占空比百分比
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注:
//========================================================================
void Car_Back(uint8 pwm_perent)//后退
{
  PWM_Count = pwm_perent;

  LH_B=1;
  LH_F=0;

  LQ_F=1;
  LQ_B=0;

  RH_F=1;
  RH_B=0;

  RQ_F=1;
  RQ_B=0;

	LED_L = 1;
	LED_R = 1;

}
//========================================================================
// 函数: void Car_Turn_Left(void)
// 描述: 左转
// 参数: pwm_perent 占空比百分比
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注:
//========================================================================
void Car_Turn_Left(uint8 pwm_perent)//左转
{
  PWM_Count = pwm_perent;
	
	LQ_F=0;
  LQ_B=1;

  LH_B=1;
  LH_F=0;

  RH_F=0;
  RH_B=1;

  RQ_F=0;
  RQ_B=1;
	
	LED_L = 1;
	LED_R = 0;

}
//========================================================================
// 函数: void Car_Turn_Right(void)
// 描述: 右转
// 参数: pwm_perent 占空比百分比
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注:
//========================================================================
void Car_Turn_Right(uint8 pwm_perent)//右转
{
  PWM_Count = pwm_perent;

  LQ_F=0;
  LQ_B=1;

  LH_B=0;
  LH_F=1;

  RH_F=0;
  RH_B=1;

  RQ_F=1;
  RQ_B=0;
	
	LED_L = 0;
	LED_R = 1;

}
//========================================================================
// 函数: void Car_Stop(void)
// 描述: 右转
// 参数: pwm_perent 占空比百分比
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注:
//========================================================================
void Car_Stop(void)//停止
{

  LH_B=0;
  LH_F=0;

  RH_F=0;
  RH_B=0;

  RQ_F=0;
  RQ_B=0;

  LQ_F=0;
  LQ_B=0;
	
	LED_L = 0;
	LED_R = 0;
}

// 2024/01/15 添加，此处方向为小车移动方向，非转弯方向
// Count_State_number  7  左后
// Count_State_number  8  右后

void Car_Back_Left(uint8 pwm_perent)//后左
{
  PWM_Count = pwm_perent;

	LH_B=1;
  LH_F=0;

  LQ_F=1;
  LQ_B=0;

  RH_F=1;
  RH_B=0;

  RQ_F=0;
  RQ_B=1;
	
	LED_L = 0;
	LED_R = 1;

}

void Car_Back_Right(uint8 pwm_perent)//后右
{
  PWM_Count = pwm_perent;

	LH_B=0;
  LH_F=1;

  LQ_F=1;
  LQ_B=0;

  RH_F=1;
  RH_B=0;

  RQ_F=1;
  RQ_B=0;
	
	LED_L = 1;
	LED_R = 0;

}

// 2024/01/17 添加按键控制 纯左掉头/右掉头
// Count_State_number 9   纯左掉头
// Count_State_number 10  纯右掉头
void Car_Pure_Left(uint8 pwm_perent)// 纯左转
{
  PWM_Count = pwm_perent;
	
	LQ_F=1;
  LQ_B=0;

  LH_B=1;
  LH_F=0;

  RH_F=0;
  RH_B=1;

  RQ_F=0;
  RQ_B=1;
	
	LED_L = 1;
	LED_R = 0;

}

void Car_Pure_Right(uint8 pwm_perent)// 纯右转
{
  PWM_Count = pwm_perent;
	
  LQ_F=0;
  LQ_B=1;

  LH_B=0;
  LH_F=1;

  RH_F=1;
  RH_B=0;

  RQ_F=1;
  RQ_B=0;
	
	LED_L = 0;
	LED_R = 1;

}



























































