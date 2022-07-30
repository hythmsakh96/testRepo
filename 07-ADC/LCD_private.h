#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/******************************** MAX NUMBER OF ROWS&COLS ************************************/
	#if 	LCD_SIZE==LCD_1X8
	#define MAX_ROWS   1
	#define MAX_COLS   8

	#elif 	LCD_SIZE==LCD_1X16
	#define MAX_ROWS   1
	#define MAX_COLS   16

	#elif 	LCD_SIZE==LCD_1X20
	#define MAX_ROWS   1
	#define MAX_COLS   20

	#elif 	LCD_SIZE==LCD_2X8
	#define MAX_ROWS   2
	#define MAX_COLS   8

	#elif 	LCD_SIZE==LCD_2X16
	#define MAX_ROWS   2
	#define MAX_COLS   16

	#elif 	LCD_SIZE==LCD_2X20
	#define MAX_ROWS   2
	#define MAX_COLS   20

	#elif 	LCD_SIZE==LCD_4X16
	#define MAX_ROWS   4
	#define MAX_COLS   16

	#elif 	LCD_SIZE==LCD_4X20
	#define MAX_ROWS   4
	#define MAX_COLS   20
	#else
	#error You must include config before private
#endif


				/*******************FROM LCD DATASHEET*****************/
/**************************************** DDRAM ******************************************************/
	#define DDRAM_BASE_ADDRESS    0X80
	#define ROW_0_OFFSET          0X00
	#define ROW_1_OFFSET          0X40
	#define ROW_2_OFFSET          0X14
	#define ROW_3_OFFSET          0X54

	#define LCD_ROW_0             (DDRAM_BASE_ADDRESS+ROW_0_OFFSET)
	#define LCD_ROW_1             (DDRAM_BASE_ADDRESS+ROW_1_OFFSET)
	#define LCD_ROW_2             (DDRAM_BASE_ADDRESS+ROW_2_OFFSET)
	#define LCD_ROW_3             (DDRAM_BASE_ADDRESS+ROW_3_OFFSET)
/**************************************** CGRAM ******************************************************/
	#define CGRAM_BASE_ADDRESS    0X40
/*************************************** COMMANDS ***************************************************/
	#define LCD_CLEAR			  0X01
/****************************************************************************************************
 * return cursor to its home , return display to its original state if it was shifted
 ****************************************************************************************************/
	#define LCD_CURSOR_HOME       0X02
/***************************************************************************************************
 * ENTRY_MODE BITS         0B 0 0 0 0 0 1 I/D S
 * I/D:increment cursor(1) ,decrement cursor(0)       which means--> write from left to right or from right to left
 * S:shift the lcd while typing(1) or no shifting(0) ,the lcd will shift left if the cursor is in increment mode (I)
 ****************************************************************************************************/
	#define LCD_ENTRY_MODE_1      0X04     //decrement , no shifting
	#define LCD_ENTRY_MODE_2      0X05     //decrement , shifting
	#define LCD_ENTRY_MODE_3      0X06     //increment , no shifting (the most commonly used)
	#define LCD_ENTRY_MODE_4      0X07     //increment , shifting
/***************************************************************************************************
 * DIPLAY_ON_OFF BITS		0B 0 0 0 0 1 D C B
 * D:the display is on(1) or off(0)
 * C:the cursor is displayed (1) or not (0)
 * B:the place at cursor position is blinking(1) or not(0)
 ***************************************************************************************************/
	#define LCD_DISPLAY_ON_OFF_1  0X08     //D(0),C(0),B(0)
	#define LCD_DISPLAY_ON_OFF_2  0X09     //D(0),C(0),B(1)
	#define LCD_DISPLAY_ON_OFF_3  0X0A     //D(0),C(1),B(0)
	#define LCD_DISPLAY_ON_OFF_4  0X0B     //D(0),C(1),B(1)
	#define LCD_DISPLAY_ON_OFF_5  0X0C     //D(1),C(0),B(0)  (the most commonly used)
	#define LCD_DISPLAY_ON_OFF_6  0X0D     //D(1),C(0),B(1)
	#define LCD_DISPLAY_ON_OFF_7  0X0E     //D(1),C(1),B(0)
	#define LCD_DISPLAY_ON_OFF_8  0X0F     //D(1),C(1),B(1)
/***************************************************************************************************
 * CURSOR_DISPLAY BITS       0B 0 0 0 1 S/C R/L 0 0
 * S/C:shift the display (1) or shift the cursor (0)
 * R/L:shift it right (1) or left(0)
 **************************************************************************************************/
	#define LCD_CURSOR_DISPLAY_1  0X10        //cursor ,left
	#define LCD_CURSOR_DISPLAY_2  0X14		  //cursor ,right
	#define LCD_CURSOR_DISPLAY_3  0X18		  //display ,left
	#define LCD_CURSOR_DISPLAY_4  0X1C		  //display ,right
/**************************************************************************************************
 * FUNCTION_SET BITS         0B 0 0 1 DL N F 0 0
 * DL:data line type 4bit mode (0) or 8bit mode (1)
 * N:number of display lines 1 line (0), 2 lines (1)
 * F:font 5x7 font (0),5x10 font (1) this font only with 1 line mode N(0)
 **************************************************************************************************/
	#if 	LCD_MODE==LCD_4BIT_MODE
    #define LCD_INTIALIZ1			  0X03
    #define LCD_INTIALIZ2			  0X02
	#define LCD_FUNCTION_SET_1        0X20     //1 line,font5x7
	#define LCD_FUNCTION_SET_2        0X24     //1 line,font5x10
	#define LCD_FUNCTION_SET_3        0X28     //2 line,font5x7
	#elif 	LCD_MODE==LCD_8BIT_MODE

	#define LCD_FUNCTION_SET_1        0X30     //1 line,font5x7
	#define LCD_FUNCTION_SET_2        0X34	   //1 line,font5x10
	#define LCD_FUNCTION_SET_3        0X38	   //2 line,font5x7
	#endif
  
static void LCD_Enable_Pulse();
static LCD_ErrorStatus LCD_SendHigherNibble(u8 Copy_u8input,u8 Copy_u8Type);
static LCD_ErrorStatus LCD_SendLowerNibble(u8 Copy_u8input,u8 Copy_u8Type);
  
#endif /*file gaurd*/

