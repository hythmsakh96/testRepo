/*
 * GIE_prg.c
 *
 *  Created on: Jul 28, 2022
 *      Author: Hythm Saad Khalifa
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_prv.h"
#include "GIE_cfg.h"
#include "GIE_int.h"

void MGIE_vGIEnable(void)
{
	SET_BIT(SREG,7);
}

void MGIE_vGIDisable(void)
{
	CLR_BIT(SREG,7);
}
