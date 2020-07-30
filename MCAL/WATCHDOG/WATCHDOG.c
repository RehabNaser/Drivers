/*
 * File Name: WATCHDOG.c
 * Creation Date: 07/29/2020
 * Author: Rehab
 * Description: C File for watchdog timer peripheral....
 */ 
 
 #include "WATCHDOG.h"
 
void WatchdogTimerOn(uint8 WatchdogPreScaler)
{
	switch(WatchdogPreScaler)
	{
		case WD_PRESC_16K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_16K);
			break;
		case WD_PRESC_32K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_32K);
			break;
		case WD_PRESC_64K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_64K);
			break;
		case WD_PRESC_128K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_128K);
			break;
		case WD_PRESC_256K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_256K);
			break;
		case WD_PRESC_512K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_512K);
			break;
		case WD_PRESC_1024K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_1024K);
			break;
		case WD_PRESC_2048K:
			THREE_BITS_WRITE(WDTC_R,WDP0,WD_PRESC_2048K);
			break;			
		default:
			break;			
	}
	BIT_WRITE(WDTC_R,WDE,BIT_HIGH);
}

void WatchdogTimerOff()
{
	TWO_BITS_WRITE(WDTC_R,WDE,TWO_BITS_HIGH);
	BIT_WRITE(WDTC_R,WDE,BIT_LOW);
}