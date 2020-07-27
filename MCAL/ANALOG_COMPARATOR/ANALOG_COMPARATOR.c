/*
 * File Name: ANALOG_COMPARATOR.c
 * Creation Date: 07/26/2020
 * Author: Rehab
 * Description: C File for analog comparator peripheral....
 */ 
 
 #include "ANALOG_COMPARATOR.h"
 
void AnalogComparatorInit(uint8 PostiveInput,uint8 NegativeInput)
{
	AnalogComparatorSelectPostiveInput(PostiveInput);
	AnalogComparatorSelectNegativeInput(NegativeInput);
	AnalogComparatorEnable();
}

void AnalogComparatorEnable(void)
{
	BIT_WRITE(ACS_R,ACD,BIT_LOW);
}

void AnalogComparatorDisable(void)
{
	BIT_WRITE(ACS_R,ACD,BIT_HIGH);
}

void AnalogComparatorSelectPostiveInput(uint8 PostiveInput)
{
	switch(PostiveInput)
	{
		case POSTIVE_ANALOGCOMP_INPUT:
			GpioPinDirection(ANALOG_COMPARATOR_PORT,AIN0,INPUT);
			BIT_WRITE(ACS_R,ACBG,BIT_LOW);
			break;
		case BANDGAP_REFERENCE:
			BIT_WRITE(ACS_R,ACBG,BIT_HIGH);
			break;
		default:
			break;			
	}
}

void AnalogComparatorSelectNegativeInput(uint8 NegativeInput)
{
	switch(NegativeInput)
	{
		case NEGATIVE_ANALOGCOMP_INPUT:
			GpioPinDirection(ANALOG_COMPARATOR_PORT,AIN1,INPUT);
			BIT_WRITE(SF_IOR,ACME,BIT_LOW);
			break;
		case ADC_INPUT_0:
			ADCSelectPin(ADC0);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;
		case ADC_INPUT_1:
			ADCSelectPin(ADC1);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;
		case ADC_INPUT_2:
			ADCSelectPin(ADC2);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;
		case ADC_INPUT_3:
			ADCSelectPin(ADC3);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;
		case ADC_INPUT_4:
			ADCSelectPin(ADC4);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;
		case ADC_INPUT_5:
			ADCSelectPin(ADC5);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;
		case ADC_INPUT_6:
			ADCSelectPin(ADC6);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;	
		case ADC_INPUT_7:
			ADCSelectPin(ADC7);
			BIT_WRITE(SF_IOR,ACME,BIT_HIGH);
			ADCDisable();
			break;				
		default:
			break;			
	}	
}

uint8 AnalogComparatorReadOutput(void)
{
	if(BIT_GET(ACS_R,ACO))
		return 1;
	else
		return 0;
}

void AnalogComparatorInterruptInit(uint8 AnalogComparatorIntMode)
{
	AnalogComparatorInterruptMode(AnalogComparatorIntMode);
	AnalogComparatorInterruptEnable();
	GlobalInterruptEnable();
}

void AnalogComparatorInterruptEnable(void)
{
	BIT_WRITE(ACS_R,ACIE,BIT_HIGH);
}

void AnalogComparatorInterruptDisable(void)
{
	BIT_WRITE(ACS_R,ACIE,BIT_LOW);
}

void AnalogComparatorInterruptMode(uint8 AnalogComparatorIntMode)
{
	switch(AnalogComparatorIntMode)
	{
		case OUTPUT_TOGGLE:
			TWO_BITS_WRITE(ACS_R,ACIS0,OUTPUT_TOGGLE);
			break;
		case OUTPUT_FALLING_EDGE:
			TWO_BITS_WRITE(ACS_R,ACIS0,OUTPUT_FALLING_EDGE);
			break;	
		case OUTPUT_RISING_EDGE:
			TWO_BITS_WRITE(ACS_R,ACIS0,OUTPUT_RISING_EDGE);
			break;	
		default:
			break;			
	}
}