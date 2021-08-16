/*
 * File Name: Motor.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for Motors...
 */ 

#include "Motor.h"

extern Str_MotorConfig_t gastr_MotorConfig[MOTORS_MAX_NUMBERS][MOTOR_PINS_NUMBERS];
extern uint8_t gau8_MotorsEnablePin[MOTORS_MAX_NUMBERS];													

uint8_t MotorInit(void)
{
	for(uint8_t au8_IterationNo1=0;au8_IterationNo1<MOTORS_MAX_NUMBERS;au8_IterationNo1++)
	{
		PwmStart(gau8_MotorsEnablePin[au8_IterationNo1]);
		for(uint8_t au8_IterationNo2=0;au8_IterationNo2<MOTOR_PINS_NUMBERS;au8_IterationNo2++)
		{
			DIO_SetPinDirection(	gastr_MotorConfig[au8_IterationNo1][au8_IterationNo2].MotorPort,
									gastr_MotorConfig[au8_IterationNo1][au8_IterationNo2].MotorPin,
									gastr_MotorConfig[au8_IterationNo1][au8_IterationNo2].MotorDirection );			
		}				   	
	}
	PwmInit();
}

uint8_t MotorStart(uint8_t MotorNumber)
{
	PwmConnect(gau8_MotorsEnablePin[MotorNumber]);
}

uint8_t MotorStop(uint8_t MotorNumber)
{
	PwmDisconnect(gau8_MotorsEnablePin[MotorNumber]);
}

uint8_t MotorSetSpeed(uint8_t MotorNumber,uint8_t MotorDuty)
{
	PwmSetDuty(gau8_MotorsEnablePin[MotorNumber],MotorDuty);
}