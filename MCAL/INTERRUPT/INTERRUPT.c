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