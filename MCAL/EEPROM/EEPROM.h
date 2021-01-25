/*
 * File Name: EEPROM.h
 * Creation Date: 01/22/2021
 * Author: Rehab
 * Description: Header File for EEPROM peripheral....
 */ 
 
#ifndef EEPROM_H_
#define EEPROM_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "INTERRUPT.h"

//FUNCTIONS PROTOTYPES
void EEPROMWriteData(uint16 Address,uint8 Data);
uint8 EEPROMReadData(uint16 Address);

void EEPROMInterruptInit(void);
void EEPROMInterruptEnable(void);
void EEPROMInterruptDisable(void);

#endif