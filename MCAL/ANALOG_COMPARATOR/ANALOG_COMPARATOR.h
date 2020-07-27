/*
 * File Name: ANALOG_COMPARATOR.h
 * Creation Date: 07/26/2020
 * Author: Rehab
 * Description: Header File for analog comparator peripheral....
 */ 

#ifndef ANALOG_COMPARATOR_H_
#define ANALOG_COMPARATOR_H_

#define ANALOG_COMPARATOR_PORT PORT_B

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "ADC.h"
#include "GPIO.h"
#include "INTERRUPT.h"

//ANALOG COMPARATOR PINS
#define AIN0 PIN2
#define AIN1 PIN3

//POSTIVE INPUT OPTIONS
#define POSTIVE_ANALOGCOMP_INPUT 0
#define BANDGAP_REFERENCE 1

//NEGATIVE INPUT OPTIONS
#define NEGATIVE_ANALOGCOMP_INPUT 0
#define ADC_INPUT_0 1
#define ADC_INPUT_1 2
#define ADC_INPUT_2 3
#define ADC_INPUT_3 4
#define ADC_INPUT_4 5
#define ADC_INPUT_5 6
#define ADC_INPUT_6 7
#define ADC_INPUT_7 8

//ANALOG COMPARATOR INTERRUPTS MODES
#define OUTPUT_TOGGLE 0
#define OUTPUT_FALLING_EDGE 2
#define OUTPUT_RISING_EDGE 3

//FUNCTIONS PROTOTYPES
void AnalogComparatorInit(uint8 PostiveInput,uint8 NegativeInput);

void AnalogComparatorEnable(void);
void AnalogComparatorDisable(void);

void AnalogComparatorSelectPostiveInput(uint8 PostiveInput);
void AnalogComparatorSelectNegativeInput(uint8 NegativeInput);

uint8 AnalogComparatorReadOutput(void);

void AnalogComparatorInterruptInit(uint8 AnalogComparatorIntMode);
void AnalogComparatorInterruptEnable(void);
void AnalogComparatorInterruptDisable(void);
void AnalogComparatorInterruptMode(uint8 AnalogComparatorIntMode);

#endif