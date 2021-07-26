/*
 * File Name: SPI_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for SPI Configuration ...
 */ 
 
#ifndef __SPI_CONFIG__
#define __SPI_CONFIG__

#define SPI_NUMBERS (1)

#define SPI0 1
#if  SPI0
	#define SPI0_PORT		(PORT_B)
	#define SPI0_MOSI_PIN 	(PIN5)
	#define SPI0_MISO_PIN 	(PIN6)
	#define SPI0_SCK_PIN 	(PIN7)
	
	#define SPI0_MASTER_SLAVE_SELECTOR	(SPI_SLAVE)
	#define SPI0_DATA_ORDER				(MSB_FIRST)
	#define SPI0_MODE 					(SPI_MODE_0)
	
	#if SPI0_MASTER_SLAVE_SELECTOR == SPI_SLAVE
			#define SLAVE_NAME			(0)
	#endif
	
	#if SPI0_MASTER_SLAVE_SELECTOR == SPI_MASTER
		#define SPI0_SPEED_MODE 		(SPI_SINGLE_SPEED)
		#define SPI0_CLK_FREQUENCY 		(SPI_PRESC_64S)
		
		#define SPI0_SLAVES_NUMBER      (3)
		#define SLAVE_0					(0)
		#define SLAVE_1					(1)
		#define SLAVE_2					(2)
	#endif
	
#endif

//SPI MASTER/SLAVE SELECTOR
#define	SPI_SLAVE  0
#define SPI_MASTER 1

//SPIs NUMBER
enum Enu_SPINumber
{
	SPI_0 = 0
};

//SPI MODES
enum Enu_SPIMode
{
	SPI_MODE_0 = 0,
	SPI_MODE_1 = 1,
	SPI_MODE_2 = 2,
	SPI_MODE_3 = 3
};

//SPI DATA ORDER
enum Enu_SPIDataOrder
{
	MSB_FIRST = 0,
    LSB_FIRST = 1
};

//SPI SPEED MODE
enum Enu_SPISpeedMode
{
	SPI_SINGLE_SPEED = 0,
    SPI_DOUBLE_SPEED = 1
};


//SPI MASTER CLK FREQUENCY SINGLE SPEED
enum Enu_SPISingleSpeedOptions
{
	SPI_PRESC_4S   = 0,
	SPI_PRESC_16S  = 1,
	SPI_PRESC_64S  = 2,
	SPI_PRESC_128S = 3
};

//SPI MASTER CLK FREQUENCY DOUBLE SPEED
enum Enu_SPIDoubleSpeedOptions
{
	SPI_PRESC_2D  = 0,
	SPI_PRESC_8D  = 1,
	SPI_PRESC_32D = 2,
	SPI_PRESC_64D = 3
};

#endif