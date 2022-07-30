/*
 * DIO_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Hythm Saad Khalifa
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"

#define DIO_LOW		0
#define DIO_HIGH	1

void DIO_vSetInputPin(u8 A_u8PinNo)
{
	switch(0xF0&A_u8PinNo)
	{
	case DIO_PORTA:
		CLR_BIT(DDRA,0x0F&A_u8PinNo);
		CLR_BIT(PORTA,0x0F&A_u8PinNo);
		break;
	case DIO_PORTB:
		CLR_BIT(DDRB,0x0F&A_u8PinNo);
		CLR_BIT(PORTB,0x0F&A_u8PinNo);
		break;
	case DIO_PORTC:
		CLR_BIT(DDRC,0x0F&A_u8PinNo);
		CLR_BIT(PORTC,0x0F&A_u8PinNo);
		break;
	case DIO_PORTD:
		CLR_BIT(DDRD,0x0F&A_u8PinNo);
		CLR_BIT(PORTD,0x0F&A_u8PinNo);
		break;
	}
}

void DIO_vSetInputPort(u8 A_u8PortNo)
{
	switch(0xF0&A_u8PortNo)
	{
	case DIO_PORTA:
		DDRA=0;
		PORTA=0;
		break;
	case DIO_PORTB:
		DDRB =0;
		PORTB=0;
		break;
	case DIO_PORTC:
		DDRC=0;
		PORTC=0;
		break;
	case DIO_PORTD:
		DDRD=0;
		PORTD=0;
		break;
	}
}

void DIO_vPinPullUpEN(u8 A_u8PinNo)
{
	switch(0xF0&A_u8PinNo)
	{
	case DIO_PORTA:
		SET_BIT(PORTA,0x0F&A_u8PinNo);
		break;
	case DIO_PORTB:
		SET_BIT(PORTB,0x0F&A_u8PinNo);
		break;
	case DIO_PORTC:
		SET_BIT(PORTC,0x0F&A_u8PinNo);
		break;
	case DIO_PORTD:
		SET_BIT(PORTD,0x0F&A_u8PinNo);
		break;
	}
}

void DIO_vPortPullUpEN(u8 A_u8PortNo)
{
	switch(0xF0&A_u8PortNo)
	{
	case DIO_PORTA:
		PORTA=0xFF;
		break;
	case DIO_PORTB:
		PORTB=0xFF;
		break;
	case DIO_PORTC:
		PORTC=0xFF;
		break;
	case DIO_PORTD:
		PORTD=0xFF;
		break;
	}
}
u8 DIO_u8PinRead(u8 A_u8PinNo)
{
	u8 ReturnValue=0;
	switch(0xF0&A_u8PinNo)
		{
		case DIO_PORTA:
			ReturnValue = GET_BIT(PINA,0x0F&A_u8PinNo);
			break;
		case DIO_PORTB:
			ReturnValue = GET_BIT(PINB,0x0F&A_u8PinNo);
			break;
		case DIO_PORTC:
			ReturnValue = GET_BIT(PINC,0x0F&A_u8PinNo);
			break;
		case DIO_PORTD:
			ReturnValue = GET_BIT(PIND,0x0F&A_u8PinNo);
			break;
		}
	return ReturnValue;
}

u8 DIO_u8PortRead(u8 A_u8PortNo)
{
	u8 ReturnValue=0;
	switch(0xF0&A_u8PortNo)
		{
		case DIO_PORTA:
			ReturnValue = PINA;
			break;
		case DIO_PORTB:
			ReturnValue = PINB;
			break;
		case DIO_PORTC:
			ReturnValue = PINC;
			break;
		case DIO_PORTD:
			ReturnValue = PIND;
			break;
		}
	return ReturnValue;
}

void DIO_vSetOutputPin(u8 A_u8PinNo)
{
	switch(0xF0&A_u8PinNo)
	{
	case DIO_PORTA:
		SET_BIT(DDRA,0x0F&A_u8PinNo);
		CLR_BIT(PORTA,0x0F&A_u8PinNo);
		break;
	case DIO_PORTB:
		SET_BIT(DDRB,0x0F&A_u8PinNo);
		CLR_BIT(PORTB,0x0F&A_u8PinNo);
		break;
	case DIO_PORTC:
		SET_BIT(DDRC,0x0F&A_u8PinNo);
		CLR_BIT(PORTC,0x0F&A_u8PinNo);
		break;
	case DIO_PORTD:
		SET_BIT(DDRD,0x0F&A_u8PinNo);
		CLR_BIT(PORTD,0x0F&A_u8PinNo);
		break;
	}
}

void DIO_vSetOutputPort(u8 A_u8PortNo)
{
	switch(0xF0&A_u8PortNo)
	{
	case DIO_PORTA:
		DDRA = 0xFF;
		PORTA=0;
		break;
	case DIO_PORTB:
		DDRB = 0xFF;
		PORTB=0;
		break;
	case DIO_PORTC:
		DDRC = 0xFF;
		PORTC=0;
		break;
	case DIO_PORTD:
		DDRD = 0xFF;
		PORTD=0;
		break;
	}
}

void DIO_vPortWrite(u8 A_u8PortNo,u8 A_u8PortValue)
{
	switch(0xF0&A_u8PortNo)
		{
		case DIO_PORTA:
			PORTA=A_u8PortValue;
			break;
		case DIO_PORTB:
			PORTB=A_u8PortValue;
			break;
		case DIO_PORTC:
			PORTC=A_u8PortValue;
			break;
		case DIO_PORTD:
			PORTD=A_u8PortValue;
			break;
		}
}

void DIO_vPinWrite(u8 A_u8PinNo,u8 A_u8PinValue)
{
	if(A_u8PinValue == DIO_LOW)
	{
	switch(0xF0&A_u8PinNo)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA,0x0F&A_u8PinNo);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB,0x0F&A_u8PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC,0x0F&A_u8PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD,0x0F&A_u8PinNo);
			break;
		}
	}
	else
	{
		switch(0xF0&A_u8PinNo)
			{
			case DIO_PORTA:
				SET_BIT(PORTA,0x0F&A_u8PinNo);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB,0x0F&A_u8PinNo);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC,0x0F&A_u8PinNo);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD,0x0F&A_u8PinNo);
				break;
			}
	}
}
