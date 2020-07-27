/*
 * File Name: BUZZER.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for buzzer...
 */ 

#ifndef BUZZER_H_
#define BUZZER_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "BUZZER_CONFIG.h"

//FUNCTIONS PROTOTYPES
void BuzzerInit(uint8 BuzzerPinNo);
void BuzzerOn(uint8 BuzzerPinNo);
void BuzzerOff(uint8 BuzzerPinNo);
void BuzzerToggle(uint8 BuzzerPinNo);
void BuzzerBlink(uint8 BuzzerPinNo , uint32 DelayTimeInmsec);
void BuzzerBlinkWithOnOffTime(uint8 BuzzerPinNo , uint32 OnTimeInmsec , uint32 OffTimeInmsec);

#endif