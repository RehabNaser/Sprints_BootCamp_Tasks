/*
 * File Name: SPI_Config.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for SPI Configuration ...
 */ 
 
#include "SPI.h"
				
#if  SPI0
	#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
		uint8_t gau8_SPI0SlaveConfig[SPI0_SLAVES_NUMBER][2]= {
																{PORT_B,PIN4},
																{PORT_A,PIN0},
																{PORT_C,PIN7}
															};
	#endif
#endif