/*
 * File Name: BUZZER.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for buzzer...
 */ 

#include "BUZZER.h"

void BuzzerInit(uint8 BuzzerPinNo)
{
	GpioPinDirection(BUZZER_PORT,BuzzerPinNo,OUTPUT);
}

void BuzzerOn(uint8 BuzzerPinNo)
{
	GpioPinWrite(BUZZER_PORT,BuzzerPinNo,HIGH);
}

void BuzzerOff(uint8 BuzzerPinNo)
{
	GpioPinWrite(BUZZER_PORT,BuzzerPinNo,LOW);
}

void BuzzerToggle(uint8 BuzzerPinNo)
{
	GpioPinToggle(BUZZER_PORT,BuzzerPinNo);
}

void BuzzerBlink(uint8 BuzzerPinNo , uint32 DelayTimeInmsec)
{
	uint32 i;
	BuzzerOn(BuzzerPinNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);
	BuzzerOff(BuzzerPinNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);	
}

void BuzzerBlinkWithOnOffTime(uint8 BuzzerPinNo , uint32 OnTimeInmsec , uint32 OffTimeInmsec)
{
	uint32 i;
	BuzzerOn(BuzzerPinNo);
	for(i=0;i<OnTimeInmsec;i++)
		_delay_ms(1);
	BuzzerOff(BuzzerPinNo);
	for(i=0;i<OffTimeInmsec;i++)
		_delay_ms(1);	
}