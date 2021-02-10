/*
 * File Name: UART.c
 * Creation Date: 02/02/2021
 * Author: Rehab
 * Description: C File for UART peripheral....
 */ 
 
#include "UART.h"

void UARTInit(uint32 BaudRate)
{
	UARTSetStopBitSize(ONE_STOP_BIT);
	UARTSetParityBit(NO_PARITY);
	UARTSetDataSize(EIGHT_BITS);
	UARTSetBaudRate(BaudRate,UART_SINGLE_SPEED);
	UARTEnableTX();
	UARTEnableRX();
}

void UARTCustomInit(uint32 BaudRate,uint8 AsyncSpeedMode,uint8 DataSize,uint8 UARTParityMode,uint8 UARTStopBitSize)
{
	UARTSetStopBitSize(UARTStopBitSize);
	UARTSetParityBit(UARTParityMode);
	UARTSetDataSize(DataSize);
	UARTSetBaudRate(BaudRate,AsyncSpeedMode);
	UARTEnableTX();
	UARTEnableRX();
}

void UARTEnableTX(void)
{
	BIT_WRITE(UCS_RB,TXEN,BIT_HIGH);
}

void UARTEnableRX(void)
{
	BIT_WRITE(UCS_RB,RXEN,BIT_HIGH);
}

void UARTDisableTX(void)
{
	BIT_WRITE(UCS_RB,TXEN,BIT_LOW);
}

void UARTDisableRX(void)
{
	BIT_WRITE(UCS_RB,RXEN,BIT_LOW);
}

void UARTSetParityBit(uint8 UARTParityMode)
{
	TWO_BITS_WRITE(UCS_RC,UPM0,UARTParityMode);
	BIT_WRITE(UCS_RC,URSEL,BIT_HIGH);
}

void UARTSetStopBitSize(uint8 UARTStopBitSize)
{
	BIT_WRITE(UCS_RC,USBS,UARTStopBitSize);
	BIT_WRITE(UCS_RC,URSEL,BIT_HIGH);
}

void UARTSetDataSize(uint8 DataSize)
{
	TWO_BITS_WRITE(UCS_RC,UCSZ0,TWO_BITS_GET(DataSize,0));
	BIT_WRITE(UCS_RC,URSEL,BIT_HIGH);
	BIT_WRITE(UCS_RB,UCSZ2,(DataSize>>2));
}

void UARTSetBaudRate(uint32 BaudRate,uint8 AsyncSpeedMode)
{
	BIT_WRITE(UCS_RA,U2X,AsyncSpeedMode);
	uint16 UBRRValue;
	switch(AsyncSpeedMode)
	{
		case UART_SINGLE_SPEED:
			UBRRValue=(uint16)((F_CPU/(16.0*BaudRate))-1);
			break;
		case UART_DOUBLE_SPEED:
			UBRRValue=(uint16)((F_CPU/(8.0*BaudRate))-1);
			break;
		default:
			break;		
	}
	REG_WRITE(UBR_RH,(UBRRValue>>8));
	REG_WRITE(UBR_RL,UBRRValue);
}

void UARTTransmit(uint8 Data)
{
	while(!(BIT_GET(UCS_RA,UDRE)));
	REG_WRITE(UD_R,Data);
}

void UARTTransmitString(uint8 *Data)
{
	for(uint8 i=0;Data[i]!='\0';i++)
	{
		UARTTransmit(Data[i]);
	}
}

void UARTTransmit9Bits(uint16 Data)
{
	while(!(BIT_GET(UCS_RA,UDRE)));
	BIT_WRITE(UCS_RB,TXB8,BIT_GET((Data>>8),0));
	REG_WRITE(UD_R,Data);
}

uint8 UARTAvailable(void)
{
	if(BIT_GET(UCS_RA,RXC))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8 UARTReceive(void)
{
	return REG_GET(UD_R);
}

uint16 UARTReceive9Bits(void)
{
	uint16 Data;
	Data =(BIT_GET(UCS_RB,RXB8)>>RXB8)<<8;
	Data |=REG_GET(UD_R);
	return Data;
}

void UARTInterruptInit(uint8 UARTIntType)
{
	UARTInterruptEnable(UARTIntType);
	GlobalInterruptEnable();
}

void UARTInterruptEnable(uint8 UARTIntType)
{
	switch(UARTIntType)
	{
		case RX_COMPLETE:
			BIT_WRITE(UCS_RB,RXCIE,BIT_HIGH);
			break;
		case TX_COMPLETE:
			BIT_WRITE(UCS_RB,TXCIE,BIT_HIGH);
			break;
		case DATA_REGISTER_EMPTY:
			BIT_WRITE(UCS_RB,UDRIE,BIT_HIGH);
			break;
		default:
			break;
	}	
}

void UARTInterruptDisable(uint8 UARTIntType)
{
	switch(UARTIntType)
	{
		case RX_COMPLETE:
			BIT_WRITE(UCS_RB,RXCIE,BIT_LOW);
			break;
		case TX_COMPLETE:
			BIT_WRITE(UCS_RB,TXCIE,BIT_LOW);
			break;
		case DATA_REGISTER_EMPTY:
			BIT_WRITE(UCS_RB,UDRIE,BIT_LOW);
			break;
		default:
			break;
	}		
}