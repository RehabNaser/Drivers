/*
 * File Name: TIMER0.h
 * Creation Date: 01/23/2021
 * Author: Rehab
 * Description: Header File for TIMER0 peripheral....
 */ 
 
#ifndef TIMER0_H_
#define TIMER0_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "GPIO.h"
#include "INTERRUPT.h"

//TIMER0 PORTS
#define T0_PORT PORT_B
#define OC0_PORT PORT_B

//TIMER0 PINS
#define T0_PIN PIN0
#define OC0_PIN PIN3

//TIMER0 OPERATION MODES
#define TIMER0_NORMAL_MODE 0
#define TIMER0_PHASE_CORRECT_PWM_MODE 1
#define TIMER0_CTC_MODE 2
#define TIMER0_FAST_PWM_MODE 3

//COMPARE MATCH OUTPUT MODES(NON-PWM MODE)
#define DISCONNECT_OC0 0
#define TOGGLE_OC0 1
#define CLEAR_OC0 2
#define SET_OC0 3 

//COMPARE MATCH OUTPUT MODES(FAST/PHASE CORRECT PWM MODE)
#define NON_INVERTING_OC0_MODE 2
#define INVERTING_OC0_MODE 3 

//TIMER0 CLOCK SOURCE OPTIONS
#define TIMER0_NO_CLK 0
#define TIMER0_INTERNAL_CLK_NO_PRESC 1
#define TIMER0_INTERNAL_CLK_PRESC_8 2
#define TIMER0_INTERNAL_CLK_PRESC_64 3
#define TIMER0_INTERNAL_CLK_PRESC_256 4
#define TIMER0_INTERNAL_CLK_PRESC_1024 5
#define TIMER0_EXTERNAL_CLK_FALLING_EDGE 6
#define TIMER0_EXTERNAL_CLK_RISING_EDGE 7

//TIMER0 INTERRUPTS TYPES
#define TIMER0_COMPARE 0
#define TIMER0_OVERFLOW 1

//FUNCTIONS PROTOTYPES
void Timer0Init(uint8 Timer0OperationMode,uint8 Timer0ClkSource,uint8 Timer0CompareValue);
void Timer0SelectOperationMode(uint8 Timer0OperationMode,uint8 Timer0CompareValue);
void Timer0SelectClkSource(uint8 Timer0ClkSource);
void Timer0SelectCompareMatchOutputWaveMode(uint8 Timer0WaveGeneratedMode);
void Timer0SetCompareValue(uint8 Timer0CompareValue);

void Timer0Delay_ms(float32 Delay_ms,uint16 PrescalerValue);//Delay In msec,CTC Mode,Internal CLK
uint32 Timer0Delay_sec_CTC(float32 Delay_sec,uint8 Timer0CompareValue,uint16 PrescalerValue);//Delay In sec,CTC Mode,Internal CLK
uint32 Timer0Delay_sec_Normal(float32 Delay_sec,uint16 PrescalerValue);//Delay In sec,Normal Mode/Fast PWM Mode,Internal CLK

void Timer0SetOutputWaveFrequency_HZ(uint32 Frequency_HZ,uint16 PrescalerValue);//Frequency In HZ,CTC Mode,Internal CLK

void Timer0SetOutputWaveDutyCycle(uint8 DutyCycle);//Fast PWM Mode/Phase Correct PWM Mode,Non Inverting
void Timer0AnalogWrite(float32 VoltageValue);
uint8 Timer0ReturnDutyOfAnalogWrite(float32 VoltageValue);

uint8 Timer0CountExternalEvent(void);

void Timer0SetOutputWavePin(void);
void Timer0SetExternalClkPin(void);

void Timer0InterruptInit(uint8 Timer0IntType);
void Timer0InterruptEnable(uint8 Timer0IntType);
void Timer0InterruptDisable(uint8 Timer0IntType);

#endif