/*
 * File Name: BUTTON.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for buttons...
 */ 

#include "BUTTON.h"

void ButtonInit(uint8 ButtonPinNo)
{
	GpioPinDirection(BUTTONS_PORT,ButtonPinNo,INPUT);
	#if BUTTON_CONNECTION_MODE == PULLUP_SW
		GpioPinWrite(BUTTONS_PORT,ButtonPinNo,HIGH);
	#endif	
}

uint8 ButtonReadPress(uint8 ButtonPinNo)
{
	_delay_ms(20);
	if(GpioPinRead(BUTTONS_PORT,ButtonPinNo))
	{
		#if BUTTON_CONNECTION_MODE == PULLDOWN
			return PRESSED;
		#else
			return NO_PRESSED;
		#endif
	
	}
	else
	{
		#if BUTTON_CONNECTION_MODE == PULLDOWN
			return NO_PRESSED;
		#else
			return PRESSED;
		#endif		
	}
}

void ButtonStillPressed(uint8 ButtonPinNo)
{
	#if BUTTON_CONNECTION_MODE == PULLDOWN
		while(GpioPinRead(BUTTONS_PORT,ButtonPinNo));	
	#else
		while(!GpioPinRead(BUTTONS_PORT,ButtonPinNo));	
	#endif	
}