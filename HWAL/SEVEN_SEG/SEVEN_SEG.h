/*
 * File Name: SEVEN_SEG.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for 7-segments...
 */ 

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "SEVEN_SEG_CONFIG.h"

//WHICH 7-SEGMENTS
#define SEG1 0
#define SEG2 1
#define BOTH 2

//FUNCTIONS PROTOTYPES
void SevenSegBCDInit(uint8 WhichSeg);
void SevenSegBCDWrite(uint8 WhichSeg,uint8 Number);

#endif