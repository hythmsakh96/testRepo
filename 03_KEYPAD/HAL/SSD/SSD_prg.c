/*
 * SSD_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Hythm Saad Khalifa
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/SSD/SSD_cfg.h"
#include "../../HAL/SSD/SSD_int.h"

void SSD_vSSDPortSetup(u8 A_u8PortNo,SSD* S_D)
{
	switch(A_u8PortNo)
	{
	case DIO_PORTA:
		DIO_vSetOutputPort(DIO_PORTA);
		S_D->SSD_PINa = PIN_A_0;
		S_D->SSD_PINb = PIN_A_1;
		S_D->SSD_PINc = PIN_A_2;
		S_D->SSD_PINd = PIN_A_3;
		S_D->SSD_PINe = PIN_A_4;
		S_D->SSD_PINf = PIN_A_5;
		S_D->SSD_PINg = PIN_A_6;
		S_D->SSD_PINh = PIN_A_7;
		break;

	case DIO_PORTB:
		DIO_vSetOutputPort(DIO_PORTB);
		S_D->SSD_PINa = PIN_B_0;
		S_D->SSD_PINb = PIN_B_1;
		S_D->SSD_PINc = PIN_B_2;
		S_D->SSD_PINd = PIN_B_3;
		S_D->SSD_PINe = PIN_B_4;
		S_D->SSD_PINf = PIN_B_5;
		S_D->SSD_PINg = PIN_B_6;
		S_D->SSD_PINh = PIN_B_7;
		break;

	case DIO_PORTC:
		DIO_vSetOutputPort(DIO_PORTC);
		S_D->SSD_PINa = PIN_C_0;
		S_D->SSD_PINb = PIN_C_1;
		S_D->SSD_PINc = PIN_C_2;
		S_D->SSD_PINd = PIN_C_3;
		S_D->SSD_PINe = PIN_C_4;
		S_D->SSD_PINf = PIN_C_5;
		S_D->SSD_PINg = PIN_C_6;
		S_D->SSD_PINh = PIN_C_7;
		break;

	case DIO_PORTD:
		DIO_vSetOutputPort(DIO_PORTD);
		S_D->SSD_PINa = PIN_D_0;
		S_D->SSD_PINb = PIN_D_1;
		S_D->SSD_PINc = PIN_D_2;
		S_D->SSD_PINd = PIN_D_3;
		S_D->SSD_PINe = PIN_D_4;
		S_D->SSD_PINf = PIN_D_5;
		S_D->SSD_PINg = PIN_D_6;
		S_D->SSD_PINh = PIN_D_7;
		break;
	}
}

void SSD_vSSDPinsSetup(u8 A_u8PinN0,u8 A_u8PinN1,u8 A_u8PinN2,u8 A_u8PinN3,u8 A_u8PinN4,u8 A_u8PinN5,u8 A_u8PinN6,u8 A_u8PinN7,SSD* S_D)
{
	S_D->SSD_PINa = A_u8PinN0;
	S_D->SSD_PINb = A_u8PinN1;
	S_D->SSD_PINc = A_u8PinN2;
	S_D->SSD_PINd = A_u8PinN3;
	S_D->SSD_PINe = A_u8PinN4;
	S_D->SSD_PINf = A_u8PinN5;
	S_D->SSD_PINg = A_u8PinN6;
	S_D->SSD_PINh = A_u8PinN7;
}

void SSD_vDisplayNum(u8 A_u8Num, SSD* S_D)
{
	if(A_u8Num<10)
	{
#if SSD_TYPE == COM_CATHODE
		DIO_vPinWrite(S_D.SSD_PINa,(1&(A_u8Num)));
		DIO_vPinWrite(S_D.SSD_PINb,(1&(A_u8Num>>1)));
		DIO_vPinWrite(S_D.SSD_PINc,(1&(A_u8Num>>2)));
		DIO_vPinWrite(S_D.SSD_PINd,(1&(A_u8Num>>3)));
		DIO_vPinWrite(S_D.SSD_PINe,(1&(A_u8Num>>4)));
		DIO_vPinWrite(S_D.SSD_PINf,(1&(A_u8Num>>5)));
		DIO_vPinWrite(S_D.SSD_PINg,(1&(A_u8Num>>6)));
		DIO_vPinWrite(S_D.SSD_PINh,(1&(A_u8Num>>7)));
#elif SSD_TYPE == COM_ANODE //0b00111111
		DIO_vPinWrite(S_D->SSD_PINa,!(1&A_u8Num));//0B00000001&0B00111111=0b00000001=0
		DIO_vPinWrite(S_D->SSD_PINb,!(2&A_u8Num));//0B00000010&0b00111111=0B00000010=0
		DIO_vPinWrite(S_D->SSD_PINc,!(4&A_u8Num));//0B00000100&0b00111111=0B00000100=0
		DIO_vPinWrite(S_D->SSD_PINd,!(8&A_u8Num));//0B00001000&0b00111111=0B00001000=0
		DIO_vPinWrite(S_D->SSD_PINe,!(16&A_u8Num));//0B00010000&0b00111111=0B00010000=0
		DIO_vPinWrite(S_D->SSD_PINf,!(32&A_u8Num));//0B00100000&0b00111111=0B00100000=0
		DIO_vPinWrite(S_D->SSD_PINg,!(64&A_u8Num));//0B01000000&0b00111111=0B00000000=1
		DIO_vPinWrite(S_D->SSD_PINh,!(128&A_u8Num));//0B10000000&0b00111111=0B00000000=1
#endif
	}
}

//void SSD_vTurnOff();
