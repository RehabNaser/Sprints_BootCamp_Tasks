/*
 * File Name: Slave_Echo.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Slave Echo Project ...
 */ 
 
 
#include "Slave_Echo.h" 

void SystemInit(void)
{
	SPI_Init(SPI_0);
	DIO_SetPinDirection(PORT_A,PIN0,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN1,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN2,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN3,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN4,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN5,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN6,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN7,PIN_OUTPUT);
}

void SystemUpdate(void)
{
	uint8_t Data;
	SPI_ReceiveChar(SPI_0,&Data,SLAVE_NAME);
	DIO_WritePin(PORT_A,PIN0,BIT_GET(Data,PIN0));
	DIO_WritePin(PORT_A,PIN1,BIT_GET(Data,PIN1));
	DIO_WritePin(PORT_A,PIN2,BIT_GET(Data,PIN2));
	DIO_WritePin(PORT_A,PIN3,BIT_GET(Data,PIN3));
	DIO_WritePin(PORT_A,PIN4,BIT_GET(Data,PIN4));
	DIO_WritePin(PORT_A,PIN5,BIT_GET(Data,PIN5));
	DIO_WritePin(PORT_A,PIN6,BIT_GET(Data,PIN6));
	DIO_WritePin(PORT_A,PIN7,BIT_GET(Data,PIN7));
}