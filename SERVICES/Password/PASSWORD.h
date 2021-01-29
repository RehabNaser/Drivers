/*
 * File Name: PASSWORD.h
 * Creation Date: 01/26/2021
 * Author: Rehab
 * Description: Header File for PASSWORD Service ....
 */ 
 
 /*
 PASSWORD Driver manual:
  using Keypad and EEPROM Drivers.
  Maximum password length = 10 digits.
  Minimum password length = 1 digit. 
 */
 
#ifndef PASSWORD_H_
#define PASSWORD_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "KEYPAD.h"
#include "EEPROM.h"

//PASSWORD CORRECTION CHECKER MACROS
#define WRONG_PASSWORD 0
#define CORRECT_PASSWORD 1

//PASSWORD LENGTH CHECKER MACROS
#define SHORT_LENGTH 0 
#define CORRECT_LENGTH 1
#define LONG_LENGTH 2  

extern uint8 Keypad[4][4];

//FUNCTIONS PROTOTYPES
uint8 EnterPassword(uint8 PasswordDigitsNumber,uint8 Key);
void SetPassword(uint16 EEPROMAddress,uint8 PasswordDigitsNumber);
uint8 CheckPassword(uint16 EEPROMAddress,uint8 PasswordDigitsNumber);
static void ClearEnteredPasswordArray(uint8 PasswordDigitsNumber);
void ClearEnteredDigitsCounter(void);
#endif