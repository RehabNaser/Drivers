/*
 * File Name: LCD.c
 * Creation Date: 07/24/2020
 * Author: Rehab
 * Description: C File for LCD...
 */ 

#include "LCD.h"

static void LCD8BitsModeReset(void)
{	
	GpioPortDirection(LCD_DATA_PORT,OUTPUT);
	_delay_ms(20);
	GpioPortWrite(LCD_DATA_PORT,0X30);
	LCDEnableSignal();
	_delay_ms(5);
	GpioPortWrite(LCD_DATA_PORT,0X30);
	LCDEnableSignal();
	_delay_us(150);
	GpioPortWrite(LCD_DATA_PORT,0X30);
	LCDEnableSignal();
	_delay_us(150);
	LCDSendCommand(LCD_8BITS_2LINE_5X8);
}

static void LCD4BitsModeReset(void)
{
	#if LCD_DATA_PINS==HIGHER_NIBBLE
		GpioHigherNibbleDirection(LCD_DATA_PORT,OUTPUT);
		_delay_ms(20);
		GpioHigherNibbleWrite(LCD_DATA_PORT,0X03);
		LCDEnableSignal();
		_delay_ms(5);
		GpioHigherNibbleWrite(LCD_DATA_PORT,0X03);
		LCDEnableSignal();
		_delay_us(150);
		GpioHigherNibbleWrite(LCD_DATA_PORT,0X03);
		LCDEnableSignal();	
		_delay_us(150);
		GpioHigherNibbleWrite(LCD_DATA_PORT,0X02);
		LCDEnableSignal();
		_delay_us(150);
		LCDSendCommand(LCD_4BITS_2LINE_5X8);
	#elif LCD_DATA_PINS==LOWER_NIBBLE
		GpioLowerNibbleDirection(LCD_DATA_PORT,OUTPUT);
		_delay_ms(20);
		GpioLowerNibbleWrite(LCD_DATA_PORT,0X03);
		LCDEnableSignal();
		_delay_ms(5);
		GpioLowerNibbleWrite(LCD_DATA_PORT,0X03);
		LCDEnableSignal();
		_delay_us(150);
		GpioLowerNibbleWrite(LCD_DATA_PORT,0X03);
		LCDEnableSignal();
		_delay_us(150);
		GpioLowerNibbleWrite(LCD_DATA_PORT,0X02);
		LCDEnableSignal();
		_delay_us(150);
		LCDSendCommand(LCD_4BITS_2LINE_5X8);
	#endif
}

static void LCDEnableSignal(void)
{
	GpioPinWrite(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_us(1);
	GpioPinWrite(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_us(1);	
}

void LCDInit(void)
{
	#ifdef LCD_RW
		GpioPinDirection(LCD_CONTROL_PORT,LCD_RW,OUTPUT);
		GpioPinWrite(LCD_CONTROL_PORT,LCD_RW,WRITE);
	#endif
	
	GpioPinDirection(LCD_CONTROL_PORT,LCD_RS,OUTPUT);
	GpioPinDirection(LCD_CONTROL_PORT,LCD_EN,OUTPUT);
	GpioPinWrite(LCD_CONTROL_PORT,LCD_EN,HIGH);
	
	#if LCD_MODE==LCD4BITSMODE
		LCD4BitsModeReset();
	#elif LCD_MODE==LCD8BITSMODE
		LCD8BitsModeReset();
	#endif
	
	LCDClear();
	LCDDisplayOn(CURSOR_ON,BLINK_OFF);
	LCDWriteEnglish();
}

static void LCDSendCmdOrData4BitsMode(uint8 CD)
{
	#if LCD_DATA_PINS==HIGHER_NIBBLE
		GpioHigherNibbleWrite(LCD_DATA_PORT,SEND_HIGHER_NIBBLE_PART(CD));
		LCDEnableSignal();
		GpioHigherNibbleWrite(LCD_DATA_PORT,SEND_LOWER_NIBBLE_PART(CD));
		LCDEnableSignal();
		_delay_ms(2);
	#elif LCD_DATA_PINS==LOWER_NIBBLE
		GpioLowerNibbleWrite(LCD_DATA_PORT,SEND_HIGHER_NIBBLE_PART(CD));
		LCDEnableSignal();
		GpioLowerNibbleWrite(LCD_DATA_PORT,SEND_LOWER_NIBBLE_PART(CD));
		LCDEnableSignal();
		_delay_ms(2);
	#endif
}

static void LCDSendCmdOrData8BitsMode(uint8 CD)
{
	GpioPortWrite(LCD_DATA_PORT,CD);
	LCDEnableSignal();
	_delay_ms(2);
}

void LCDSendCommand(uint8 Cmd)
{
	GpioPinWrite(LCD_CONTROL_PORT,LCD_RS,IR);
	#if LCD_MODE==LCD4BITSMODE
		LCDSendCmdOrData4BitsMode(Cmd);
	#elif LCD_MODE==LCD8BITSMODE
		LCDSendCmdOrData8BitsMode(Cmd);
	#endif
}

void LCDSendData(uint8 Data)
{
	GpioPinWrite(LCD_CONTROL_PORT,LCD_RS,DR);
	#if LCD_MODE==LCD4BITSMODE
		LCDSendCmdOrData4BitsMode(Data);
	#elif LCD_MODE==LCD8BITSMODE
		LCDSendCmdOrData8BitsMode(Data);
	#endif
}

void LCDSendString(uint8 *String)
{
	while(*String!='\0')
	{
		LCDSendData(*String);
		String++;
	} 	 	
}

void LCDSendNumber(uint32 Number)
{
	uint8 Numbers[10];
	int8 Count;
	if(Number==0)
	{
		LCDSendData(48);
		return;
	}
	for(Count=0;Number>0;Count++)
	{
		Numbers[Count]=(Number%10)+48;
		Number=Number/10;
	}
	for(Count--;Count>=0;Count--)
	{
		LCDSendData(Numbers[Count]);
	}	
}

void LCDClear(void)
{
	LCDSendCommand(LCD_CLEAR_DISPALY);
}

void LCDDisplayOff(void)
{
	LCDSendCommand(LCD_DISPLAYOFF_CURSOROFF);	
}

void LCDDisplayOn(uint8 CursorState,uint8 BlinkState)
{
	switch(CursorState)
	{
		case CURSOR_ON:
			switch(BlinkState)
			{
				case BLINK_ON:
					LCDSendCommand(LCD_DISPLAYON_CURSORON_BLINKING);
					break;
				case BLINK_OFF:
					LCDSendCommand(LCD_DISPLAYON_CURSORON_NOBLINKING);
					break;
				default:
					break;
			}
			break;
		case CURSOR_OFF:
			switch(BlinkState)
			{
				case BLINK_ON:
					LCDSendCommand(LCD_DISPLAYON_CURSOROFF_BLINKING);
					break;
				case BLINK_OFF:
					LCDSendCommand(LCD_DISPLAYON_CURSOROFF_NOBLINKING);
					break;
				default:
					break;					
			}
			break;
		default:
			break;
	} 	
}

void LCDReturnHome(void)
{
	LCDSendCommand(LCD_RETURN_HOME);	
}

void LCDWriteArabic(void)
{
	LCDSendCommand(LCD_DEC_AC);	
}

void LCDWriteEnglish(void)
{
	LCDSendCommand(LCD_INC_AC);	
}

//ROWS AND COLUMNS START FROM 1
void LCDSetCursor(uint8 Row , uint8 column)
{
	column--;
	switch(Row)
	{
		case 1:
			LCDSendCommand(LCD_LINE1_DDRAM_ADDRESS(column));
			break;
		case 2:
			LCDSendCommand(LCD_LINE2_DDRAM_ADDRESS(column));
			break; 
		case 3:
			LCDSendCommand(LCD_LINE3_DDRAM_ADDRESS(column));
			break;	 
		case 4:
			LCDSendCommand(LCD_LINE4_DDRAM_ADDRESS(column));
			break;	
		default:
			break;
	}
}

//MUST SEND MY SINGLE CHAR WITH DOUBLE QUOTE "" (AS STRING)
void LCDDisplayString(uint8 Row , uint8 column , uint8 *String)
{
	LCDSetCursor(Row,column);
	LCDSendString(String);
}

//CAN SEND MY SINGLE CHAR WITH SINGLE QUOTE ''
void LCDDisplayChar(uint8 Row , uint8 column , uint8 Char)
{
	LCDSetCursor(Row,column);
	LCDSendData(Char);
}

void LCDDisplayNumber(uint8 Row , uint8 column , uint32 Number)
{
	LCDSetCursor(Row,column);
	LCDSendNumber(Number);
}

void LCDDisplayShiftRight(void)
{
	LCDSendCommand(LCD_SHIFTDISPLAY_RIGHT);	
}

void LCDDisplayShiftLeft(void)
{
	LCDSendCommand(LCD_SHIFTDISPLAY_RIGHT);	
}

void LCDCursorMoveRight(void)
{
	LCDSendCommand(LCD_MOVECURSOR_RIGHT);	
}

void LCDCursorMoveLeft(void)
{
	LCDSendCommand(LCD_MOVECURSOR_LEFT);	
}

/*
 * MAX 8 CHARACTERS FOR 5X8 OR 4 CHARACTERS FOR 5X11
 * ON (LCDCreat5X8Char)--> CharNo START FROM 0 TO 7 
 *                     --> TO PRINT THIS CHAR ON LCD (LCDSendData) TAKES VALUES 0 FOR CHAR 0
 *																			    1 FOR CHAR 1
 *																				2 FOR CHAR 2
 *																				3 FOR CHAR 3
 *																				4 FOR CHAR 4
 *																				5 FOR CHAR 5
 *																				6 FOR CHAR 6
 *																				7 FOR CHAR 7
 * ON (LCDCreat5X11Char)--> CharNo START FROM 0 TO 3
 *                     --> TO PRINT THIS CHAR ON LCD (LCDSendData) TAKES VALUES 0 FOR CHAR 0
 *																			    2 FOR CHAR 1
 *																			    4 FOR CHAR 2
 *																				6 FOR CHAR 3
 */
void LCDCreat5X8Char(uint8 CharNo , uint8 *Char)
{
	uint8 Count;
	if( (CharNo<0)||(CharNo>7))
		return; 
	LCDSendCommand(LCD_CGRAM_ADDRESS+(CharNo*8));
	for(Count=0;Count<8;Count++)		
		LCDSendData(Char[Count]);
	LCDSetCursor(1,1);	
}

void LCDCreat5X11Char(uint8 CharNo , uint8 *Char)
{
	uint8 Count;
	if( (CharNo<0)||(CharNo>3))
		return;
	LCDSendCommand(LCD_CGRAM_ADDRESS+(CharNo*16));
	for(Count=0;Count<11;Count++)
		LCDSendData(Char[Count]);
	LCDSetCursor(1,1);
}