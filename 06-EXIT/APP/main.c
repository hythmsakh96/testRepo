/*
 * main.c
 *
 *  Created on: May 19, 2022
 *      Author: Hythm Saad Khalifa
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/EXTI/EXTI_prv.h"
#include "../MCAL/GIE/GIE_int.h"
#include <avr/interrupt.h>
ISR(INT0_vect)
{
	MDIO_vTogPinVal(DIO_PORTA,DIO_PIN0);
}

int main(void)
{
	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTD,DIO_PIN2,DIO_HIGH);
	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	MEXTI0_vSenCon(INT0_RISE_EDGE);
	MEXTI0_vIntEN();
	MGIE_vGIEnable();

	while(1)
	{

	}
	return 0;
}

