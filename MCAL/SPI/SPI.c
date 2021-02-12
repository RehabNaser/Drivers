/*
 * File Name: SPI.c
 * Creation Date: 02/08/2021
 * Author: Rehab
 * Description: C File for SPI peripheral....
 */ 
 
#include "SPI.h"

void SPIEnable(void)
{
	BIT_WRITE(SPC_R,SPE,BIT_HIGH);
}

void SPIDisable(void)
{
	BIT_WRITE(SPC_R,SPE,BIT_LOW);
}

void SPIMasterInit(uint8 SPIMode,uint8 DataOrder,uint8 SpeedMode,uint8 CLKFrequency)
{
	GpioPinDirection(SPI_PORT,MOSI_PIN,OUTPUT);
	GpioPinDirection(SPI_PORT,SCK_PIN,OUTPUT);
	GpioPinDirection(SPI_PORT,SS_PIN,OUTPUT);
	BIT_WRITE(SPC_R,DORD,DataOrder);
	BIT_WRITE(SPS_R,SPI2X,SpeedMode);
	TWO_BITS_WRITE(SPC_R,SPR0,CLKFrequency);
	TWO_BITS_WRITE(SPC_R,CPHA,SPIMode);
	BIT_WRITE(SPC_R,MSTR,SPI_MASTER);
	SPIEnable();
}

void SPISlaveInit(uint8 SPIMode,uint8 DataOrder)
{
	GpioPinDirection(SPI_PORT,MISO_PIN,OUTPUT);
	BIT_WRITE(SPC_R,DORD,DataOrder);
	TWO_BITS_WRITE(SPC_R,CPHA,SPIMode);
	BIT_WRITE(SPC_R,MSTR,SPI_SLAVE);
	SPIEnable();
}

void SPITX(uint8 Data)
{
	REG_WRITE(SPD_R,Data);
	while(!(BIT_GET(SPS_R,SPIF)));
}

uint8 SPIRX(void)
{
	while(!(BIT_GET(SPS_R,SPIF)));
	return REG_GET(SPD_R);
}

uint8 SPITXRX(uint8 Data)
{
	REG_WRITE(SPD_R,Data);
	while(!(BIT_GET(SPS_R,SPIF)));	
	return REG_GET(SPD_R);
}

void SPIInterruptInit(void)
{
	SPIInterruptEnable();
	GlobalInterruptEnable();
}

void SPIInterruptEnable(void)
{
	BIT_WRITE(SPC_R,SPIE,BIT_HIGH);	
}

void SPIInterruptDisable(void)
{
	BIT_WRITE(SPC_R,SPIE,BIT_LOW);	
}