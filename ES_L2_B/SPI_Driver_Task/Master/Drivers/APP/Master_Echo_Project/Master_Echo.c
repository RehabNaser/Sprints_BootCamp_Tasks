/*
 * File Name: Master_Echo.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Master Echo Project ...
 */ 
 
 
#include "Master_Echo.h" 

void SystemInit(void)
{
	SPI_Init(SPI_0);
}

void SystemUpdate(void)
{
	SPI_TransmitChar(SPI_0,'R',SLAVE_0);
	for(uint32_t i=0;i<10000;i++);
	SPI_TransmitChar(SPI_0,'e',SLAVE_0);
	for(uint32_t i=0;i<10000;i++);
	SPI_TransmitChar(SPI_0,'h',SLAVE_0);
	for(uint32_t i=0;i<10000;i++);
	SPI_TransmitChar(SPI_0,'a',SLAVE_0);
	for(uint32_t i=0;i<10000;i++);
	SPI_TransmitChar(SPI_0,'b',SLAVE_0);
	for(uint32_t i=0;i<10000;i++);	
}