/*
 * File Name: Speed_Control_System.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Speed Control System ...
 */ 
 
 
#include "Speed_Control_System.h" 

void SystemInit(void)
{
	PwmInit();
	ButtonInit();
	
	GpioSetPinDirection(PORT_B,PIN3,PIN_OUTPUT);
	GpioSetPinDirection(PORT_D,PIN4,PIN_OUTPUT);
	GpioSetPinDirection(PORT_D,PIN5,PIN_OUTPUT);
	GpioSetPinDirection(PORT_D,PIN7,PIN_OUTPUT);
	
	PwmStart(PWM_CHANNEL_OC0);
	PwmStart(PWM_CHANNEL_OC1A);
	PwmStart(PWM_CHANNEL_OC2);
	
	PwmConnect(PWM_CHANNEL_OC0);
	PwmConnect(PWM_CHANNEL_OC1A);
	PwmConnect(PWM_CHANNEL_OC1B);
	PwmConnect(PWM_CHANNEL_OC2);
	
}

void SystemUpdate(void)
{
	uint8_t au8_ButtonState = NO_PRESSED;
	static uint8_t au8_ButtonFlag = 0;
	static uint8_t au8_ButtonPressCounter = 0;
	for(uint32_t i=0;i<100000;i++);//For Debouncing
	ButtonRead(BUTTON1,&au8_ButtonState);
	if(au8_ButtonState==PRESSED&&au8_ButtonFlag==0&&au8_ButtonPressCounter==0)
	{
		PwmSetDuty(PWM_CHANNEL_OC0,SPEED_30);
		PwmSetDuty(PWM_CHANNEL_OC1A,SPEED_30);
		PwmSetDuty(PWM_CHANNEL_OC1B,SPEED_30);
		PwmSetDuty(PWM_CHANNEL_OC2,SPEED_30);
		au8_ButtonPressCounter++;
		au8_ButtonFlag=1;
	}
	else if(au8_ButtonState==PRESSED&&au8_ButtonFlag==0&&au8_ButtonPressCounter==1)
	{
		PwmSetDuty(PWM_CHANNEL_OC0,SPEED_60);
		PwmSetDuty(PWM_CHANNEL_OC1A,SPEED_60);
		PwmSetDuty(PWM_CHANNEL_OC1B,SPEED_60);
		PwmSetDuty(PWM_CHANNEL_OC2,SPEED_60);
		au8_ButtonPressCounter++;
		au8_ButtonFlag=1;
	}
	else if(au8_ButtonState==PRESSED&&au8_ButtonFlag==0&&au8_ButtonPressCounter==2)
	{
		PwmSetDuty(PWM_CHANNEL_OC0,SPEED_90);
		PwmSetDuty(PWM_CHANNEL_OC1A,SPEED_90);
		PwmSetDuty(PWM_CHANNEL_OC1B,SPEED_90);
		PwmSetDuty(PWM_CHANNEL_OC2,SPEED_90);
		au8_ButtonPressCounter=0;
		au8_ButtonFlag=1;
	}
	else if(au8_ButtonState==NO_PRESSED&&au8_ButtonFlag==1)
	{
		au8_ButtonFlag=0;
	}
}