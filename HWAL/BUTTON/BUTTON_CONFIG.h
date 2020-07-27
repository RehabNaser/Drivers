/*
 * File Name: BUTTON_CONFIG.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for buttons' connections...
 */ 
 
#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_

//FILES INCLUDING
#include "GPIO.h"

//BUTTONS CONNECTION
#define BUTTONS_PORT PORT_D
#define BUTTON0 PIN0
#define BUTTON1 PIN1
#define BUTTON2 PIN2

//KEYPAD CONNECTION MODE
#define BUTTON_CONNECTION_MODE PULLUP_SW
#define PULLDOWN 0
#define PULLUP_HW 1
#define PULLUP_SW 2

#endif