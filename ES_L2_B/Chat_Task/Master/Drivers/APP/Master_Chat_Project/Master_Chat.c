/*
 * File Name: Master_Chat.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Master Chat Project ...
 */ 
 
 
#include "Master_Chat.h" 

void SystemInit(void)
{
	UART_Init(UART_0);
	SPI_Init(SPI_0);
}

void SystemUpdate(void)
{
	uint8_t au8_Message[MESSAGE_ARRAY_SIZE];
	uint8_t u8_MessageLengthFlag=LENGTH_IS_OK;
	uint8_t u8_DataAvailableToRead;		
	
	UART_TransmitString(UART_0,"Enter Your Message:\r");
	
	uint8_t u8_LoopVariable=0;
	do
	{
		while(1)
		{
			UART_IsDataAvailableToRead(UART_0,&u8_DataAvailableToRead);
			if(u8_DataAvailableToRead)
			{
				UART_ReceiveChar(UART_0,&au8_Message[u8_LoopVariable]);
				break;
			}	
		}			
		
		if((u8_LoopVariable==MASSAGE_MAX_LENGHT)&&(au8_Message[u8_LoopVariable]!='\r'))
		{
			u8_MessageLengthFlag=LENGTH_IS_LONG;
			break;
		}
	
	}while(au8_Message[u8_LoopVariable++]!='\r');
	au8_Message[--u8_LoopVariable]='\0';


	if(u8_MessageLengthFlag==LENGTH_IS_LONG)
	{
		UART_TransmitString(UART_0,"\rMessage more than 255 Chars !!\r");
	}
	else
	{
		UART_TransmitString(UART_0,"Sending....\r");
		SPI_TransmitString(SPI_0,au8_Message,SLAVE_0);
	}
}