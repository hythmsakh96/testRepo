/*
 * main.c
 *
 *  Created on: May 19, 2022
 *      Author: Hythm Saad Khalifa
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include <util/delay.h>
int main(void)
{
	u8 ADC_MAP=0;
	MDIO_vSetPortDir(DIO_PORTC,0XFF);
	MADC_vInit();
	u16 ADC_V=0;

	while(1)
	{
		ADC_V = MADC_u16AnalRead(ADC_CH0);
		ADC_MAP = ADC_V/4;
		MDIO_vSetPortVal(DIO_PORTC,ADC_MAP);


	}
	return 0;
}

