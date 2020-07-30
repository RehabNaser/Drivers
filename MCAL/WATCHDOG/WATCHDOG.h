/*
 * File Name: WATCHDOG.h
 * Creation Date: 07/29/2020
 * Author: Rehab
 * Description: Header File for watchdog timer peripheral....
 */ 
 
#ifndef WATCHDOG_H_
#define WATCHDOG_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"

//WATCHDOG TIMER PRESCALERS
#define WD_PRESC_16K 0
#define WD_PRESC_32K 1
#define WD_PRESC_64K 2
#define WD_PRESC_128K 3
#define WD_PRESC_256K 4
#define WD_PRESC_512K 5
#define WD_PRESC_1024K 6
#define WD_PRESC_2048K 7

//FUNCTIONS PROTOTYPES
void WatchdogTimerOn(uint8 WatchdogPreScaler);
void WatchdogTimerOff();

#endif