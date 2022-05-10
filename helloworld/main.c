/*
 * main.c
 *
 *  Created on: May 10, 2022
 *      Author: Hythm Saad Khalifa
 */
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRA = 15;
	PORTA = 1;
	while(1)
	{
	_delay_ms(1000);
	PORTA=PORTA<<1;
	}
	return 0;
}
