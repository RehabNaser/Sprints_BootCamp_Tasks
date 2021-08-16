/*
 * File Name: UART.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for UART peripheral....
 */ 

#include "UART.h"

#if  UART0
	static Ptr_VoidFuncVoid_t saptr_UART0InterruptCallback[UART0_INTERRUPT_NUMBERS];
#endif

uint8_t UART_Init(uint8_t UARTNumber)
{
	uint16_t UBRRValue;
	switch(UARTNumber)
	{
		#if  UART0
			case UART_0:				
				UCSRC = (BIT_HIGH<<URSEL) |
						(UART0_MODE<<UMSEL) |
						(UART0_PARITY_MODE<<UPM0) |
						(UART0_STOP_BITS_SIZE<<USBS) |
						(TWO_BITS_GET(UART0_DATA_SIZE,0)<<UCSZ0);
						
				BIT_WRITE(UCSRB,UCSZ2,BIT_GET(UART0_DATA_SIZE,2));		
				
				BIT_WRITE(UCSRA,U2X,UART0_SPEED_MODE);
				#if UART0_SPEED_MODE == UART_SINGLE_SPEED
					UBRRValue=(uint16_t)((F_CPU/(16.0*UART0_BAUDRATE))-1);
				#elif UART0_SPEED_MODE == UART_DOUBLE_SPEED
					UBRRValue=(uint16_t)((F_CPU/(8.0*UART0_BAUDRATE))-1);
				#endif
				
				REG_WRITE(UBRRH,((uint8_t)(UBRRValue>>8)));
				REG_WRITE(UBRRL,((uint8_t)UBRRValue));
				
				BIT_WRITE(UCSRB,TXEN,BIT_HIGH);
				BIT_WRITE(UCSRB,RXEN,BIT_HIGH);
				break;
		#endif
		default:
			break;
	}
}

uint8_t UART_TransmitChar(uint8_t UARTNumber,uint8_t TxChar)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
				while(!(BIT_GET(UCSRA,UDRE)));
				REG_WRITE(UDR,TxChar);
				break;			
		#endif
		default:
			break;
	}
}

uint8_t UART_TransmitString(uint8_t UARTNumber,ptr_uint8_t TxString)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
			{
				uint8_t i=0;		
				do
				{
					while(!(BIT_GET(UCSRA,UDRE)));
					REG_WRITE(UDR,TxString[i]);
					//for(uint32_t i=0;i<20000;i++);
				}while(TxString[i++]!='\0');	
				break;
			}			
		#endif
		default:
			break;
	}	
}

uint8_t UART_IsDataAvailableToRead(uint8_t UARTNumber,ptr_uint8_t State)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
				if(BIT_GET(UCSRA,RXC))
				{
					*State=AVAILABLE;
				}
				else
				{
					*State=NOT_AVAILABLE;
				}
				break;			
		#endif
		default:
			break;
	}		
}

uint8_t UART_ReceiveChar(uint8_t UARTNumber,ptr_uint8_t RxData)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
				*RxData = REG_GET(UDR);
				break;			
		#endif
		default:
			break;
	}	
}

uint8_t UART_ReceiveString(uint8_t UARTNumber,ptr_uint8_t RxString)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
			{
				uint8_t DataAvailable;
				uint8_t i=0;		
				do
				{
					while(1)
					{
						UART_IsDataAvailableToRead(UART_0,&DataAvailable);
						if(DataAvailable)
						{
							RxString[i]=REG_GET(UDR);
							break;
						}	
					}
				}while(RxString[i++]!='\0');
				break;		
			}					
		#endif
		default:
			break;
	}	
}
	
uint8_t UART_EnableInterrupt(uint8_t UARTNumber,uint8_t UARTInterruptType)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
				switch(UARTInterruptType)
				{
					case RX_COMPLETE:
						BIT_WRITE(UCSRB,RXCIE,BIT_HIGH);
						break;
					case TX_COMPLETE:
						BIT_WRITE(UCSRB,TXCIE,BIT_HIGH);
						break;
					case DATA_REGISTER_EMPTY:
						BIT_WRITE(UCSRB,UDRIE,BIT_HIGH);
						break;
					default:
						break;
				}
				break;			
		#endif
		default:
			break;
	}	
}

uint8_t UART_DisableInterrupt(uint8_t UARTNumber,uint8_t UARTInterruptType)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
				switch(UARTInterruptType)
				{
					case RX_COMPLETE:
						BIT_WRITE(UCSRB,RXCIE,BIT_LOW);
						break;
					case TX_COMPLETE:
						BIT_WRITE(UCSRB,TXCIE,BIT_LOW);
						break;
					case DATA_REGISTER_EMPTY:
						BIT_WRITE(UCSRB,UDRIE,BIT_LOW);
						break;
					default:
						break;
				}
				break;			
		#endif
		default:
			break;
	}	
}

uint8_t UART_SetCallback(uint8_t UARTNumber,uint8_t UARTInterruptType,Ptr_VoidFuncVoid_t Callback)
{
	switch (UARTNumber)
	{
		#if  UART0
			case UART_0:
				saptr_UART0InterruptCallback[UARTInterruptType] = *Callback;
				break;	
		#endif
		default:
			break;
	}		
}

#if  UART0
	#if 0
		ISR (USART_RXC_vect)
		{
			saptr_UART0InterruptCallback[RX_COMPLETE]();
		}
	#endif	
	#if 0
		ISR (USART_TXC_vect)
		{
			saptr_UART0InterruptCallback[TX_COMPLETE]();
		}
	#endif
	#if 0
		ISR (USART_UDRE_vect)
		{
			saptr_UART0InterruptCallback[DATA_REGISTER_EMPTY]();	
		}
	#endif
#endif