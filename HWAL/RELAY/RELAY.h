/*
 * File Name: RELAY.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for relay...
 */ 

#ifndef RELAY_H_
#define RELAY_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "RELAY_CONFIG.h"

//FUNCTIONS PROTOTYPES
void RelayInit(uint8 RelayPinNo);
void RelayOn(uint8 RelayPinNo);
void RelayOff(uint8 RelayPinNo);
void RelayToggle(uint8 RelayPinNo);
void RelayBlink(uint8 RelayPinNo , uint32 DelayTimeInmsec);
void RelayBlinkWithOnOffTime(uint8 RelayPinNo , uint32 OnTimeInmsec , uint32 OffTimeInmsec);

#endif