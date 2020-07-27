/*
 * File Name: GPIO.h
 * Creation Date: 07/20/2020
 * Author: Rehab
 * Description: Header File for GPIO peripheral....
 */ 

#ifndef GPIO_H_
#define GPIO_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"

//PORTS NAME
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//GENERAL MACROS
#define INPUT 0
#define OUTPUT 1

#define BIT_INPUT 0
#define LOWER_NIBBLE_INPUT 0
#define HIGHER_NIBBLE_INPUT 0
#define PORT_INPUT 0

#define BIT_OUTPUT 1
#define LOWER_NIBBLE_OUTPUT 15
#define HIGHER_NIBBLE_OUTPUT 15
#define PORT_OUTPUT 255

//FUNCTIONS PROTOTYPES
void GpioPortDirection(uint8 Port , uint8 Dir );
void GpioPortWrite(uint8 Port , uint8 Val );
void GpioPortToggle(uint8 Port);
uint8 GpioPortRead(uint8 Port);

void GpioPinDirection(uint8 Port , uint8 PinNo ,uint8 Dir);
void GpioPinWrite(uint8 Port , uint8 PinNo ,uint8 Val);
void GpioPinToggle(uint8 Port,uint8 PinNo);
uint8 GpioPinRead(uint8 Port,uint8 PinNo);

void GpioHigherNibbleDirection(uint8 Port , uint8 Dir );
void GpioHigherNibbleWrite(uint8 Port , uint8 Val );
void GpioHigherNibbleToggle(uint8 Port);
uint8 GpioHigherNibbleRead(uint8 Port);

void GpioLowerNibbleDirection(uint8 Port , uint8 Dir );
void GpioLowerNibbleWrite(uint8 Port , uint8 Val );
void GpioLowerNibbleToggle(uint8 Port);
uint8 GpioLowerNibbleRead(uint8 Port);

#endif