/*
 * File Name: SPI.h
 * Creation Date: 02/08/2021
 * Author: Rehab
 * Description: Header File for SPI peripheral....
 */ 
 
#ifndef SPI_H_
#define SPI_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "INTERRUPT.h"
#include "GPIO.h"

//SPI PORT
#define SPI_PORT PORT_B

//SPI PINS
#define SS_PIN PIN4
#define MOSI_PIN PIN5
#define MISO_PIN PIN6
#define SCK_PIN PIN7

//SPI MODES
#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

//SPI SPEED MODE
#define SPI_SINGLE_SPEED 0
#define SPI_DOUBLE_SPEED 1

//SPI MASTER CLK FREQUENCY SINGLE SPEED
#define SPI_PRESC_4S 0
#define SPI_PRESC_16S 1
#define SPI_PRESC_64S 2
#define SPI_PRESC_128S 3

//SPI MASTER CLK FREQUENCY DOUBLE SPEED
#define SPI_PRESC_2D 0
#define SPI_PRESC_8D 1
#define SPI_PRESC_32D 2
#define SPI_PRESC_64D 3

//SPI DATA ORDER
#define MSB_FIRST 0
#define LSB_FIRST 1

//SPI MASTER/SLAVE SELECTOR
#define SPI_SLAVE 0
#define SPI_MASTER 1

//FUNCTIONS PROTOTYPES
void SPIEnable(void);
void SPIDisable(void);

void SPIMasterInit(uint8 SPIMode,uint8 DataOrder,uint8 SpeedMode,uint8 CLKFrequency);
void SPISlaveInit(uint8 SPIMode,uint8 DataOrder);

void SPITX(uint8 Data);
uint8 SPIRX(void);
uint8 SPITXRX(uint8 Data);

void SPIInterruptInit(void);
void SPIInterruptEnable(void);
void SPIInterruptDisable(void);

#endif