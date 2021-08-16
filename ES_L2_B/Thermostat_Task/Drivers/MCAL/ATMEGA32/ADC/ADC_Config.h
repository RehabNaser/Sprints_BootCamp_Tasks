/*
 * File Name: ADC_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for ADC Configuration ...
 */ 
 
#ifndef __ADC_CONFIG__
#define __ADC_CONFIG__

#define ADC_NUMBERS (1)

#define ADC0 1
#if  ADC0
	#define ADC0_PRESCALER			ADC_PRESC_128
	#define ADC0_RESOLUTION			(1024.0)
	#define ADC0_CONVERSION_MODE	ADC_SINGLE_CONVERSION_MODE
	#if ADC0_CONVERSION_MODE==ADC_AUTO_TRIGGER_MODE
		#define ADC0_AUTO_TRIGGER_SOURCE	FREE_RUNNING_MODE
	#endif	
	
	#define ADC0_REFERENCE_VOLTAGE	AVCC
	#if ADC0_REFERENCE_VOLTAGE==AREF
		#define AREF_VOLT 			0
	#endif
#endif


///ADC CONVERSION MODES
#define ADC_SINGLE_CONVERSION_MODE	0
#define ADC_AUTO_TRIGGER_MODE		1

//ADC REFERENCE VOLTAGES 
#define AREF 		0
#define AVCC 		1
#define INTERNAL 	3

#define AVCC_VOLT 		5
#define INTERNAL_VOLT 	2.56 

//ADCs NUMBER
enum Enu_ADCNumber
{
	ADC_0 = 0
};

//ADC AUTO TRIGGER SIGNAL SOURCE 
enum Enu_ADCAutoTriggerSignalSource
{
	FREE_RUNNING_MODE 			= 0,
    ANALOG_COMPARATOR 			= 1,
    EXTERNAL_INTERRUPT_REQUEST 	= 2,
    TIMER_0_COMPARE_MATCH 		= 3,
    TIMER_0_OVERFLOW 			= 4,
    TIMER_1_COMPARE_MATCH 		= 5,
    TIMER_1_OVERFLOW 			= 6,
    TIMER_1_CAPTURE_EVENT 		= 7
};


//ADC PRESCALERS
enum Enu_ADCPrescalers
{
	ADC_PRESC_2   =	1,
	ADC_PRESC_4   =	2,
	ADC_PRESC_8   =	3,
	ADC_PRESC_16  =	4,
	ADC_PRESC_32  =	5,
	ADC_PRESC_64  =	6,
	ADC_PRESC_128 = 7
};

#endif