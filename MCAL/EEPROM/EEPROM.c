/*
 * File Name: EEPROM.c
 * Creation Date: 01/22/2021
 * Author: Rehab
 * Description: C File for EEPROM peripheral....
 */ 
 
#include "EEPROM.h"

void EEPROMWriteData(uint16 Address,uint8 Data)
{
	while(BIT_GET(EEC_R,EEWE));
	REG_WRITE(EEA_R,Address);
	REG_WRITE(EED_R,Data);
	BIT_WRITE(EEC_R,EEMWE,BIT_HIGH);
	BIT_WRITE(EEC_R,EEWE,BIT_HIGH);
}

uint8 EEPROMReadData(uint16 Address)
{
	while(BIT_GET(EEC_R,EEWE));
	REG_WRITE(EEA_R,Address);
	BIT_WRITE(EEC_R,EERE,BIT_HIGH);
	return REG_GET(EED_R);	
}
 
void EEPROMInterruptInit(void)
{
	EEPROMInterruptEnable();
	GlobalInterruptEnable();
}

void EEPROMInterruptEnable(void)
{
	BIT_WRITE(EEC_R,EERIE,BIT_HIGH);	
}

void EEPROMInterruptDisable(void)
{
	BIT_WRITE(EEC_R,EERIE,BIT_LOW);	
}