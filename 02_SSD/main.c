/*
 * maBin.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Hythm Saad Khalifa
 */
#include "Drivers/LIB/STD_TYPES.h"
#include "Drivers/LIB/BIT_MATH.h"
#include "Drivers/MCAL/DIO/DIO_int.h"
#include "Drivers/HAL/SSD/SSD_int.h"

#include <util/delay.h>

int main(void)
{
	SSD A;
	SSD_vSSDPortSetup(DIO_PORTC,&A);
	while(1)
	{
SSD_vDisplayNum(25,&A);
//DIO_vPinWrite(B->SSD_PINa,!(1&  SSD_NINE));
//DIO_vPinWrite(B->SSD_PINb,!(2&  SSD_NINE));
//DIO_vPinWrite(B->SSD_PINc,!(4&  SSD_NINE));
//DIO_vPinWrite(B->SSD_PINd,!(8&  SSD_NINE));
//DIO_vPinWrite(B->SSD_PINe,!(16& SSD_NINE));
//DIO_vPinWrite(B->SSD_PINf,!(32& SSD_NINE));
//DIO_vPinWrite(B->SSD_PINg,!(64& SSD_NINE));
//DIO_vPinWrite(B->SSD_PINh,!(128&SSD_NINE));
	}
	return 0;
}

