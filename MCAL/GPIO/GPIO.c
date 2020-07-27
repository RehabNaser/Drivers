/*
 * File Name: GPIO.c
 * Creation Date: 07/20/2020
 * Author: Rehab
 * Description: C File for GPIO peripheral....
 */ 

#include "GPIO.h"

void GpioPortDirection(uint8 Port , uint8 Dir )
{
	switch(Port)
	{
		case PORT_A:
			switch (Dir)
			{
				case INPUT:
					REG_WRITE(DDR_A,PORT_INPUT);
					break;
				case OUTPUT:
					REG_WRITE(DDR_A,PORT_OUTPUT);
					break;
				default:
					break;
			}
			break;
		case PORT_B:
			switch (Dir)
			{
				case INPUT:
					REG_WRITE(DDR_B,PORT_INPUT);
					break;
				case OUTPUT:
					REG_WRITE(DDR_B,PORT_OUTPUT);
					break;
				default:
					break;
			}
			break;
		case PORT_C:
			switch (Dir)
			{
				case INPUT:
					REG_WRITE(DDR_C,PORT_INPUT);
					break;
				case OUTPUT:
					REG_WRITE(DDR_C,PORT_OUTPUT);
					break;
				default:
					break;			 
			}
			break;
		case PORT_D:
			switch (Dir)
			{
				case INPUT:
					REG_WRITE(DDR_D,PORT_INPUT);
					break;
				case OUTPUT:
					REG_WRITE(DDR_D,PORT_OUTPUT);
					break;
				default:
					break;
			}	
			break;
		default:
			break;
	}	
}

void GpioPortWrite(uint8 Port , uint8 Val )
{
	switch(Port)
	{
		case PORT_A:
			REG_WRITE(VALR_A,Val);
			break;
		case PORT_B:
			REG_WRITE(VALR_B,Val);
			break;	  
		case PORT_C:
			REG_WRITE(VALR_C,Val);
			break;
		case PORT_D:
			REG_WRITE(VALR_D,Val);
			break;
		default:
			break;
	} 	   
}

void GpioPortToggle(uint8 Port)
{
	switch(Port)
	{
		case PORT_A:
			REG_TOGGLE(VALR_A);
			break;
		case PORT_B:
			REG_TOGGLE(VALR_B);
			break;
		case PORT_C:
			REG_TOGGLE(VALR_C);
			break;
		case PORT_D:
			REG_TOGGLE(VALR_D);
			break;			
		default:
			break;
	}	
}

uint8 GpioPortRead(uint8 Port)
{
	switch(Port)
	{
		case PORT_A:
			return (REG_GET(INPUTR_A));
			break;
		case PORT_B:
			return (REG_GET(INPUTR_B));
			break;
		case PORT_C:
			return (REG_GET(INPUTR_C));
			break;
		case PORT_D:
			return (REG_GET(INPUTR_D));
			break;
		default:
			break;
	}	
}

void GpioPinDirection(uint8 Port , uint8 PinNo ,uint8 Dir)
{
	switch(Port)
	{
		case PORT_A:
			BIT_WRITE(DDR_A,PinNo,Dir);
			break;
		case PORT_B:
			BIT_WRITE(DDR_B,PinNo,Dir);
			break;
		case PORT_C:
			BIT_WRITE(DDR_C,PinNo,Dir);
			break;
		case PORT_D:
			BIT_WRITE(DDR_D,PinNo,Dir);
			break;
		default:
			break;
	}	
}

void GpioPinWrite(uint8 Port , uint8 PinNo ,uint8 Val)
{
	switch(Port)
	{
		case PORT_A:
			BIT_WRITE(VALR_A,PinNo,Val);
			break;
		case PORT_B:
			BIT_WRITE(VALR_B,PinNo,Val);
			break;
		case PORT_C:
			BIT_WRITE(VALR_C,PinNo,Val);
			break;
		case PORT_D:
			BIT_WRITE(VALR_D,PinNo,Val);
			break;
		default:
			break;
	}	
}

void GpioPinToggle(uint8 Port,uint8 PinNo)
{
	switch(Port)
	{
		case PORT_A:
			BIT_TOGGLE(VALR_A,PinNo);
			break;
		case PORT_B:
			BIT_TOGGLE(VALR_B,PinNo);
			break;
		case PORT_C:
			BIT_TOGGLE(VALR_C,PinNo);
			break;
		case PORT_D:
			BIT_TOGGLE(VALR_D,PinNo);
			break;
		default:
			break;	
	}	
}

uint8 GpioPinRead(uint8 Port,uint8 PinNo)
{
	switch(Port)
	{
		case PORT_A:
			if(BIT_GET(INPUTR_A,PinNo))
				return 1;
			else
				return 0;
			break;
		case PORT_B:
			if(BIT_GET(INPUTR_B,PinNo))
				return 1;
			else
				return 0;
			break;
		case PORT_C:
			if(BIT_GET(INPUTR_C,PinNo))
				return 1;
			else
				return 0;
			break;
		case PORT_D:
			if(BIT_GET(INPUTR_D,PinNo))
				return 1;
			else
				return 0;
			break;
		default:
			break;
	}	
}

void GpioHigherNibbleDirection(uint8 Port , uint8 Dir )
{
	switch(Port)
	{
		case PORT_A:
			switch (Dir)
			{
				case INPUT:
					HIGHER_NIBBLE_WRITE(DDR_A,HIGHER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					HIGHER_NIBBLE_WRITE(DDR_A,HIGHER_NIBBLE_OUTPUT);
					break;
				default:
					break;
			}
			break;	
		case PORT_B:
			switch (Dir)
			{
				case INPUT:
					HIGHER_NIBBLE_WRITE(DDR_B,HIGHER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					HIGHER_NIBBLE_WRITE(DDR_B,HIGHER_NIBBLE_OUTPUT);
					break;
				default:
					break;
			}
			break;
		case PORT_C:
			switch (Dir)
			{
				case INPUT:
					HIGHER_NIBBLE_WRITE(DDR_C,HIGHER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					HIGHER_NIBBLE_WRITE(DDR_C,HIGHER_NIBBLE_OUTPUT);
					break;
				default:
					break;
			}
			break;	 
		case PORT_D:
			switch (Dir)
			{
				case INPUT:
					HIGHER_NIBBLE_WRITE(DDR_D,HIGHER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					HIGHER_NIBBLE_WRITE(DDR_D,HIGHER_NIBBLE_OUTPUT);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	} 	 
}

void GpioHigherNibbleWrite(uint8 Port , uint8 Val )
{
	switch(Port)
	{
		case PORT_A:
			HIGHER_NIBBLE_WRITE(VALR_A,Val);
			break;
		case PORT_B:
			HIGHER_NIBBLE_WRITE(VALR_B,Val);
			break;
		case PORT_C:
			HIGHER_NIBBLE_WRITE(VALR_C,Val);
			break;
		case PORT_D:
			HIGHER_NIBBLE_WRITE(VALR_D,Val);
			break;
		default:
			break;
	}	
}

void GpioHigherNibbleToggle(uint8 Port)
{
	switch(Port)
	{
		case PORT_A:
			HIGHER_NIBBLE_TOGGLE(VALR_A);
			break;
		case PORT_B:
			HIGHER_NIBBLE_TOGGLE(VALR_B);
			break;
		case PORT_C:
			HIGHER_NIBBLE_TOGGLE(VALR_C);
			break;
		case PORT_D:
			HIGHER_NIBBLE_TOGGLE(VALR_D);
			break;
		default:
			break;

	}	
}

uint8 GpioHigherNibbleRead(uint8 Port)
{
	switch(Port)
	{
		case PORT_A:
			return (HIGHER_NIBBLE_GET(INPUTR_A)>>HIGHER_NIBBLE);
			break;
		case PORT_B:
			return (HIGHER_NIBBLE_GET(INPUTR_B)>>HIGHER_NIBBLE);
			break;
		case PORT_C:
			return (HIGHER_NIBBLE_GET(INPUTR_C)>>HIGHER_NIBBLE);
			break;
		case PORT_D:
			return (HIGHER_NIBBLE_GET(INPUTR_D)>>HIGHER_NIBBLE);
			break;
		default:
			break;
	}	
}

void GpioLowerNibbleDirection(uint8 Port , uint8 Dir )
{
	switch(Port)
	{
		case PORT_A:
			switch (Dir)
			{
				case INPUT:
					LOWER_NIBBLE_WRITE(DDR_A,LOWER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					LOWER_NIBBLE_WRITE(DDR_A,LOWER_NIBBLE_OUTPUT);
					break;
				default:
					break;				
			}
			break;
		case PORT_B:
			switch (Dir)
			{
				case INPUT:
					LOWER_NIBBLE_WRITE(DDR_B,LOWER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					LOWER_NIBBLE_WRITE(DDR_B,LOWER_NIBBLE_OUTPUT);
					break;
				default:
					break;				
			}
			break;
		case PORT_C:
			switch (Dir)
			{
				case INPUT:
					LOWER_NIBBLE_WRITE(DDR_C,LOWER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					LOWER_NIBBLE_WRITE(DDR_C,LOWER_NIBBLE_OUTPUT);
					break;
				default:
					break;				
			}
			break;
		case PORT_D:
			switch (Dir)
			{
				case INPUT:
					LOWER_NIBBLE_WRITE(DDR_D,LOWER_NIBBLE_INPUT);
					break;
				case OUTPUT:
					LOWER_NIBBLE_WRITE(DDR_D,LOWER_NIBBLE_OUTPUT);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	} 	  	
}

void GpioLowerNibbleWrite(uint8 Port , uint8 Val )
{
	switch(Port)
	{
		case PORT_A:
			LOWER_NIBBLE_WRITE(VALR_A,Val);
			break;
		case PORT_B:
			LOWER_NIBBLE_WRITE(VALR_B,Val);
			break;
		case PORT_C:
			LOWER_NIBBLE_WRITE(VALR_C,Val);
			break;
		case PORT_D:
			LOWER_NIBBLE_WRITE(VALR_D,Val);
			break;
		default:
			break;

	}	
}

void GpioLowerNibbleToggle(uint8 Port)
{
	switch(Port)
	{
		case PORT_A:
			LOWER_NIBBLE_TOGGLE(VALR_A);
			break;
		case PORT_B:
			LOWER_NIBBLE_TOGGLE(VALR_B);
			break;	
		case PORT_C:
			LOWER_NIBBLE_TOGGLE(VALR_C);
			break;	 
		case PORT_D:
			LOWER_NIBBLE_TOGGLE(VALR_D);
			break;
		default:
			break;

	}
} 	

uint8 GpioLowerNibbleRead(uint8 Port)
{
	switch(Port)
	{
		case PORT_A:
			return (LOWER_NIBBLE_GET(INPUTR_A)>>LOWER_NIBBLE);
			break;
		case PORT_B:
			return (LOWER_NIBBLE_GET(INPUTR_B)>>LOWER_NIBBLE);
			break;
		case PORT_C:
			return (LOWER_NIBBLE_GET(INPUTR_C)>>LOWER_NIBBLE);
			break;
		case PORT_D:
			return (LOWER_NIBBLE_GET(INPUTR_D)>>LOWER_NIBBLE);
			break;
		default:
			break;

	}
}