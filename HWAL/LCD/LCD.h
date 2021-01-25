/*
 * File Name: LCD.h
 * Creation Date: 07/24/2020
 * Author: Rehab
 * Description: Header File for LCD...
 */ 

#ifndef LCD_H_
#define LCD_H_

//FILES INCLUDING
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "MC_REGISTERS.h"
#include "LCD_CONFIG.h"

//RW PIN
#define READ HIGH
#define WRITE LOW

//RS PIN
#define DR HIGH
#define IR LOW

//CLEAR DISPLAY COMMAND
#define LCD_CLEAR_DISPALY 0X01
//RETURN HOME COMMAND
#define LCD_RETURN_HOME 0X02
//ENTRY MODE SET COMMANDS
#define LCD_INC_AC 0X06
#define LCD_DEC_AC 0X04
#define LCD_INC_AC_SHIFT_LEFT 0X07
#define LCD_DEC_AC_SHIFT_RIGHT 0X05
//FUNCTION SET COMMANDS
#define LCD_8BITS_1LINE_5X8 0X30
#define LCD_8BITS_1LINE_5X11 0X34
#define LCD_8BITS_2LINE_5X8 0X38
#define LCD_4BITS_1LINE_5X8 0X20
#define LCD_4BITS_1LINE_5X11 0X24
#define LCD_4BITS_2LINE_5X8 0X28
//DISPLAY ON/OFF COMMANDS
#define LCD_DISPLAYOFF_CURSOROFF 0X08
#define LCD_DISPLAYON_CURSORON_NOBLINKING 0X0E
#define LCD_DISPLAYON_CURSOROFF_NOBLINKING	0X0C
#define LCD_DISPLAYON_CURSORON_BLINKING 0X0F
#define LCD_DISPLAYON_CURSOROFF_BLINKING	0X0D
//CURSOR OR DISPLAY SHIFT COMMANDS 
#define LCD_SHIFTDISPLAY_LEFT 0X18
#define LCD_SHIFTDISPLAY_RIGHT 0X1C
#define LCD_MOVECURSOR_LEFT 0X10
#define LCD_MOVECURSOR_RIGHT 0X14

#define LCD_LINE1_STARTADDRESS 0X00
#define LCD_LINE2_STARTADDRESS 0X40
#define LCD_LINE3_STARTADDRESS 0X14
#define LCD_LINE4_STARTADDRESS 0X54

//SET DDRAM ADDRESS COMMAND
#define LCD_LINE1_DDRAM_ADDRESS(COLUMN) ((0X80|LCD_LINE1_STARTADDRESS)|COLUMN)
#define LCD_LINE2_DDRAM_ADDRESS(COLUMN) ((0X80|LCD_LINE2_STARTADDRESS)|COLUMN)
#define LCD_LINE3_DDRAM_ADDRESS(COLUMN) ((0X80|LCD_LINE3_STARTADDRESS)|COLUMN)
#define LCD_LINE4_DDRAM_ADDRESS(COLUMN) ((0X80|LCD_LINE4_STARTADDRESS)|COLUMN)

//SET CGRAM ADDRESS COMMAND
#define LCD_CGRAM_ADDRESS 0X40

//CURSOR STATE
#define CURSOR_OFF 0
#define CURSOR_ON 1

//BLINK STATE
#define BLINK_OFF 0
#define BLINK_ON 1

//MACROS
#define SEND_HIGHER_NIBBLE_PART(VAL) ((VAL>>HIGHER_NIBBLE)&0X0F)
#define SEND_LOWER_NIBBLE_PART(VAL) ((VAL>>LOWER_NIBBLE)&0X0F)

//FUNCTIONS PROTOTYPES
static void LCD4BitsModeReset(void);
static void LCD8BitsModeReset(void);
void LCDInit(void);

static void LCDEnableSignal(void);

static void LCDSendCmdOrData4BitsMode(uint8 DC);
static void LCDSendCmdOrData8BitsMode(uint8 DC);

void LCDSendCommand(uint8 Cmd);
void LCDSendData(uint8 Data);
void LCDSendString(uint8 *String);
void LCDSendNumber(uint32 Number);

void LCDClear(void);
void LCDReturnHome(void);

void LCDWriteArabic(void);
void LCDWriteEnglish(void);

void LCDDisplayOff(void);
void LCDDisplayOn(uint8 CursorState,uint8 BlinkState);

void LCDDisplayShiftRight(void);
void LCDDisplayShiftLeft(void);
void LCDCursorMoveRight(void);
void LCDCursorMoveLeft(void);

void LCDSetCursor(uint8 Row , uint8 column);

void LCDDisplayString(uint8 Row , uint8 column , uint8 *String);
void LCDDisplayChar(uint8 Row , uint8 column , uint8 Char);
void LCDDisplayNumber(uint8 Row , uint8 column , uint32 Number);

void LCDCreat5X8Char(uint8 CharNo , uint8 *Char);
void LCDCreat5X11Char(uint8 CharNo , uint8 *Char);

#endif

