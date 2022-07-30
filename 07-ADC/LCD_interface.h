#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/**/
#include "LIB/STD_TYPES.h"

/********************************** LCD AVAILABLE SIZES ************************************************/
	#define LCD_1X8             0
	#define LCD_1X16            1
	#define LCD_1X20            2
	#define LCD_2X8             3
	#define LCD_2X16            4
	#define LCD_2X20            5
	#define LCD_4X16            6
	#define LCD_4X20            7
/********************************** LCD AVAILABLE MODES ************************************************/
	#define LCD_4BIT_MODE       0
	#define LCD_8BIT_MODE       1
/*************************************** help in code readability *******************************/
#define LCD_COMMAND	              0
#define LCD_DATA		          1
                              
#define LCD_WRITE		          0
#define LCD_READ		          1


typedef enum
{
  LCD_NOK,
  LCD_OK
}LCD_ErrorStatus;

/**/

LCD_ErrorStatus LCD_Init();
LCD_ErrorStatus LCD_Send (u8 Copy_u8input , u8 Copy_u8Type);
LCD_ErrorStatus LCD_DisplayChar(u8 Copy_u8inputChar);
void LCD_DisplayString(u8* Copy_pu8inputString);
LCD_ErrorStatus LCD_CreateCustomChar(u8* Copy_u8CustomChar,u8 index);
void LCD_ShiftLeft(u8 Copy_u8Number);
void LCD_ShiftRight(u8 Copy_u8Number);
void LCD_CursorShiftLeft(u8 Copy_u8Number);
void LCD_CursorShiftRight(u8 Copy_u8Number);
void LCD_SetCursor(u8 Copy_u8Row,u8 Copy_u8Col);
void LCD_Clear();





#endif /*file gaurd*/
