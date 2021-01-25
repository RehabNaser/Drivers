/*
 * File Name: ADC.h
 * Creation Date: 07/21/2020
 * Author: Rehab
 * Description: Header File for ADC peripheral....
 */ 

#ifndef ADC_H_
#define ADC_H_

#define ADC_PORT PORT_A

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "GPIO.h"
#include "INTERRUPT.h"

//ADC REFERENCE VOLTAGES 
#define AREF 0
#define AVCC 1
#define INTERNAL 3

#define AREF_VOLT 0 
#define AVCC_VOLT 5
#define INTERNAL_VOLT 2.56

//ADC PRESCALERS
#define ADC_PRESC_2 1
#define ADC_PRESC_4 2
#define ADC_PRESC_8 3
#define ADC_PRESC_16 4
#define ADC_PRESC_32 5
#define ADC_PRESC_64 6
#define ADC_PRESC_128 7

//ADC ANALOG PINS
#define ADC0 PIN0
#define ADC1 PIN1
#define ADC2 PIN2
#define ADC3 PIN3
#define ADC4 PIN4
#define ADC5 PIN5
#define ADC6 PIN6
#define ADC7 PIN7

//ADC AUTO TRIGGER SIGNAL SOURCE 
#define FREE_RUNNING_MODE 0
#define ANALOG_COMPARATOR 1
#define EXTERNAL_INTERRUPT_REQUEST 2
#define TIMER_0_COMPARE_MATCH 3
#define TIMER_0_OVERFLOW 4
#define TIMER_1_COMPARE_MATCH 5
#define TIMER_1_OVERFLOW 6
#define TIMER_1_CAPTURE_EVENT 7

//FUNCTIONS PROTOTYPES
void ADCInit(void);
void ADCCustomInitSingleConversionMode(uint8 ADCPreScaler,uint8 ADCAnalogPin,uint8 ADCRefVol);
void ADCCustomInitAutoTriggerConversionMode(uint8 ADCAnalogPin,uint8 ADCPreScaler,uint8 ADCRefVol,uint8 ADCAutoTriggerSource);

void ADCEnable(void);
void ADCDisable(void);

void ADCSelectPrescaler(uint8 ADCPreScaler);
void ADCSelectPin(uint8 ADCAnalogPin);
void ADCSelectVref(uint8 ADCRefVol);
void ADCAutoTriggerConversionEnable(uint8 ADCAutoTriggerSource);
void ADCAutoTriggerConversionDisable(void);

void ADCSingleConversionStart(void);
void ADCFreeRunningModeConversionStart(void);

void ADCSingleConversionStartPin(uint8 ADCAnalogPin);

uint16 ADCData(void);
uint16 ADCSingleConversionRead(void);//
uint16 ADCAutoTriggerConversionRead(void);
uint16 ADCFreeRunningModeConversionRead(void);

uint16 ADCSingleConversionReadPin(uint8 ADCAnalogPin);
uint16 ADCAutoTriggerConversionReadPin(uint8 ADCAnalogPin);
uint16 ADCFreeRunningModeConversionReadPin(uint8 ADCAnalogPin);

float32 ConvertReadingFromDigitalToAnalog(uint16 ADC_DigitalData,uint8 ADCRefVol);
float32 ADCSingleConversionConvertReadingFromDigitalToAnalogAvcc(void);//
float32 ADCAutoTriggerConversionConvertReadingFromDigitalToAnalogAvcc(void);
float32 ADCFreeRunningModeConversionConvertReadingFromDigitalToAnalogAvcc(void);

float32 ADCSingleConversionConvertReadingFromDigitalToAnalog(uint8 ADCRefVol);
float32 ADCAutoTriggerConversionConvertReadingFromDigitalToAnalog(uint8 ADCRefVol);
float32 ADCFreeRunningModeConversionConvertReadingFromDigitalToAnalog(uint8 ADCRefVol);

float32 ADCSingleConversionConvertReadingPinFromDigitalToAnalogAvcc(uint8 ADCAnalogPin);
float32 ADCAutoTriggerConversionConvertReadingPinFromDigitalToAnalogAvcc(uint8 ADCAnalogPin);
float32 ADCFreeRunningModeConversionConvertReadingPinFromDigitalToAnalogAvcc(uint8 ADCAnalogPin);

float32 ADCSingleConversionConvertReadingPinFromDigitalToAnalog(uint8 ADCAnalogPin,uint8 ADCRefVol);
float32 ADCAutoTriggerConversionConvertReadingPinFromDigitalToAnalog(uint8 ADCAnalogPin,uint8 ADCRefVol);
float32 ADCFreeRunningModeConversionConvertReadingPinFromDigitalToAnalog(uint8 ADCAnalogPin,uint8 ADCRefVol);

void ADCInterruptInit(void);
void ADCInterruptEnable(void);
void ADCInterruptDisable(void);

#endif