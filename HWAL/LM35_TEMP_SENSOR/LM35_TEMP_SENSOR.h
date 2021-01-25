/*
 * File Name: LM35_TEMP_SENSOR.h
 * Creation Date: 01/25/2021
 * Author: Rehab
 * Description: Header File for LM35 Temperature Sensor...
 */ 

#ifndef LM35_TEMP_SENSOR_H_
#define LM35_TEMP_SENSOR_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "ADC.h"
#include "LM35_TEMP_SENSOR_CONFIG.h"

//FUNCTIONS PROTOTYPES
void LM35TempSensorRead(uint8 LM35SensorPinNo);
uint8 LM35TempSensorCalculateTemp(uint8 ADCRefVol);
#endif