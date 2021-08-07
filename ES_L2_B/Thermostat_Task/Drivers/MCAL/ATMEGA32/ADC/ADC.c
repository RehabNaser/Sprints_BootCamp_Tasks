/*
 * File Name: ADC.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for ADC peripheral....
 */ 

#include "ADC.h"

#if  ADC0
	static Ptr_VoidFuncVoid_t saptr_ADCInterruptCallback[ADC_NUMBERS];
#endif


uint8_t ADC_Init(uint8_t ADCNumber)
{
	switch(ADCNumber)
	{
		#if  ADC0
			case ADC_0:
				TWO_BITS_WRITE(ADMUX,REFS0,ADC0_REFERENCE_VOLTAGE);//Select ADC reference voltage
				#if ADC0_CONVERSION_MODE==ADC_AUTO_TRIGGER_MODE
					BIT_WRITE(ADCSRA,ADATE,BIT_HIGH);
					THREE_BITS_WRITE(SFIOR,ADTS0,ADC0_AUTO_TRIGGER_SOURCE);					
				#endif				
				THREE_BITS_WRITE(ADCSRA,ADPS0,ADC0_PRESCALER);//Set Prescaler	
				BIT_WRITE(ADCSRA,ADEN,BIT_HIGH);//Enable ADC
				break;
		#endif
		default:
			break;
	}	
}

uint8_t ADC_Enable(uint8_t ADCNumber)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				BIT_WRITE(ADCSRA,ADEN,BIT_HIGH);
				break;
		#endif
		default:
			break;
	}
}

uint8_t ADC_Disable(uint8_t ADCNumber)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				BIT_WRITE(ADCSRA,ADEN,BIT_LOW);
				break;
		#endif
		default:
			break;
	}
}

uint8_t ADC_StartConversion(uint8_t ADCNumber,uint8_t ADCPinNumber)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				FIVE_BITS_WRITE(ADMUX,MUX0,ADCPinNumber);
				BIT_WRITE(ADCSRA,ADSC,BIT_HIGH); 
				break;
		#endif
		default:
			break;
	}	
}

uint8_t ADC_GetConversionValue(uint8_t ADCNumber,ptr_uint16_t DigitalValue)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				while(BIT_GET(ADCSRA,ADSC));
				*DigitalValue=REG_GET(ADC);
				break;
		#endif
		default:
			break;
	}	
}

uint8_t ADC_ConvertReadingFromDigitalToAnalog(uint16_t DigitalValue,float32_t* AnalogValue)
{
	#if ADC0_REFERENCE_VOLTAGE==AVCC
		*AnalogValue=(DigitalValue*(AVCC_VOLT/ADC0_RESOLUTION));
	#elif ADC0_REFERENCE_VOLTAGE==AREF
		*AnalogValue=(DigitalValue*(AREF_VOLT/ADC0_RESOLUTION));
	#elif ADC0_REFERENCE_VOLTAGE==INTERNAL
		*AnalogValue=(DigitalValue*(INTERNAL_VOLT/ADC0_RESOLUTION));
	#endif
}

uint8_t ADC_EnableInterrupt(uint8_t ADCNumber)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				BIT_WRITE(ADCSRA,ADIE,BIT_HIGH);
				break;
		#endif
		default:
			break;
	}	
}

uint8_t ADC_DisableInterrupt(uint8_t ADCNumber)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				BIT_WRITE(ADCSRA,ADIE,BIT_LOW);
				break;
		#endif
		default:
			break;
	}		
}

uint8_t ADC_SetCallback(uint8_t ADCNumber,Ptr_VoidFuncVoid_t Callback)
{
	switch(ADCNumber)
	{
		#if ADC0
			case ADC_0:
				saptr_ADCInterruptCallback[ADC_0] = *Callback;
				break;
		#endif
		default:
			break;
	}			
}

#if  ADC0
	#if 0
		ISR (ADC_vect)
		{
			saptr_ADCInterruptCallback[ADC_0]();
		}
	#endif
#endif