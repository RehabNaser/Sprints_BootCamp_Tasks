/*
 * File Name: SPI.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for SPI peripheral....
 */ 

#include "SPI.h"

#if  SPI0
	static Ptr_VoidFuncVoid_t saptr_SPIInterruptCallback[SPI_NUMBERS];
	#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
		extern uint8_t gau8_SPI0SlaveConfig[SPI0_SLAVES_NUMBER][2];
	#endif
#endif
	
uint8_t SPI_Init(uint8_t SPINumber)
{
	switch(SPINumber)
	{
		#if  SPI0
			case SPI_0:
				
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_SetPinDirection(SPI0_PORT,SPI0_MOSI_PIN,PIN_OUTPUT);
					DIO_SetPinDirection(SPI0_PORT,SPI0_SCK_PIN,PIN_OUTPUT);
					
					for(uint8_t au8_IterationNo=0;au8_IterationNo<SPI0_SLAVES_NUMBER;au8_IterationNo++)
					{
						DIO_SetPinDirection(	gau8_SPI0SlaveConfig[au8_IterationNo][0],
												gau8_SPI0SlaveConfig[au8_IterationNo][1],
												PIN_OUTPUT );			
						
						DIO_WritePin(	gau8_SPI0SlaveConfig[au8_IterationNo][0],
										gau8_SPI0SlaveConfig[au8_IterationNo][1],
										PIN_HIGH);					
					}					

					SPCR = 	(SPI0_MASTER_SLAVE_SELECTOR<<MSTR)|
							(SPI0_DATA_ORDER<<DORD) |
							(SPI0_MODE<<CPHA) |
							(SPI0_CLK_FREQUENCY<<SPR0);					
					
					BIT_WRITE(SPSR,SPI2X,SPI0_SPEED_MODE);
					
				#elif SPI0_MASTER_SLAVE_SELECTOR == SPI_SLAVE
					DIO_SetPinDirection(SPI0_PORT,SPI0_MISO_PIN,PIN_OUTPUT);
					SPCR = 	(SPI0_MASTER_SLAVE_SELECTOR<<MSTR)|
							(SPI0_DATA_ORDER<<DORD) |
							(SPI0_MODE<<CPHA) ;							
				#endif
				BIT_WRITE(SPCR,SPE,BIT_HIGH);
				break;
		#endif
		default:
			break;
	}
}

uint8_t SPI_TransmitChar(uint8_t SPINumber,uint8_t TxChar,uint8_t SlaveNumber)
{
	switch(SPINumber)
	{
		#if  SPI0
			case SPI_0:
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_LOW);
				#endif
				
				REG_WRITE(SPDR,TxChar);
				while(!(BIT_GET(SPSR,SPIF)));
				
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_HIGH);
				#endif
				break;
		#endif
		default:
			break;
	}	
}

uint8_t SPI_TransmitString(uint8_t SPINumber,ptr_uint8_t TxString,uint8_t SlaveNumber)
{
	switch (SPINumber)
	{
		#if  SPI0
			case SPI_0:
			{
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_LOW);
				#endif
				
				uint8_t i=0;		
				do
				{
					REG_WRITE(SPDR,TxString[i]);
					while(!(BIT_GET(SPSR,SPIF)));
				}while(TxString[i++]!='\0');					
				
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_HIGH);
				#endif				
				break;	
			}	
		#endif
		default:
			break;
	}	
}
 
uint8_t SPI_ReceiveChar(uint8_t SPINumber,ptr_uint8_t RxData,uint8_t SlaveNumber)
{
	switch(SPINumber)
	{
		#if  SPI0
			case SPI_0:
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_LOW);
				#endif
				
				while(!(BIT_GET(SPSR,SPIF)));
				*RxData = REG_GET(SPDR);
				
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_HIGH);
				#endif
				break;
		#endif
		default:
			break;
	}	
}

uint8_t SPI_ReceiveString(uint8_t SPINumber,ptr_uint8_t RxString,uint8_t SlaveNumber)
{
	switch (SPINumber)
	{
		#if  SPI0
			case SPI_0:
			{
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_LOW);
				#endif
				
				uint8_t i=0;		
				do
				{
					while(!(BIT_GET(SPSR,SPIF)));
					RxString[i] = REG_GET(SPDR);
				}while(RxString[i++]!='\0');
				
				#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
					DIO_WritePin(	gau8_SPI0SlaveConfig[SlaveNumber][0],
									gau8_SPI0SlaveConfig[SlaveNumber][1],
									PIN_HIGH);
				#endif				
				break;		
			}					
		#endif
		default:
			break;
	}	
}

uint8_t SPI_EnableInterrupt(uint8_t SPINumber)
{
	switch (SPINumber)
	{
		#if  SPI0
			case SPI_0:
				BIT_WRITE(SPCR,SPIE,BIT_HIGH);	
				break;			
		#endif
		default:
			break;
	}	
}

uint8_t SPI_DisableInterrupt(uint8_t SPINumber)
{
	switch (SPINumber)
	{
		#if  SPI0
			case SPI_0:
				BIT_WRITE(SPCR,SPIE,BIT_LOW);	
				break;			
		#endif
		default:
			break;
	}		
}

uint8_t SPI_SetCallback(uint8_t SPINumber,Ptr_VoidFuncVoid_t Callback)
{
	switch (SPINumber)
	{
		#if  SPI0
			case SPI_0:
				saptr_SPIInterruptCallback[SPI_0] = *Callback;
				break;	
		#endif
		default:
			break;
	}		
}

#if  SPI0
	#if 0
		ISR (SPI_STC_vect)
		{
			saptr_SPIInterruptCallback[SPI_0]();
		}
	#endif
#endif