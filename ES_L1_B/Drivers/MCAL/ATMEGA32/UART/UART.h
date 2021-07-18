/*
 * File Name: UART.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for UART peripheral....
 */ 

#ifndef __UART__
#define __UART__

//FILES INCLUDING
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MC_REGISTERS.h"

#include "UART_Config.h"
#include "UART_RetVal.h"


//FUNCTIONS PROTOTYPES

uint8_t UART_Init(uint8_t UARTNumber);

uint8_t UART_TransmitChar(uint8_t UARTNumber,uint8_t TxChar);//Polling, put can used on interrupt mode
uint8_t UART_TransmitString(uint8_t UARTNumber,ptr_uint8_t TxString);//Polling + delay between each char

uint8_t UART_IsDataAvailableToRead(uint8_t UARTNumber,ptr_uint8_t State);//using before receiving char
uint8_t UART_ReceiveChar(uint8_t UARTNumber,ptr_uint8_t RxData);//for polling and interrupt mode
uint8_t UART_ReceiveString(uint8_t UARTNumber,ptr_uint8_t RxString);//polling

uint8_t UART_EnableInterrupt(uint8_t UARTNumber,uint8_t UARTInterruptType);
uint8_t UART_DisableInterrupt(uint8_t UARTNumber,uint8_t UARTInterruptType);
uint8_t UART_SetCallback(uint8_t UARTNumber,uint8_t UARTInterruptType,Ptr_VoidFuncVoid_t Callback);

#endif