/*
 * File Name: LM35_TEMP_SENSOR.c
 * Creation Date: 01/25/2021
 * Author: Rehab
 * Description: C File for LM35 Temperature Sensor...
 */ 

#include "LM35_TEMP_SENSOR.h"

void LM35TempSensorRead(uint8 LM35SensorPinNo)
{
	ADCSingleConversionStartPin(LM35SensorPinNo);
}

//LM35 is 10mv --> 1c
uint8 LM35TempSensorCalculateTemp(uint8 ADCRefVol)
{
	uint8 Temperature;
	uint16 ADC_DigitalData;
	float32 ADC_AnalogData;
	ADC_DigitalData=ADCData();
	ADC_AnalogData=ConvertReadingFromDigitalToAnalog(ADC_DigitalData,ADCRefVol);
	Temperature=(uint8)(ADC_AnalogData/0.01);
	return Temperature;
}