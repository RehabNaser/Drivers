/*
 * File Name: ADC.c
 * Creation Date: 07/21/2020
 * Author: Rehab
 * Description: C File for ADC peripheral....
 */ 

#include "ADC.h"

void ADCInit(void)
{
	ADCSelectPin(ADC0);
	ADCSelectVref(AVCC);
	ADCSelectPrescaler(ADC_PRESC_64);
	ADCEnable();
}

void ADCCustomInitSingleConversionMode(uint8 ADCPreScaler,uint8 ADCAnalogPin,uint8 ADCRefVol)
{
	ADCSelectPin(ADCAnalogPin);
	ADCSelectVref(ADCRefVol);
	ADCSelectPrescaler(ADCPreScaler);
	ADCEnable();
}

void ADCCustomInitAutoTriggerConversionMode(uint8 ADCAnalogPin,uint8 ADCPreScaler,uint8 ADCRefVol,uint8 ADCAutoTriggerSource)
{
	ADCSelectPin(ADCAnalogPin);
	ADCSelectVref(ADCRefVol);
	ADCAutoTriggerConversionEnable(ADCAutoTriggerSource);
	ADCSelectPrescaler(ADCPreScaler);
	ADCEnable();	
}

void ADCEnable(void)
{
	BIT_WRITE(ADC_CSRA,ADEN,BIT_HIGH);	
}

void ADCDisable(void)
{
	BIT_WRITE(ADC_CSRA,ADEN,BIT_LOW);		
}

void ADCSelectPrescaler(uint8 ADCPreScaler)
{
	THREE_BITS_WRITE(ADC_CSRA,ADPS0,ADCPreScaler);	
}

void ADCSelectPin(uint8 ADCAnalogPin)
{
	GpioPinDirection(ADC_PORT,ADCAnalogPin,INPUT);
	FIVE_BITS_WRITE(ADC_MUX,MUX0,ADCAnalogPin);	
}

void ADCSelectVref(uint8 ADCRefVol)
{
	TWO_BITS_WRITE(ADC_MUX,REFS0,ADCRefVol);	
}

void ADCAutoTriggerConversionEnable(uint8 ADCAutoTriggerSource)
{
	BIT_WRITE(ADC_CSRA,ADATE,BIT_HIGH);
	THREE_BITS_WRITE(SF_IOR,ADTS0,ADCAutoTriggerSource);	
}

void ADCAutoTriggerConversionDisable(void)
{
	BIT_WRITE(ADC_CSRA,ADATE,BIT_LOW);	
}

void ADCSingleConversionStart(void)
{
	BIT_WRITE(ADC_CSRA,ADSC,BIT_HIGH); 	
}

void ADCFreeRunningModeConversionStart(void)
{
	ADCSingleConversionStart();	
}

void ADCSingleConversionStartPin(uint8 ADCAnalogPin)
{
	ADCSelectPin(ADCAnalogPin);
	ADCSingleConversionStart();
}

uint16 ADCData(void)
{
	return REG_GET(ADC);	
}

uint16 ADCSingleConversionRead(void)
{
	uint16 ADC_Data;
	ADCSingleConversionStart();
	while(BIT_GET(ADC_CSRA,ADSC));
	ADC_Data=ADCData();
	return ADC_Data;
}

uint16 ADCAutoTriggerConversionRead(void)
{
	uint16 ADC_Data;
	while(BIT_GET(ADC_CSRA,ADSC));
	ADC_Data=ADCData();
	return ADC_Data; 	
}

uint16 ADCFreeRunningModeConversionRead(void)
{
	uint16 ADC_Data;
	ADC_Data=ADCData();
	return ADC_Data;	
}

uint16 ADCSingleConversionReadPin(uint8 ADCAnalogPin)
{
	uint16 ADC_Data;
	ADCSelectPin(ADCAnalogPin);
	ADC_Data=ADCSingleConversionRead();	
	return ADC_Data;
}

uint16 ADCAutoTriggerConversionReadPin(uint8 ADCAnalogPin)
{
	uint16 ADC_Data;
	ADCSelectPin(ADCAnalogPin);
	ADC_Data=ADCAutoTriggerConversionRead();
	return ADC_Data; 	
}

uint16 ADCFreeRunningModeConversionReadPin(uint8 ADCAnalogPin)
{
	uint16 ADC_Data;
	ADCSelectPin(ADCAnalogPin);
	ADC_Data=ADCFreeRunningModeConversionRead();
	return ADC_Data;	
}

float32 ConvertReadingFromDigitalToAnalog(uint16 ADC_DigitalData,uint8 ADCRefVol)
{
	float32 ADC_AnalogData=0;
	switch(ADCRefVol)
	{
		case AVCC:
			ADC_AnalogData=ADC_DigitalData*(AVCC_VOLT/1024.0);
			break;
		case AREF:
			ADC_AnalogData=ADC_DigitalData*(AREF_VOLT/1024.0);
			break;
		case INTERNAL:
			ADC_AnalogData=ADC_DigitalData*(INTERNAL_VOLT/1024.0);
			break;
		default:
			break;
	} 
	return ADC_AnalogData;		
}

float32 ADCSingleConversionConvertReadingFromDigitalToAnalogAvcc(void)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCSingleConversionRead();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,AVCC);
	return ADC_AnalogData;	
}

float32 ADCAutoTriggerConversionConvertReadingFromDigitalToAnalogAvcc(void)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCAutoTriggerConversionRead();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,AVCC);
	return ADC_AnalogData;		
}

float32 ADCFreeRunningModeConversionConvertReadingFromDigitalToAnalogAvcc(void)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCFreeRunningModeConversionRead();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,AVCC);
	return ADC_AnalogData;	
}

float32 ADCSingleConversionConvertReadingFromDigitalToAnalog(uint8 ADCRefVol)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCSingleConversionRead();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	return ADC_AnalogData;
}

float32 ADCAutoTriggerConversionConvertReadingFromDigitalToAnalog(uint8 ADCRefVol)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCAutoTriggerConversionRead();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	return ADC_AnalogData;	
}

float32 ADCFreeRunningModeConversionConvertReadingFromDigitalToAnalog(uint8 ADCRefVol)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCFreeRunningModeConversionRead();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	return ADC_AnalogData;	
}

float32 ADCSingleConversionConvertReadingPinFromDigitalToAnalogAvcc(uint8 ADCAnalogPin)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCSingleConversionReadPin(ADCAnalogPin);
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,AVCC);
	return ADC_AnalogData;		
}

float32 ADCAutoTriggerConversionConvertReadingPinFromDigitalToAnalogAvcc(uint8 ADCAnalogPin)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCAutoTriggerConversionReadPin(ADCAnalogPin);
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,AVCC);
	return ADC_AnalogData;	
}

float32 ADCFreeRunningModeConversionConvertReadingPinFromDigitalToAnalogAvcc(uint8 ADCAnalogPin)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCFreeRunningModeConversionReadPin(ADCAnalogPin);
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,AVCC);
	return ADC_AnalogData;	
}

float32 ADCSingleConversionConvertReadingPinFromDigitalToAnalog(uint8 ADCAnalogPin,uint8 ADCRefVol)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCSingleConversionReadPin(ADCAnalogPin);
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	return ADC_AnalogData;
}

float32 ADCAutoTriggerConversionConvertReadingPinFromDigitalToAnalog(uint8 ADCAnalogPin,uint8 ADCRefVol)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCAutoTriggerConversionReadPin(ADCAnalogPin);
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	return ADC_AnalogData;		
}

float32 ADCFreeRunningModeConversionConvertReadingPinFromDigitalToAnalog(uint8 ADCAnalogPin,uint8 ADCRefVol)
{
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCFreeRunningModeConversionReadPin(ADCAnalogPin);
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	return ADC_AnalogData;		
}

void ADCInterruptInit(void)
{
	ADCInterruptEnable();
	GlobalInterruptEnable();	
}

void ADCInterruptEnable(void)
{
	BIT_WRITE(ADC_CSRA,ADIE,BIT_HIGH);	
}

void ADCInterruptDisable(void)
{
	BIT_WRITE(ADC_CSRA,ADIE,BIT_LOW);		
}