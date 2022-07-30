/*
 * LCD_prg.c
 *
 *  Created on: May 19, 2022
 *      Author: Hythm Saad Khalifa
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_prv.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include <util/delay.h>


void HLCD_vSendCmd(u8 A_u8Cmd)
{
MDIO_vSetPinVal(LCD_RS_PIN,DIO_OUTPUT_LOW);
MDIO_vSetPinVal(LCD_RW_PIN,DIO_OUTPUT_LOW);
#if LCD_MODE == LCD_4BIT

MDIO_vSetPinVal(LCD_DB4,((A_u8Cmd>>4)&0x01));
MDIO_vSetPinVal(LCD_DB5,((A_u8Cmd>>5)&0x01));
MDIO_vSetPinVal(LCD_DB6,((A_u8Cmd>>6)&0x01));
MDIO_vSetPinVal(LCD_DB7,((A_u8Cmd>>7)&0x01));

MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_HIGH);
_delay_ms(1);
MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_LOW);
_delay_ms(1);

MDIO_vSetPinVal(LCD_DB4,((A_u8Cmd&0x01)>>0));
MDIO_vSetPinVal(LCD_DB5,((A_u8Cmd&0x02)>>1));
MDIO_vSetPinVal(LCD_DB6,((A_u8Cmd&0x03)>>2));
MDIO_vSetPinVal(LCD_DB7,((A_u8Cmd&0x04)>>3));

#elif	LCD_MODE == LCD_8BIT

MDIO_vSetPortVal((0xF0&LCD_DB0),A_u8Cmd);

#endif

MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_HIGH);
_delay_ms(1);
MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_LOW);
_delay_ms(1);
}

void HLCD_vSendChar(u8 A_u8Char)
{

MDIO_vSetPinVal(LCD_RS_PIN,DIO_OUTPUT_HIGH);
MDIO_vSetPinVal(LCD_RW_PIN,DIO_OUTPUT_LOW);
#if LCD_MODE == LCD_4BIT

MDIO_vSetPinVal(LCD_DB4,(((A_u8Char>>4)&0x01)));
MDIO_vSetPinVal(LCD_DB5,(((A_u8Char>>5)&0x01)));
MDIO_vSetPinVal(LCD_DB6,(((A_u8Char>>6)&0x01)));
MDIO_vSetPinVal(LCD_DB7,(((A_u8Char>>7)&0x01)));

MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_HIGH);
_delay_ms(1);
MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_LOW);
_delay_ms(1);

MDIO_vSetPinVal(LCD_DB4,((A_u8Char&0x01)>>0));
MDIO_vSetPinVal(LCD_DB5,((A_u8Char&0x02)>>1));
MDIO_vSetPinVal(LCD_DB6,((A_u8Char&0x03)>>2));
MDIO_vSetPinVal(LCD_DB7,((A_u8Char&0x04)>>3));

#elif	LCD_MODE == LCD_8BIT

MDIO_vSetPortVal((0xF0&LCD_DB0),A_u8Char);

#endif

MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_HIGH);
_delay_ms(1);
MDIO_vSetPinVal(LCD_EN_PIN,DIO_OUTPUT_LOW);
_delay_ms(1);
}

void HLCD_vInit(void)
{
#if LCD_MODE == LCD_4BIT
		MDIO_vSetPinDir(LCD_DB4,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB5,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB6,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB7,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_RS_PIN,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_RW_PIN,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_EN_PIN,DIO_OUTPUT);
		_delay_ms(50);
		HLCD_vSendCmd(0b00000011);//0010		0b DB7 DB6 DB5 DB4 DB7 DB6 DB5 DB4
		_delay_ms(5);
		HLCD_vSendCmd(0b00000011);//0010
		_delay_ms(1);
		HLCD_vSendCmd(0b00000011);//N F X X	(N:0->1 line  1->2 line,F:0-> 5*7  1->5*10)
		HLCD_vSendCmd(0b00000010);//00
		HLCD_vSendCmd(0x28);//1 D C B (D:DISPLAY,C:CURSOR,B:BLINK)
		HLCD_vSendCmd(0x0C);
		HLCD_vSendCmd(0x06);
		HLCD_vSendCmd(0x00);

//		_delay_ms(5);
//		//HLCD_vSendCmd(0b00000000);//0
//		HLCD_vSendCmd(0b00000001);//0001
//		_delay_ms(50);
//		//HLCD_vSendCmd(0b00000000);//0
//		HLCD_vSendCmd(0b00000100);//01 I/D SH(I/D:INCREMENT MODE,SH:SHIFT)
//		_delay_ms(5);

#elif	LCD_MODE == LCD_8BIT
		MDIO_vSetPinDir(LCD_DB0,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB1,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB2,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB3,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB4,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB5,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB6,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_DB7,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_RS_PIN,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_RW_PIN,DIO_OUTPUT);
		MDIO_vSetPinDir(LCD_EN_PIN,DIO_OUTPUT);
		_delay_ms(50);
		HLCD_vSendCmd(0b00111000);
		_delay_ms(5);
		HLCD_vSendCmd(0b00001100);
		_delay_ms(5);
		HLCD_vSendCmd(0b00000001);
		_delay_ms(5);
		HLCD_vSendCmd(0b00000110);
		_delay_ms(5);
#endif
}

void HLCD_vPrintStr(u8 A_u8Str[])
{
	u8 index=0;
	while(A_u8Str[index]!= '\0')
	{
		HLCD_vSendChar(A_u8Str[index]);
		index++;
	}

}
void HLCD_vPrintNum(s32 A_s32Num)
{
	while(A_s32Num>0)
	{
	if(A_s32Num<10)
	{
	HLCD_vSendChar(A_s32Num+'0');
	A_s32Num/=10;
	}
	else
	{
		HLCD_vPrintNum(A_s32Num/10);
		A_s32Num%=10;
	}
}
}
void HLCD_vSetCursorPosition(u8 A_u8LinePos,u8 A_u8LineNum)
{
	if(A_u8LinePos<16)
	{
	if(A_u8LineNum==0)
	{
		HLCD_vSendCmd(0b10000000|(A_u8LinePos));
	}
	else if(A_u8LineNum==1)
	{
		HLCD_vSendCmd((0b10000000|(A_u8LinePos+0x40)));
	}}
}
void HLCD_vClear(void)
{
	HLCD_vSendCmd(1);
}
/*void HLCD_vSaveCusChar(u8 A_u8PatternNum,u8 A_u8Pattern[])
{
	u8 X;
	// set CGRAM Ad
	u8 LOC_Index=0;
	switch(A_u8PatternNum)
	{
	case 0:
		HLCD_vSendCmd(0x40);
		break;
	case 1:
		HLCD_vSendCmd(0x40+8);
		break;
	case 2:
		HLCD_vSendCmd(0x40+16);
		break;
	case 3:
		HLCD_vSendCmd(0x40+24);
		break;
	case 4:
		HLCD_vSendCmd(0x40+32);
		break;
	case 5:
		HLCD_vSendCmd(0x40+40);
		break;
	case 6:
		HLCD_vSendCmd(0x40+48);
		break;
	case 7:
		HLCD_vSendCmd(0x40+56);
		break;
	}
	for(;LOC_Index<8;LOC_Index++)
	{
		HLCD_vSendChar(A_u8Pattern[LOC_Index]);
	}
}*/
//void HLCD_vDispCusChar(/* TODO: to be implemented*/);
