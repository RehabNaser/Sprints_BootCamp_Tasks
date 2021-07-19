/*
 * File Name: Echo.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Echo Project ...
 */ 
 
 
#include "Echo.h" 

void SystemInit(void)
{
	UART_Init(UART_0);
}

void SystemUpdate(void)
{
	uint8_t String[50];
	UART_ReceiveString(UART_0,String);
	UART_TransmitString(UART_0,String);	
}