/*
 * File Name: INTERRUPT.h
 * Creation Date: 07/22/2020
 * Author: Rehab
 * Description: Header File for INTERRUPT peripheral....
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "GPIO.h"

//INTERRUPTS TYPES
#define INT_INT0 0
#define INT_INT1 1
#define INT_INT2 2
#define INT_TIMER2_COMP 3
#define INT_TIMER2_OVF 4
#define INT_TIMER1_CAPT 5
#define INT_TIMER1_COMPA 6
#define INT_TIMER1_COMPB 7
#define INT_TIMER1_OVF 8
#define INT_TIMER0_COMP 9
#define INT_TIMER0_OVF 10
#define INT_SPI 11
#define INT_USART_RXC 12
#define INT_USART_UDRE 13
#define INT_USART_TXC 14
#define INT_ADC 15
#define INT_EERDY 16
#define INT_ANA_COMP 17
#define INT_TWI 18

//EXTERNAL INTERRUPTS NUMBERS
#define INTN0 0
#define INTN1 1
#define INTN2 2
//EXTERNAL INTERRUPTS PORTS
#define INT0_PORT PORT_D
#define INT1_PORT PORT_D
#define INT2_PORT PORT_B
//EXTERNAL INTERRUPTS PINS
#define INT0_PIN PIN2
#define INT1_PIN PIN3
#define INT2_PIN PIN2
//EXTERNAL INTERRUPTS MODES
#define LOW_LEVEL 0
#define LOGICAL_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3
//EXTERNAL INTERRUPTS PINS CONNECTION MODE
#define PULLDOWN 0
#define PULLUP_HW 1
#define PULLUP_SW 2

//TIMER NUMBERS
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
//TIMER0 & TIMER2 INTERRUPTS TYPES
#define COMPARE 0
#define OVERFLOW 1
//TIMER1 INTERRUPTS TYPES
#define CAPTURE 0
#define OVERFLOW 1
#define COMPARE_A 2
#define COMPARE_B 3

//USART INTERRUPTS TYPES
#define RX_COMPLETE 0
#define TX_COMPLETE  1
#define DATA_REGISTER_EMPTY 2

//FUNCTIONS PROTOTYPES
void GlobalInterruptEnable(void);
void GlobalInterruptDisable(void);

void ExternalInterruptInit(uint8 ExternalIntNum,uint8 ExternalIntMode,uint8 ExternalIntPinConnectionMode);
void ExternalInterruptEnable(uint8 ExternalIntNum);
void ExternalInterruptDisable(uint8 ExternalIntNum);
void ExternalInterruptMode(uint8 ExternalIntNum,uint8 ExternalIntMode);

void TimerInterruptInit(uint8 TimerNum,uint8 TimerIntType);
void TimerInterruptEnable(uint8 TimerNum,uint8 TimerIntType);
void TimerInterruptDisable(uint8 TimerNum,uint8 TimerIntType);

void SPIInterruptInit(void);
void SPIInterruptEnable(void);
void SPIInterruptDisable(void);

void TWIInterruptInit(void);
void TWIInterruptEnable(void);
void TWIInterruptDisable(void);

void EEPROMInterruptInit(void);
void EEPROMInterruptEnable(void);
void EEPROMInterruptDisable(void);

void USARTInterruptInit(uint8 USARTIntType);
void USARTInterruptEnable(uint8 USARTIntType);
void USARTInterruptDisable(uint8 USARTIntType);

#endif