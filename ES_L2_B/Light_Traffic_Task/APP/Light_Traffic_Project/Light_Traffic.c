/*
 * File Name: Light_Traffic.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Light Traffic Project ...
 */ 
 
 
#include "Light_Traffic.h" 

void SystemInit(void)
{
	UART_Init(UART_0);
	LED_Init();
}

void SystemUpdate(void)
{
	uint8_t String[50];
	UART_TransmitString(UART_0,"Command? ");
	UART_ReceiveString(UART_0,String);
	if(StringCompare(String,"START")==0)
	{
		LED_On(GREEN_LED);
		LED_Off(YELLOW_LED);
		LED_Off(RED_LED);
		UART_TransmitString(UART_0,"\r[Replay] Green LED is ON\r");	
	}
	else if(StringCompare(String,"WAIT")==0)
	{
		LED_On(YELLOW_LED);
		LED_Off(GREEN_LED);
		LED_Off(RED_LED);
	UART_TransmitString(UART_0,"\r[Replay] Yellow LED is ON\r");	
	}
	else if(StringCompare(String,"STOP")==0)
	{
		LED_On(RED_LED);
		LED_Off(GREEN_LED);
		LED_Off(YELLOW_LED);
		UART_TransmitString(UART_0,"\r[Replay] Red LED is ON\r");	
	}
	else if(StringCompare(String,"AT")==0)
	{
		UART_TransmitString(UART_0,"\r[Replay] OK\r");	
	}
	else
	{
		UART_TransmitString(UART_0,"\r[Replay] Invalid Command\r");	
	}
}