/*
 * File Name: UART_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for UART Configuration ...
 */ 
 
#ifndef __UART_CONFIG__
#define __UART_CONFIG__

#define UART_NUMBERS (1)

#define UART0 1
#if  UART0
	#define UART0_BAUDRATE 			((uint16_t)9600)
	#define UART0_STOP_BITS_SIZE 	(ONE_STOP_BIT)
	#define UART0_PARITY_MODE 		(NO_PARITY)
	#define UART0_DATA_SIZE 		(EIGHT_BITS)
	#define UART0_MODE 				(ASYNCHRONOUS)
	#define UART0_SPEED_MODE 		(UART_SINGLE_SPEED)
	#define UART0_INTERRUPT_NUMBERS (3)
#endif

#define UART1 0
#if  UART1
	#define
#endif

#define UART2 0
#if  UART2
	#define
#endif


//UARTs NUMBER
enum Enu_UARtNumber
{
	UART_0 = 0
};

//UART INTERRUPTS TYPES
enum Enu_UARtInterruptsTypes
{
	RX_COMPLETE = 0,
	TX_COMPLETE = 1,
	DATA_REGISTER_EMPTY = 2,
};

//UART ASYNC. SPEED TYPES
#define UART_SINGLE_SPEED  0
#define	UART_DOUBLE_SPEED  1


//UART DATA SIZE
enum Enu_UARtDataSize
{
	FIVE_BITS = 0,
	SIX_BITS = 1,
	SEVEN_BITS = 2,
	EIGHT_BITS = 3,
	NINE_BITS = 7
};

//UART STOP BITS SIZE
enum Enu_UARtStopBitsSize
{
	ONE_STOP_BIT = 0,
	TWO_STOP_BIT = 1
	
};

//UART PARITY MODES
enum Enu_UARtParityModes
{
	NO_PARITY = 0,
	EVEN_PARITY = 2,
	ODD_PARITY = 3
	
};

//USART MODES
enum Enu_UARtModes
{
	ASYNCHRONOUS = 0,
	SYNCHRONOUS = 1,
};

enum Enu_UARtDataToRead
{
	NOT_AVAILABLE = 0,
	AVAILABLE = 1,
};
#endif