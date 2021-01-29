/*
 * File Name: PASSWORD.c
 * Creation Date: 01/26/2021
 * Author: Rehab
 * Description: C File for PASSWORD Service....
 */ 
 
#include "PASSWORD.h"

uint8 EnteredPassword[10]={0};
static uint8 EnteredDigitsCounter=0;

uint8 EnterPassword(uint8 PasswordDigitsNumber,uint8 Key)
{
	
	if(EnteredDigitsCounter==PasswordDigitsNumber)
	{
		if(Key==Keypad[3][3])
		{
			EnteredDigitsCounter=0;
			return CORRECT_LENGTH;
		}
		else
		{
			EnteredDigitsCounter=0;
			return LONG_LENGTH;
		}
	}
	else
	{
		if(Key==Keypad[3][3])
		{
			EnteredDigitsCounter=0;			
			return SHORT_LENGTH;
		}
		else
		{
			EnteredPassword[EnteredDigitsCounter]=Key-48;
			EnteredDigitsCounter++;
			if(EnteredDigitsCounter==PasswordDigitsNumber)
			{
				return CORRECT_LENGTH;
			}
			else
			{
				return SHORT_LENGTH;
			}
		}			

	}
}

void SetPassword(uint16 EEPROMAddress,uint8 PasswordDigitsNumber)
{
	for(uint8 i=0;i<PasswordDigitsNumber;i++)
	{
		EEPROMWriteData(EEPROMAddress+i,EnteredPassword[i]);
	}
}

uint8 CheckPassword(uint16 EEPROMAddress,uint8 PasswordDigitsNumber)
{
	for(uint8 i=0;i<PasswordDigitsNumber;i++)
	{
		if(EEPROMReadData(EEPROMAddress+i)!=EnteredPassword[i])
		{
			return WRONG_PASSWORD;
		}
	}
	return CORRECT_PASSWORD;
}

static void ClearEnteredPasswordArray(uint8 PasswordDigitsNumber)
{
	for(uint8 i=0;i<PasswordDigitsNumber;i++)
	{
		EnteredPassword[i]=0;
	}
}

void ClearEnteredDigitsCounter(void)
{
	EnteredDigitsCounter=0;
}