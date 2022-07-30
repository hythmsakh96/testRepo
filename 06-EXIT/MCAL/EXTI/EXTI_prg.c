/*
 * EXIT_prg.c
 *
 *  Created on: Jul 27, 2022
 *      Author: Hythm Saad Khalifa
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "EXTI_cfg.h"
#include "EXTI_int.h"
#include "EXTI_prv.h"

void MEXTI0_vIntEN(void)
{
	SET_BIT(GICR,6);
}

void MEXTI0_vIntDIS(void)
{
	CLR_BIT(GICR,6);
}

void MEXTI0_vSenCon(u8 A_u8SenCon)
{
	MDIO_vSetPinVal(MCUCR, 0, A_u8SenCon&0x01);
	MDIO_vSetPinVal(MCUCR, 1, A_u8SenCon&0x10);
}

void MEXTI1_vIntEN(void)
{
	SET_BIT(GICR,7);
}

void MEXTI1_vIntDIS(void)
{
	CLR_BIT(GICR,7);
}

void MEXTI1_vSenCon(u8 A_u8SenCon)
{
	MDIO_vSetPinVal(MCUCR,2,A_u8SenCon&0x01);
	MDIO_vSetPinVal(MCUCR,3,A_u8SenCon&0x10);
}

void MEXTI2_vIntEN(void)
{
	SET_BIT(GICR,5);
}

void MEXTI2_vIntDIS(void)
{
	CLR_BIT(GICR,5);
}

void MEXTI2_vSenCon(u8 A_u8SenCon)
{
	MDIO_vSetPinVal(MCUCSR,6,A_u8SenCon);
}


