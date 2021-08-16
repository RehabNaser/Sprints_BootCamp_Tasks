/*
 * File Name: SPI.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for SPI peripheral....
 */ 

#ifndef __SPI__
#define __SPI__

//FILES INCLUDING
//#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MC_REGISTERS.h"
#include "DIO.h"
#include "SPI_Config.h"
#include "SPI_RetVal.h"


//FUNCTIONS PROTOTYPES
uint8_t SPI_Init(uint8_t SPINumber);

//Assuming all slaves have the same configuration (Data order,SPI mode,Work at same Master Speed)

uint8_t SPI_TransmitChar(uint8_t SPINumber,uint8_t TxChar,uint8_t SlaveNumber);//Polling,Can't use on interrupt 
uint8_t SPI_TransmitString(uint8_t SPINumber,ptr_uint8_t TxString,uint8_t SlaveNumber);//Polling,Can't use on interrupt 
 
uint8_t SPI_ReceiveChar(uint8_t SPINumber,ptr_uint8_t RxData,uint8_t SlaveNumber);//Polling,Can't use on interrupt 
uint8_t SPI_ReceiveString(uint8_t SPINumber,ptr_uint8_t RxString,uint8_t SlaveNumber);//Polling,Can't use on interrupt 

uint8_t SPI_EnableInterrupt(uint8_t SPINumber);
uint8_t SPI_DisableInterrupt(uint8_t SPINumber);

uint8_t SPI_SetCallback(uint8_t SPINumber,Ptr_VoidFuncVoid_t Callback);

#endif