/*
 * File Name: SEVEN_SEG_CONFIG.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for 7-segments connection...
 */ 
 
#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_

//FILES INCLUDING
#include "GPIO.h"

//7-SEGMENTS CONNECTION
#define SEVENSEG_PORT PORT_C
#define SEVENSEG_DATA_PINS HIGHER_NIBBLE
#define SEVENSEG_EN1 PIN2
#define SEVENSEG_EN2 PIN3

#endif