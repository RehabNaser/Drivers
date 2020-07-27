/*
 * File Name: BUTTON.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for buttons...
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "BUTTON_CONFIG.h"

//BUTTON STATE
#define NO_PRESSED 0
#define PRESSED 1

//FUNCTIONS PROTOTYPES
void ButtonInit(uint8 ButtonPinNo);
uint8 ButtonReadPress(uint8 ButtonPinNo);
void ButtonStillPressed(uint8 ButtonPinNo);

#endif