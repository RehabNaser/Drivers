/*
 * File Name: LED.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for LEDs...
 */ 

#include "LED.h"

void LedInit(uint8 LEDPinNo)
{
	GpioPinDirection(LEDS_PORT,LEDPinNo,OUTPUT);		
}

void LedOn(uint8 LEDPinNo)
{
	GpioPinWrite(LEDS_PORT,LEDPinNo,HIGH);	
}

void LedOff(uint8 LEDPinNo)
{
	GpioPinWrite(LEDS_PORT,LEDPinNo,LOW);	
}

void LedToggle(uint8 LEDPinNo)
{
	GpioPinToggle(LEDS_PORT,LEDPinNo);	
}

void LedBlink(uint8 LEDPinNo , uint32 DelayTimeInmsec)
{
	uint32 i;
	LedOn(LEDPinNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);
	LedOff(LEDPinNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);	
}

void LedBlinkWithOnOffTime(uint8 LEDPinNo , uint32 OnTimeInmsec , uint32 OffTimeInmsec)
{
	uint32 i;
	LedOn(LEDPinNo);
	for(i=0;i<OnTimeInmsec;i++)
		_delay_ms(1);
	LedOff(LEDPinNo);
	for(i=0;i<OffTimeInmsec;i++)
		_delay_ms(1);	
}

void LedsInit(uint8 StartLEDPinNo , uint8 LEDsNo)
{
	uint8 x;
	for(x=StartLEDPinNo;x<LEDsNo+StartLEDPinNo;x++)
		GpioPinDirection(LEDS_PORT,x,OUTPUT);	
}

void LedsOn(uint8 StartLEDPinNo , uint8 LEDsNo)
{
	uint8 x;
	for(x=StartLEDPinNo;x<LEDsNo+StartLEDPinNo;x++)	
		GpioPinWrite(LEDS_PORT,x,HIGH);		
}

void LedsOff(uint8 StartLEDPinNo , uint8 LEDsNo)
{
	uint8 x;
	for(x=StartLEDPinNo;x<LEDsNo+StartLEDPinNo;x++)
		GpioPinWrite(LEDS_PORT,x,LOW);	
}

void LedsToggle(uint8 StartLEDPinNo , uint8 LEDsNo)
{
	uint8 x;
	for(x=StartLEDPinNo;x<LEDsNo+StartLEDPinNo;x++)
		GpioPinToggle(LEDS_PORT,x);	
}

void LedsBlink(uint8 StartLEDPinNo , uint8 LEDsNo , uint32 DelayTimeInmsec)
{
	uint32 i;
	LedsOn(StartLEDPinNo,LEDsNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);
	LedsOff(StartLEDPinNo,LEDsNo);	
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);	
	
}