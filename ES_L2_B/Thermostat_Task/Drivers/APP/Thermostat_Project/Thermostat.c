/*
 * File Name: Thermostat.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Thermostat Project ...
 */ 

#include "Thermostat.h"

static void THERMOSTAT_SetTemperature();
static uint8_t gu8_EnteredTemperature=0;

static void THERMOSTAT_SetTemperature()
{
	uint8_t u8_Key;
	uint8_t au8_EnteredKeys[TEMPERATURE_MAX_DIGITS];
	LCD_SendCommand(LCD_CLEAR_DISPALY);
	LCD_SendCommand(LCD_LINE1_DDRAM_ADDRESS(6));
	LCD_SendString("Set");
	LCD_SendCommand(LCD_LINE2_DDRAM_ADDRESS(1));
	LCD_SendString("The Temperature");
	LCD_SendCommand(LCD_CLEAR_DISPALY);
	while(1)
	{
		static uint8_t u8_Counter=0;
		KEYPAD_MustPressed(&u8_Key);
		while(1)
		{
			uint8_t u8_TempKey;
			KEYPAD_ReadKey(&u8_TempKey);
			if(u8_TempKey!=u8_Key)
			{
				break;
			}
		}
		if((u8_Key=='*')||(u8_Key=='#'))
		{
			break;
		}
		
		else if(u8_Counter==TEMPERATURE_MAX_DIGITS)
		{
			LCD_SendCommand(LCD_CLEAR_DISPALY);
			LCD_SendCommand(LCD_LINE1_DDRAM_ADDRESS(2));
			LCD_SendString("More 2 Digits");
			for(uint32_t i=0;i<10000;i++);	
			LCD_SendCommand(LCD_CLEAR_DISPALY);
			LCD_SendCommand(LCD_LINE1_DDRAM_ADDRESS(6));
			LCD_SendString("Set");
			LCD_SendCommand(LCD_LINE2_DDRAM_ADDRESS(1));
			LCD_SendString("The Temperature");
			LCD_SendCommand(LCD_CLEAR_DISPALY);					
			u8_Counter=0;
			au8_EnteredKeys[0]=au8_EnteredKeys[1]=0;
		}
		else
		{
			LCD_SendData(u8_Key);
			au8_EnteredKeys[u8_Counter]=u8_Key-48;
			u8_Counter++;
		}						
	}
	
	gu8_EnteredTemperature=(au8_EnteredKeys[0]*10)+au8_EnteredKeys[1];
		
}

void SystemInit(void)
{
	LCD_Init();
	KEYPAD_Init();
	LM35_init();
	MotorInit();
	LCD_SendCommand(LCD_DISPLAYON_CURSOROFF_NOBLINKING);
	THERMOSTAT_SetTemperature();
	LCD_SendCommand(LCD_CLEAR_DISPALY);
}

void SystemUpdate(void)
{
	uint8_t u8_Temperature;
	static uint8_t u8_MotorDuty;
	
	LM35_Read(LM35_1);
	LM35_CalculateTemp(&u8_Temperature);	
	LCD_SendCommand(LCD_LINE1_DDRAM_ADDRESS(0));
	LCD_SendString("E_T=");
	LCD_SendNumber(gu8_EnteredTemperature);	
	LCD_SendCommand(LCD_LINE1_DDRAM_ADDRESS(8));
	LCD_SendString("R_T=");
	LCD_SendNumber(u8_Temperature);	
	if(u8_Temperature<=gu8_EnteredTemperature)
	{
		u8_MotorDuty=0;
		MotorStop(MOTOR1);
	}
	else if((u8_Temperature>gu8_EnteredTemperature) && (u8_Temperature<=gu8_EnteredTemperature+5))
	{
		u8_MotorDuty=30;
		MotorStart(MOTOR1);
		MotorSetSpeed(MOTOR1,u8_MotorDuty);
	}
	else if((u8_Temperature>gu8_EnteredTemperature+5) && (u8_Temperature<=gu8_EnteredTemperature+10))
	{
		u8_MotorDuty=60;
		MotorStart(MOTOR1);
		MotorSetSpeed(MOTOR1,u8_MotorDuty);		
	}
	else
	{
		u8_MotorDuty=90;
		MotorStart(MOTOR1);
		MotorSetSpeed(MOTOR1,u8_MotorDuty);		
	}	
	
	LCD_SendCommand(LCD_LINE2_DDRAM_ADDRESS(0));
	LCD_SendString("Duty=");
	LCD_SendNumber(u8_MotorDuty);	
}