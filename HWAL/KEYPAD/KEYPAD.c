/*
 * File Name: KEYPAD.c
 * Creation Date: 07/24/2020
 * Author: Rehab
 * Description: C File for keypad...
 */ 


#include "KEYPAD.h"

uint8 Keypad[4][4]=
{
	{'1','2','3','-'},
	{'4','5','6','*'},
	{'7','8','9','/'},
	{'c','0','=','+'}
};

void KeypadInit(void)
{
	//ROWS (INPUTS)
	#if KEYPAD_ROWSPINS==HIGHER_NIBBLE
		GpioHigherNibbleDirection(KEYPAD_PORT,INPUT);
		#if KEYPAD_CONNECTION_MODE==PULLUP_SW
			GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_HIGH);
		#endif
	#elif KEYPAD_ROWSPINS==LOWER_NIBBLE
		GpioLowerNibbleDirection(KEYPAD_PORT,INPUT);
		#if KEYPAD_CONNECTION_MODE==PULLUP_SW
			GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_HIGH);
		#endif	
	#endif
	//COLUMNS (OUTPUTS)
	#if KEYPAD_COLUMNPINS==HIGHER_NIBBLE
		GpioHigherNibbleDirection(KEYPAD_PORT,OUTPUT);
		#if KEYPAD_CONNECTION_MODE==PULLDOWN
			GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_LOW);
		#else
			GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_HIGH);
		#endif	
	#elif KEYPAD_COLUMNPINS==LOWER_NIBBLE
		GpioLowerNibbleDirection(KEYPAD_PORT,OUTPUT);
		#if KEYPAD_CONNECTION_MODE==PULLDOWN
			GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_LOW);
		#else
			GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_HIGH);
		#endif
	#endif
} 

uint8 KeypadReadKey(void)
{
	uint8 Row=0,Col=0;
	#if KEYPAD_COLUMNPINS==HIGHER_NIBBLE
		#if KEYPAD_ROWSPINS==HIGHER_NIBBLE
			#if KEYPAD_CONNECTION_MODE==PULLDOWN
				for(Col=0;Col<4;Col++)
				{
					GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_LOW);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,HIGH);
					_delay_ms(20);
					Row=GpioHigherNibbleRead(KEYPAD_PORT);
					if(Row!=HIGHER_NIBBLE_LOW)
					{
						while(GpioHigherNibbleRead(KEYPAD_PORT)!=HIGHER_NIBBLE_LOW);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];				
			#else
				for(Col=0;Col<4;Col++)
				{
					GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_HIGH);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,LOW);
					_delay_ms(20);
					Row=GpioHigherNibbleRead(KEYPAD_PORT);
					if(Row!=HIGHER_NIBBLE_HIGH)
					{
						while(GpioHigherNibbleRead(KEYPAD_PORT)!=HIGHER_NIBBLE_HIGH);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];				
			#endif
		#elif KEYPAD_ROWSPINS==LOWER_NIBBLE
			#if KEYPAD_CONNECTION_MODE==PULLDOWN
				for(Col=0;Col<4;Col++)
				{
					GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_LOW);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,HIGH);
					_delay_ms(20);
					Row=GpioLowerNibbleRead(KEYPAD_PORT);
					if(Row!=LOWER_NIBBLE_LOW)
					{
						while(GpioLowerNibbleRead(KEYPAD_PORT)!=LOWER_NIBBLE_LOW);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];					
			#else
				for(Col=0;Col<4;Col++)
				{
					GpioHigherNibbleWrite(KEYPAD_PORT,HIGHER_NIBBLE_HIGH);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,LOW);
					_delay_ms(20);
					Row=GpioLowerNibbleRead(KEYPAD_PORT);
					if(Row!=LOWER_NIBBLE_HIGH)
					{	
						while(GpioLowerNibbleRead(KEYPAD_PORT)!=LOWER_NIBBLE_HIGH);
						break;
					}							
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];				
			#endif			
		#endif
	#elif KEYPAD_COLUMNPINS==LOWER_NIBBLE
		#if KEYPAD_ROWSPINS==HIGHER_NIBBLE
			#if KEYPAD_CONNECTION_MODE==PULLDOWN
				for(Col=0;Col<4;Col++)
				{
					GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_LOW);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,HIGH);
					_delay_ms(20);
					Row=GpioHigherNibbleRead(KEYPAD_PORT);
					if(Row!=HIGHER_NIBBLE_LOW)
					{
						while(GpioHigherNibbleRead(KEYPAD_PORT)!=HIGHER_NIBBLE_LOW);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];				
			#else
				for(Col=0;Col<4;Col++)
				{
					GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_HIGH);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,LOW);
					_delay_ms(20);
					Row=GpioHigherNibbleRead(KEYPAD_PORT);
					if(Row!=HIGHER_NIBBLE_HIGH)
					{
						while(GpioHigherNibbleRead(KEYPAD_PORT)!=HIGHER_NIBBLE_HIGH);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];				
			#endif			
		#elif KEYPAD_ROWSPINS==LOWER_NIBBLE
			#if KEYPAD_CONNECTION_MODE==PULLDOWN
				for(Col=0;Col<4;Col++)
				{
					GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_LOW);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,HIGH);
					_delay_ms(20);
					Row=GpioLowerNibbleRead(KEYPAD_PORT);
					if(Row!=LOWER_NIBBLE_LOW)
					{
						while(GpioLowerNibbleRead(KEYPAD_PORT)!=LOWER_NIBBLE_LOW);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];				
			#else
				for(Col=0;Col<4;Col++)
				{
					GpioLowerNibbleWrite(KEYPAD_PORT,LOWER_NIBBLE_HIGH);
					GpioPinWrite(KEYPAD_PORT,Col+KEYPAD_COLUMNPINS,LOW);
					_delay_ms(20);
					Row=GpioLowerNibbleRead(KEYPAD_PORT);
					if(Row!=LOWER_NIBBLE_HIGH)
					{
						while(GpioLowerNibbleRead(KEYPAD_PORT)!=LOWER_NIBBLE_HIGH);
						break;
					}
				}
				if(Col==4)
					return 0;
				else
					Row=KeypadWhichRow(Row);
				return Keypad[Row][Col];					
			#endif			
		#endif
	#endif	
}

static uint8 KeypadWhichRow(uint8 RowsVal)
{
	uint8 Row=4;
	#if KEYPAD_CONNECTION_MODE==PULLDOWN
		switch(RowsVal)
		{
			case 0X01:
				Row=0;			
				break;
			case 0X02:
				Row=1;		
				break;
			case 0X04:
				Row=2;
				break;
			case 0X08:
				Row=3;		
				break;
			default:
				break;
		}
		return Row;
	#else
		switch(RowsVal)
		{
			case 0X0E:
				Row=0;			
				break;
			case 0X0D:
				Row=1;		
				break;
			case 0X0B:
				Row=2;		
				break;
			case 0X07:
				Row=3;		
				break;
			default:
				break;
		}
		return Row;	
	#endif
}

uint8 KeypadMustPressed(void)
{
	uint8 Key;
	do 
	{
		Key=KeypadReadKey(); 	 
	}while (Key==0);
	return Key;	
}