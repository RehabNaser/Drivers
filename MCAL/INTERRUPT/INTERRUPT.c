/*
 * File Name: INTERRUPT.c
 * Creation Date: 07/22/2020
 * Author: Rehab
 * Description: C File for INTERRUPT peripheral....
 */ 

#include "INTERRUPT.h"

void GlobalInterruptEnable(void)
{
	BIT_WRITE(S_REG,I,BIT_HIGH);	
}

void GlobalInterruptDisable(void)
{
	BIT_WRITE(S_REG,I,BIT_LOW);	
}

void ExternalInterruptInit(uint8 ExternalIntNum,uint8 ExternalIntMode,uint8 ExternalIntPinConnectionMode)
{
	switch(ExternalIntNum)
	{
		case INTN0:
			GpioPinDirection(INT0_PORT,INT0_PIN,INPUT);
			switch(ExternalIntPinConnectionMode)
			{
				case PULLUP_SW:
					GpioPinWrite(INT0_PORT,INT0_PIN,BIT_HIGH);
					break;
				default:
					break;
			}
			break;
		case INTN1:
			GpioPinDirection(INT1_PORT,INT1_PIN,INPUT);
			switch(ExternalIntPinConnectionMode)
			{
				case PULLUP_SW:
					GpioPinWrite(INT1_PORT,INT1_PIN,BIT_HIGH);
					break;
				default:
					break;
			}		
			break;
		case INTN2:
			GpioPinDirection(INT2_PORT,INT2_PIN,INPUT);
			switch(ExternalIntPinConnectionMode)
			{
				case PULLUP_SW:
					GpioPinWrite(INT2_PORT,INT2_PIN,BIT_HIGH);
					break;
				default:
					break;
			}		
			break;
		default:
			break;
	}
	ExternalInterruptMode(ExternalIntNum,ExternalIntMode);
	ExternalInterruptEnable(ExternalIntNum);
	GlobalInterruptEnable();
	
	
 
}

void ExternalInterruptEnable(uint8 ExternalIntNum)
{
	switch(ExternalIntNum)
	{
		case INTN0:
			BIT_WRITE(GIC_R,INT0,BIT_HIGH);
			break;
		case INTN1:
			BIT_WRITE(GIC_R,INT1,BIT_HIGH);
			break;
		case INTN2:
			BIT_WRITE(GIC_R,INT2,BIT_HIGH);
			break;
		default:
			break;
	}	
}

void ExternalInterruptDisable(uint8 ExternalIntNum)
{
	switch(ExternalIntNum)
	{
		case INTN0:
			BIT_WRITE(GIC_R,INT0,BIT_LOW);
			break;
		case INTN1:
			BIT_WRITE(GIC_R,INT1,BIT_LOW);
			break;
		case INTN2:
			BIT_WRITE(GIC_R,INT2,BIT_LOW);
			break;
		default:
			break;
	}	
}

void ExternalInterruptMode(uint8 ExternalIntNum,uint8 ExternalIntMode)
{
	switch(ExternalIntNum)
	{
		case INTN0:
			switch(ExternalIntMode)
			{
				case LOW_LEVEL:
					TWO_BITS_WRITE(MCUC_R,ISC00,LOW_LEVEL);
					break;
				case LOGICAL_CHANGE:
					TWO_BITS_WRITE(MCUC_R,ISC00,LOGICAL_CHANGE);			
					break;
				case FALLING_EDGE:
					TWO_BITS_WRITE(MCUC_R,ISC00,FALLING_EDGE);
					break;
				case RISING_EDGE:
					TWO_BITS_WRITE(MCUC_R,ISC00,RISING_EDGE);
					break;
				default:
					break;
			}
			break;
		case INTN1:
			switch(ExternalIntMode)
			{
				case LOW_LEVEL:
					TWO_BITS_WRITE(MCUC_R,ISC10,LOW_LEVEL);
					break;
				case LOGICAL_CHANGE:
					TWO_BITS_WRITE(MCUC_R,ISC10,LOGICAL_CHANGE);
					break;
				case FALLING_EDGE:
					TWO_BITS_WRITE(MCUC_R,ISC10,FALLING_EDGE);
					break;
				case RISING_EDGE:
					TWO_BITS_WRITE(MCUC_R,ISC10,RISING_EDGE);
					break;
				default:
					break;
			}		
			break;
		case INTN2:
			switch(ExternalIntMode)
			{
				case FALLING_EDGE:
					BIT_WRITE(MCUCS_R,ISC2,BIT_LOW);
					break;
				case RISING_EDGE:
					BIT_WRITE(MCUCS_R,ISC2,BIT_HIGH);
					break;
				default:
					break;
			}		
			break;
		default:
			break;
	}	
}

void TimerInterruptInit(uint8 TimerNum,uint8 TimerIntType)
{
	TimerInterruptEnable(TimerNum,TimerIntType); 
	GlobalInterruptEnable();	
}

void TimerInterruptEnable(uint8 TimerNum,uint8 TimerIntType)
{
	switch(TimerNum)
	{
		case TIMER0:
			switch(TimerIntType)
			{
				case COMPARE:
					BIT_WRITE(TIMSK_R,OCIE0,BIT_HIGH);
					break;
				case OVERFLOW:
					BIT_WRITE(TIMSK_R,TOIE0,BIT_HIGH);
					break;
				default:
					break;
			}
			break;
		case TIMER1:
			switch(TimerIntType)
			{
				case CAPTURE:
					BIT_WRITE(TIMSK_R,TICIE1,BIT_HIGH);
					break;
				case OVERFLOW:
					BIT_WRITE(TIMSK_R,TOIE1,BIT_HIGH);
					break;
				case COMPARE_A:
					BIT_WRITE(TIMSK_R,OCIE1A,BIT_HIGH);
					break;
				case COMPARE_B:
					BIT_WRITE(TIMSK_R,OCIE1B,BIT_HIGH);
					break;
				default:
					break;
			}	 
			break;
		case TIMER2:
			switch(TimerIntType)
			{
				case COMPARE:
					BIT_WRITE(TIMSK_R,OCIE2,BIT_HIGH);
					break;
				case OVERFLOW:
					BIT_WRITE(TIMSK_R,TOIE2,BIT_HIGH);
					break;
				default:
					break;				
			}	 
			break;
		default:
			break;
	}	
}

void TimerInterruptDisable(uint8 TimerNum,uint8 TimerIntType)
{
	switch(TimerNum)
	{
		case TIMER0:
			switch(TimerIntType)
			{
				case COMPARE:
					BIT_WRITE(TIMSK_R,OCIE0,BIT_LOW);
					break;
				case OVERFLOW:
					BIT_WRITE(TIMSK_R,TOIE0,BIT_LOW);
					break;
				default:
					break;
			}	 
			break;
		case TIMER1:
			switch(TimerIntType)
			{
				case CAPTURE:
					BIT_WRITE(TIMSK_R,TICIE1,BIT_LOW);
					break;			
				case OVERFLOW:
					BIT_WRITE(TIMSK_R,TOIE1,BIT_LOW);
					break;			
				case COMPARE_A:
					BIT_WRITE(TIMSK_R,OCIE1A,BIT_LOW);
					break;
				case COMPARE_B:
					BIT_WRITE(TIMSK_R,OCIE1B,BIT_LOW);
					break;	
				default:
					break;				
			}	 
			break;
		case TIMER2:
			switch(TimerIntType)
			{
				case COMPARE:
					BIT_WRITE(TIMSK_R,OCIE2,BIT_LOW);
					break;
				case OVERFLOW:
					BIT_WRITE(TIMSK_R,TOIE2,BIT_LOW);
					break;
				default:
					break;				
			}	 
			break;	
		default:
			break;		
	}	
}

void SPIInterruptInit(void)
{
	SPIInterruptEnable();
	GlobalInterruptEnable();
}

void SPIInterruptEnable(void)
{
	BIT_WRITE(SPC_R,SPIE,BIT_HIGH);	
}

void SPIInterruptDisable(void)
{
	BIT_WRITE(SPC_R,SPIE,BIT_LOW);	
}

void TWIInterruptInit(void)
{
	TWIInterruptEnable();
	GlobalInterruptEnable();
}

void TWIInterruptEnable(void)
{
	BIT_WRITE(TWC_R,TWIE,BIT_HIGH);	
}

void TWIInterruptDisable(void)
{
	BIT_WRITE(TWC_R,TWIE,BIT_LOW);	
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

void USARTInterruptInit(uint8 USARTIntType)
{
	USARTInterruptEnable(USARTIntType);
	GlobalInterruptEnable();
}

void USARTInterruptEnable(uint8 USARTIntType)
{
	switch(USARTIntType)
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

void USARTInterruptDisable(uint8 USARTIntType)
{
	switch(USARTIntType)
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