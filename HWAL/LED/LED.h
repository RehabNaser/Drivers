/*
 * File Name: LED.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for LEDs...
 */ 

#ifndef LED_H_
#define LED_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "LED_CONFIG.h"

//FUNCTIONS PROTOTYPES
void LedInit(uint8 LEDPinNo);
void LedOn(uint8 LEDPinNo);
void LedOff(uint8 LEDPinNo);
void LedToggle(uint8 LEDPinNo);
void LedBlink(uint8 LEDPinNo , uint32 DelayTimeInmsec);
void LedBlinkWithOnOffTime(uint8 LEDPinNo , uint32 OnTimeInmsec , uint32 OffTimeInmsec);

void LedsInit(uint8 StartLEDPinNo , uint8 LEDsNo);
void LedsOn(uint8 StartLEDPinNo , uint8 LEDsNo);
void LedsOff(uint8 StartLEDPinNo , uint8 LEDsNo);
void LedsToggle(uint8 StartLEDPinNo , uint8 LEDsNo);
void LedsBlink(uint8 StartLEDPinNo , uint8 LEDsNo , uint32 DelayTimeInmsec);

#endif