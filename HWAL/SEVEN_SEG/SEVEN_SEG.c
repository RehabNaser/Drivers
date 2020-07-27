/*
 * File Name: SEVEN_SEG.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for 7-segments...
 */ 

#include "SEVEN_SEG.h"

void SevenSegBCDInit(uint8 WhichSeg)
{
	#if SEVENSEG_DATA_PINS == HIGHER_NIBBLE
		GpioHigherNibbleDirection(SEVENSEG_PORT,OUTPUT);
	#elif SEVENSEG_DATA_PINS == LOWER_NIBBLE
		GpioLowerNibbleDirection(SEVENSEG_PORT,OUTPUT);
	#endif		
	switch(WhichSeg)
	{
		case SEG1:
			GpioPinDirection(SEVENSEG_PORT,SEVENSEG_EN1,OUTPUT);
			break;
		case SEG2:
			GpioPinDirection(SEVENSEG_PORT,SEVENSEG_EN2,OUTPUT);
			break;
		case BOTH:
			GpioPinDirection(SEVENSEG_PORT,SEVENSEG_EN1,OUTPUT);
			GpioPinDirection(SEVENSEG_PORT,SEVENSEG_EN2,OUTPUT);
			break;
		default:
			break;
	}
}

void SevenSegBCDWrite(uint8 WhichSeg , uint8 Number)
{
	#if SEVENSEG_DATA_PINS == HIGHER_NIBBLE
		GpioHigherNibbleWrite(SEVENSEG_PORT,Number);
	#elif SEVENSEG_DATA_PINS == LOWER_NIBBLE
		GpioLowerNibbleWrite(SEVENSEG_PORT,Number);
	#endif	
	switch(WhichSeg)
	{
		case SEG1:
			GpioPinWrite(SEVENSEG_PORT,SEVENSEG_EN1,HIGH);
			GpioPinWrite(SEVENSEG_PORT,SEVENSEG_EN2,LOW);
			break;
		case SEG2:
			GpioPinWrite(SEVENSEG_PORT,SEVENSEG_EN2,HIGH);
			GpioPinWrite(SEVENSEG_PORT,SEVENSEG_EN1,LOW);
			break;
		case BOTH:
			GpioPinWrite(SEVENSEG_PORT,SEVENSEG_EN1,HIGH);	
			GpioPinWrite(SEVENSEG_PORT,SEVENSEG_EN2,HIGH);					
			break;
		default:
			break;		
	}
}