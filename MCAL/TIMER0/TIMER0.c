/*
 * File Name: TIMER0.c
 * Creation Date: 01/23/2021
 * Author: Rehab
 * Description: C File for TIMER0 peripheral....
 */ 
 
#include "TIMER0.h"

void Timer0Init(uint8 Timer0OperationMode,uint8 Timer0ClkSource,uint8 Timer0CompareValue)
{
	Timer0SelectOperationMode(Timer0OperationMode,Timer0CompareValue);
	Timer0SelectClkSource(Timer0ClkSource);
}

void Timer0SelectOperationMode(uint8 Timer0OperationMode,uint8 Timer0CompareValue)
{
	switch(Timer0OperationMode)
	{
		case TIMER0_NORMAL_MODE:
			BIT_WRITE(TCCR_0,WGM00,BIT_LOW);
			BIT_WRITE(TCCR_0,WGM01,BIT_LOW);
			break;
		case TIMER0_PHASE_CORRECT_PWM_MODE:
			BIT_WRITE(TCCR_0,WGM00,BIT_HIGH);
			BIT_WRITE(TCCR_0,WGM01,BIT_LOW);		
			break;
		case TIMER0_CTC_MODE:
			BIT_WRITE(TCCR_0,WGM00,BIT_LOW);
			BIT_WRITE(TCCR_0,WGM01,BIT_HIGH);		
			break;
		case TIMER0_FAST_PWM_MODE:
			BIT_WRITE(TCCR_0,WGM00,BIT_HIGH);
			BIT_WRITE(TCCR_0,WGM01,BIT_HIGH);		
			break;
		default:
			break;
	}
	Timer0SetCompareValue(Timer0CompareValue);
}

void Timer0SelectClkSource(uint8 Timer0ClkSource)
{
	THREE_BITS_WRITE(TCCR_0,CS00,Timer0ClkSource);
}

void Timer0SelectCompareMatchOutputWaveMode(uint8 Timer0WaveGeneratedMode)
{
	TWO_BITS_WRITE(TCCR_0,COM00,Timer0WaveGeneratedMode);
}

void Timer0SetCompareValue(uint8 Timer0CompareValue)
{
	REG_WRITE(OCR_0,Timer0CompareValue);
}

//Delay In msec,CTC Mode,Internal CLK
//PrescalerValues (1,8,64,256,1024)
/*F_CPU = 10MHZ 
if PrescalerValue=1--> Available Delay rang is 0.0256ms(OCR0=255)-->0.0001ms(OCR0=0)
if PrescalerValue=8--> Available Delay rang is 0.2048ms(OCR0=255)-->0.0008ms(OCR0=0)
if PrescalerValue=64--> Available Delay rang is 1.6384ms(OCR0=255)-->0.0064ms(OCR0=0)
if PrescalerValue=256--> Available Delay rang is 6.5536ms(OCR0=255)-->0.0256ms(OCR0=0)
if PrescalerValue=1024--> Available Delay rang is 26.2144ms(OCR0=255)-->0.1024ms(OCR0=0)
*/ 
void Timer0Delay_ms(float32 Delay_ms,uint16 PrescalerValue)
{
	uint8 Timer0CompareValue;
	Timer0CompareValue=(uint8)((((Delay_ms/1000.0)*F_CPU)/PrescalerValue)-1);
	Timer0SetCompareValue(Timer0CompareValue);	
}

//Delay In sec,CTC Mode,Internal CLK
//Recommended using Timer0CompareValue=255,PrescalerValue=1024
uint32 Timer0Delay_sec_CTC(float32 Delay_sec,uint8 Timer0CompareValue,uint16 PrescalerValue)
{
	uint32 NumberOfCompareMatch;
	float32 TimeOfOneCompareMatch=((float32)(Timer0CompareValue+1)*PrescalerValue)/F_CPU;
	NumberOfCompareMatch=(uint32)(Delay_sec/TimeOfOneCompareMatch);
	return NumberOfCompareMatch;
}

//Delay In sec,Normal Mode/Fast PWM Mode,Internal CLK
//Recommended using PrescalerValue=1024
uint32 Timer0Delay_sec_Normal(float32 Delay_sec,uint16 PrescalerValue)
{
	uint32 NumberOfOverflow;
	float32 TimeOfOneOverflow=(256.0*PrescalerValue)/F_CPU;
	NumberOfOverflow=(uint32)(Delay_sec/TimeOfOneOverflow);
	return NumberOfOverflow;
}

//Frequency In HZ,CTC Mode,Internal CLK
//PrescalerValues (1,8,64,256,1024)
/*F_CPU = 10MHZ 
if PrescalerValue=1--> Available Freq rang is 19531.25Hz(OCR0=255)-->5000000Hz(OCR0=0)
if PrescalerValue=8--> Available Freq rang is 2441.40625Hz(OCR0=255)-->625000Hz(OCR0=0)
if PrescalerValue=64--> Available Freq rang is 305.17578125Hz(OCR0=255)-->78125Hz(OCR0=0)
if PrescalerValue=256--> Available Freq rang is 76.2939453125Hz(OCR0=255)-->19531.25Hz(OCR0=0)
if PrescalerValue=1024--> Available Freq rang is 19.073486328125Hz(OCR0=255)-->4882.8125Hz(OCR0=0)
*/ 
void Timer0SetOutputWaveFrequency_HZ(uint32 Frequency_HZ,uint16 PrescalerValue)
{
	uint8 Timer0CompareValue;
	Timer0CompareValue=(uint8)((F_CPU/(2.0*Frequency_HZ*PrescalerValue))-1);
	Timer0SetCompareValue(Timer0CompareValue);
}

//Fast PWM Mode/Phase Correct PWM Mode,Non Inverting
//DutyCycle Range from 1-->100
void Timer0SetOutputWaveDutyCycle(uint8 DutyCycle)
{
	uint8 Timer0CompareValue;
	Timer0CompareValue=(uint8)(((DutyCycle/100.0)*256.0)-1);
	Timer0SetCompareValue(Timer0CompareValue);	
}

void Timer0AnalogWrite(float32 VoltageValue)
{
	uint8 DutyCycle;
	DutyCycle=(uint8)((VoltageValue/5.0)*100);
	Timer0SetOutputWaveDutyCycle(DutyCycle);
}

uint8 Timer0ReturnDutyOfAnalogWrite(float32 VoltageValue)
{
	uint8 DutyCycle;
	DutyCycle=(uint8)((VoltageValue/5.0)*100);
	return DutyCycle;
}

uint8 Timer0CountExternalEvent(void)
{
	return REG_GET(TCNT_0);
}

void Timer0SetOutputWavePin(void)
{
	GpioPinDirection(OC0_PORT,OC0_PIN,OUTPUT);
	GpioPinWrite(OC0_PORT,OC0_PIN,LOW);	
}

void Timer0SetExternalClkPin(void)
{
	GpioPinDirection(T0_PORT,T0_PIN,INPUT);
}

void Timer0InterruptInit(uint8 Timer0IntType)
{
	Timer0InterruptEnable(Timer0IntType); 
	GlobalInterruptEnable();	
}

void Timer0InterruptEnable(uint8 Timer0IntType)
{
	switch(Timer0IntType)
	{
		case TIMER0_COMPARE:
			BIT_WRITE(TIMSK_R,OCIE0,BIT_HIGH);
			break;
		case TIMER0_OVERFLOW:
			BIT_WRITE(TIMSK_R,TOIE0,BIT_HIGH);
			break;
		default:
			break;
	}	
}

void Timer0InterruptDisable(uint8 Timer0IntType)
{
	switch(Timer0IntType)
	{
		case TIMER0_COMPARE:
			BIT_WRITE(TIMSK_R,OCIE0,BIT_LOW);
			break;
		case TIMER0_OVERFLOW:
			BIT_WRITE(TIMSK_R,TOIE0,BIT_LOW);
			break;
		default:
			break;
	}
}