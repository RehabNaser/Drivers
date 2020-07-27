/*
 * File Name: RELAY.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for relay...
 */ 

#include "RELAY.h"

void RelayInit(uint8 RelayPinNo)
{
	GpioPinDirection(RELAY_PORT,RelayPinNo,OUTPUT);
}

void RelayOn(uint8 RelayPinNo)
{
	GpioPinWrite(RELAY_PORT,RelayPinNo,HIGH);
}

void RelayOff(uint8 RelayPinNo)
{
	GpioPinWrite(RELAY_PORT,RelayPinNo,LOW);
}

void RelayToggle(uint8 RelayPinNo)
{
	GpioPinToggle(RELAY_PORT,RelayPinNo);
}

void RelayBlink(uint8 RelayPinNo , uint32 DelayTimeInmsec)
{
	uint32 i;
	RelayOn(RelayPinNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);
	RelayOff(RelayPinNo);
	for(i=0;i<DelayTimeInmsec;i++)
		_delay_ms(1);
}

void RelayBlinkWithOnOffTime(uint8 RelayPinNo , uint32 OnTimeInmsec , uint32 OffTimeInmsec)
{
	uint32 i;
	RelayOn(RelayPinNo);
	for(i=0;i<OnTimeInmsec;i++)
		_delay_ms(1);
	RelayOff(RelayPinNo);
	for(i=0;i<OffTimeInmsec;i++)
		_delay_ms(1);
}