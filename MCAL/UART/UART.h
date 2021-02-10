/*
 * File Name: UART.h
 * Creation Date: 02/02/2021
 * Author: Rehab
 * Description: Header File for UART peripheral....
 */ 
 
#ifndef UART_H_
#define UART_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "INTERRUPT.h"

//UART INTERRUPTS TYPES
#define RX_COMPLETE 0
#define TX_COMPLETE  1
#define DATA_REGISTER_EMPTY 2

//UART ASYNC. SPEED TYPES
#define UART_SINGLE_SPEED 0
#define UART_DOUBLE_SPEED 1

//UART DATA SIZE
#define FIVE_BITS 0
#define SIX_BITS 1
#define SEVEN_BITS 2
#define EIGHT_BITS 3
#define NINE_BITS 7

//UART STOP BITS SIZE
#define ONE_STOP_BIT 0
#define TWO_STOP_BIT 1

//UART PARITY MODES
#define NO_PARITY 0
#define EVEN_PARITY 2
#define ODD_PARITY 3

//USART MODES
#define ASYNCHRONOUS 0
#define SYNCHRONOUS 1

//FUNCTIONS PROTOTYPES
void UARTInit(uint32 BaudRate);
void UARTCustomInit(uint32 BaudRate,uint8 AsyncSpeedMode,uint8 DataSize,uint8 UARTParityMode,uint8 UARTStopBitSize);

void UARTEnableTX(void);
void UARTEnableRX(void);
void UARTDisableTX(void);
void UARTDisableRX(void);

void UARTSetParityBit(uint8 UARTParityMode);
void UARTSetStopBitSize(uint8 UARTStopBitSize);
void UARTSetDataSize(uint8 DataSize);
void UARTSetBaudRate(uint32 BaudRate,uint8 AsyncSpeedMode);

void UARTTransmit(uint8 Data);
void UARTTransmitString(uint8 *Data);
void UARTTransmit9Bits(uint16 Data);//Data values from 0 to 511
uint8 UARTAvailable(void);
uint8 UARTReceive(void);
uint16 UARTReceive9Bits(void);

void UARTInterruptInit(uint8 UARTIntType);
void UARTInterruptEnable(uint8 UARTIntType);
void UARTInterruptDisable(uint8 UARTIntType);

#endif