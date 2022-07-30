
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <util/delay.h>
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"



/*MCAL LAYER*/
#include "MCAL/DIO/DIO_int.h"

/*LCD_COMMAND	
  LCD_DATA    */

LCD_ErrorStatus LCD_Send(u8 Copy_u8input,u8 Copy_u8Type)
{
    
    //Higher nibble
    LCD_SendHigherNibble(Copy_u8input,Copy_u8Type);


    //Lower nibble
    LCD_SendLowerNibble(Copy_u8input,Copy_u8Type);


    return LCD_OK;
}


LCD_ErrorStatus LCD_Init()
{
  LCD_ErrorStatus error=LCD_OK;
  
  MDIO_vSetPinVal(LCD_D4,DIO_OUTPUT_LOW);
  MDIO_vSetPinVal(LCD_D5,DIO_OUTPUT_LOW);
  MDIO_vSetPinVal(LCD_D6,DIO_OUTPUT_LOW);
  MDIO_vSetPinVal(LCD_D7,DIO_OUTPUT_LOW);
  MDIO_vSetPinVal(RS,DIO_OUTPUT_LOW);
  MDIO_vSetPinVal(RW,DIO_OUTPUT_LOW);
  MDIO_vSetPinVal(EN,DIO_OUTPUT_LOW);
  
  MDIO_vSetPinVal(RW,LCD_WRITE);


  _delay_ms(50);
  
  LCD_SendLowerNibble(LCD_INTIALIZ1,LCD_COMMAND);
  _delay_ms(5);
  LCD_SendLowerNibble(LCD_INTIALIZ1,LCD_COMMAND);
  _delay_us(150);
  
  LCD_SendLowerNibble(LCD_INTIALIZ1,LCD_COMMAND);
  
  LCD_SendLowerNibble(LCD_INTIALIZ2,LCD_COMMAND);
  
  LCD_Send(LCD_FUNCTION_SET_3,LCD_COMMAND);
  LCD_Send(LCD_DISPLAY_ON_OFF_5,LCD_COMMAND);
  LCD_Send(LCD_ENTRY_MODE_3,LCD_COMMAND);
  LCD_Send(LCD_CLEAR,LCD_COMMAND);
  
  
  

  return error;
}

LCD_ErrorStatus LCD_DisplayChar(u8 Copy_u8inputChar)
{
  LCD_Send(Copy_u8inputChar,LCD_DATA);
  return LCD_OK;
}

void LCD_DisplayString(u8* Copy_pu8inputString)
{
	int i=0;
	while(Copy_pu8inputString[i])
	{
		LCD_DisplayChar(Copy_pu8inputString[i++]);
	}
}

void LCD_SetCursor(u8 Copy_u8Row,u8 Copy_u8Col)
{
	if(Copy_u8Row >= MAX_ROWS || Copy_u8Col >= MAX_COLS)
	{
		//error
	}
	else
	{
		switch(Copy_u8Row)
		{
		case 0: LCD_Send(LCD_ROW_0 + Copy_u8Col,LCD_COMMAND); break;
		case 1: LCD_Send(LCD_ROW_1 + Copy_u8Col,LCD_COMMAND); break;
		case 2: LCD_Send(LCD_ROW_2 + Copy_u8Col,LCD_COMMAND); break;
		case 3: LCD_Send(LCD_ROW_3 + Copy_u8Col,LCD_COMMAND); break;
		}

	}
}

static void LCD_Enable_Pulse()
{
  MDIO_vSetPinVal(EN,DIO_OUTPUT_HIGH);
  _delay_ms(5);
  MDIO_vSetPinVal(EN,DIO_OUTPUT_LOW);
  _delay_ms(1);  
}

void LCD_ShiftLeft(u8 Copy_u8Number)
{
u8 iterator=0;
for(iterator=0;iterator<Copy_u8Number;++iterator)
	{
		LCD_Send(LCD_CURSOR_DISPLAY_3,LCD_COMMAND);

			_delay_ms(350);
	}
}
void LCD_ShiftRight(u8 Copy_u8Number)
{
	u8 iterator=0;
	for(iterator=0;iterator<Copy_u8Number;++iterator)
		{
			LCD_Send(LCD_CURSOR_DISPLAY_4,LCD_COMMAND);

				_delay_ms(350);
		}
}

void LCD_CursorShiftLeft(u8 Copy_u8Number)
{
u8 iterator=0;
for(iterator=0;iterator<Copy_u8Number;++iterator)
	{
		LCD_Send(LCD_CURSOR_DISPLAY_1,LCD_COMMAND);
		_delay_ms(350);
	}
}
void LCD_CursorShiftRight(u8 Copy_u8Number)
{
	int iterator=0;
	for(iterator=0;iterator<Copy_u8Number;++iterator)
		{
			LCD_Send(LCD_CURSOR_DISPLAY_2,LCD_COMMAND);
			_delay_ms(350);
		}

}
void LCD_Clear()
{
	LCD_Send(LCD_CLEAR,LCD_COMMAND);
}


LCD_ErrorStatus LCD_CreateCustomChar(u8* Copy_u8CustomChar,u8 index)
{
	u8 i=0;
	LCD_ErrorStatus Error=LCD_OK;
	LCD_Send(CGRAM_BASE_ADDRESS+index*8,LCD_COMMAND);
	for(i =0;i<8;++i)
		LCD_Send(Copy_u8CustomChar[i],LCD_DATA);

	LCD_Send(DDRAM_BASE_ADDRESS,LCD_COMMAND);

	return Error;
}



/*send lower*/
static LCD_ErrorStatus LCD_SendLowerNibble(u8 Copy_u8input,u8 Copy_u8Type)
{
	 MDIO_vSetPinVal(RS,Copy_u8Type);
    /*Lower nibble */
    MDIO_vSetPinVal(LCD_D7,(Copy_u8input>>3)&1);
    MDIO_vSetPinVal(LCD_D6,(Copy_u8input>>2)&1);
    MDIO_vSetPinVal(LCD_D5,(Copy_u8input>>1)&1);
    MDIO_vSetPinVal(LCD_D4,(Copy_u8input>>0)&1);
    LCD_Enable_Pulse();
    return LCD_OK;
}

static LCD_ErrorStatus LCD_SendHigherNibble(u8 Copy_u8input,u8 Copy_u8Type)
{
	MDIO_vSetPinVal(RS,Copy_u8Type);
    /*Higher nibble */
    MDIO_vSetPinVal(LCD_D7,(Copy_u8input>>7)&1);
    MDIO_vSetPinVal(LCD_D6,(Copy_u8input>>6)&1);
    MDIO_vSetPinVal(LCD_D5,(Copy_u8input>>5)&1);
    MDIO_vSetPinVal(LCD_D4,(Copy_u8input>>4)&1);
    LCD_Enable_Pulse();

    return LCD_OK;
 
}

