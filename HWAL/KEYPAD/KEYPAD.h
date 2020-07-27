/*
 * File Name: KEYPAD.h
 * Creation Date: 07/24/2020
 * Author: Rehab
 * Description: Header File for keypad..
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "KEYPAD_CONFIG.h"

//FUNCTIONS PROTOTYPES
void KeypadInit(void);
uint8 KeypadReadKey(void);
static uint8 KeypadWhichRow(uint8 RowsVal);
uint8 KeypadMustPressed(void);

#endif