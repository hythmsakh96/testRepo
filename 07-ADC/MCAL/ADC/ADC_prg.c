/*
 * ADC_prg.c
 *
 *  Created on: Jul 28, 2022
 *      Author: Hythm Saad Khalifa
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_int.h"

void MADC_vInit(void)
{
	/*1- Reference Voltage Section*/
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	/*2- Data Adjustment Direction*/
	CLR_BIT(ADMUX, 5);
	/*3- Select Prescalar bits*/
	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRE_SC_2);
	/*4- Select Enable*/
	/*	4a- Auto Trigger Source*/
	CLR_BIT(ADCSRA,5);
	/*5- Interrupt En/Dis*/
	CLR_BIT(ADCSRA,3);
	/*6- Enable ADC*/
	SET_BIT(ADCSRA,7);
}
u16  MADC_u16AnalRead(A_u8ChannelNo)
{
	/*1- Select Channel	*/
	ADMUX = (ADMUX & 0xE8)	|	(A_u8ChannelNo);
	/*2- Start Conversion*/
	SET_BIT(ADCSRA,6);
	/*3- Poll on Flag*/
	while(GET_BIT(ADCSRA,4)!=1);
	/*4- Clear Flag*/
	SET_BIT(ADCSRA,4);
	/*5- Return ADC Value*/
	return ADC;
}

