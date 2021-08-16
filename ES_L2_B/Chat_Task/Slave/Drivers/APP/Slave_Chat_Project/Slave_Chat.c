/*
 * File Name: Slave_Chat.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Slave Chat Project ...
 */ 
 
 
#include "Slave_Chat.h" 

void SystemInit(void)
{
	UART_Init(UART_0);
	SPI_Init(SPI_0);
}

void SystemUpdate(void)
{
	uint8_t au8_Message[MESSAGE_ARRAY_SIZE];
	SPI_ReceiveString(SPI_0,au8_Message,SLAVE_NAME);
	UART_TransmitString(UART_0,"Message: ");
	UART_TransmitString(UART_0,au8_Message);
	UART_TransmitChar(UART_0,'\r');
}