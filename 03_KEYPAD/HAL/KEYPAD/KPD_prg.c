/*
 * KPD_prg.c
 *
 *  Created on: Jul 23, 2022
 *      Author: Hythm Saad Khalifa
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"
#include "KPD_cfg.h"
#include "KPD_int.h"

void KPD_vInit(u8 A_u8PortNo)
{
	DIO_vSetPinDir(KPD_PORT,DIO_PIN0,DIO_OUTPUT);
	DIO_vSetPinDir(KPD_PORT,DIO_PIN1,DIO_OUTPUT);
	DIO_vSetPinDir(KPD_PORT,DIO_PIN2,DIO_OUTPUT);
	DIO_vSetPinDir(KPD_PORT,DIO_PIN3,DIO_OUTPUT);

	DIO_vSetPinVal(KPD_PORT,DIO_PIN0,DIO_HIGH);
	DIO_vSetPinVal(KPD_PORT,DIO_PIN1,DIO_HIGH);
	DIO_vSetPinVal(KPD_PORT,DIO_PIN2,DIO_HIGH);
	DIO_vSetPinVal(KPD_PORT,DIO_PIN3,DIO_HIGH);

	DIO_vSetPinDir(KPD_PORT,DIO_PIN4,DIO_INPUT);
	DIO_vSetPinDir(KPD_PORT,DIO_PIN5,DIO_INPUT);
	DIO_vSetPinDir(KPD_PORT,DIO_PIN6,DIO_INPUT);
	DIO_vSetPinDir(KPD_PORT,DIO_PIN7,DIO_INPUT);

	DIO_vSetPinVal(KPD_PORT,DIO_PIN4,DIO_HIGH);
	DIO_vSetPinVal(KPD_PORT,DIO_PIN5,DIO_HIGH);
	DIO_vSetPinVal(KPD_PORT,DIO_PIN6,DIO_HIGH);
	DIO_vSetPinVal(KPD_PORT,DIO_PIN7,DIO_HIGH);
}
u8 KPD_u8GetPressedKey(void){

  u8 LOC_u8Column=0;

  u8 LOC_u8Row=0;

  /* Initialize the switch status to NOT Pressed                                                                     */
  u8 LOC_u8Retrun = NOT_PRESSED;

  /* Looping on columns of the Key Pad                                                                               */
 // while(!LOC_u8Retrun)
  //{
  for (LOC_u8Column = 0; LOC_u8Column < 4; LOC_u8Column++)
  {
    /* Activate the Column                                                                                           */
    DIO_vSetPinVal(KPD_PORT, LOC_u8Column, DIO_LOW);

    /* Loop on the rows of the Key Pad                                                                               */
    for (LOC_u8Row =0; LOC_u8Row < 4; LOC_u8Row++)
    {
      /* Check the status of the switch                                                                              */
      if (!DIO_u8GetPintVal(KPD_PORT, LOC_u8Row+4))
      {
        /* Get the value of the currently pressed switch                                                             */
        LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column][LOC_u8Row];

        /* Wait until the switch is released (Single Press)                                                          */
        while (!DIO_u8GetPintVal(KPD_PORT, LOC_u8Row+4));

        /* Delay to avoid bouncing                                                                                   */
        _delay_ms(20);
      }
    }

    /* Deactivate the Column                                                                                         */
    DIO_vSetPinVal(KPD_PORT, LOC_u8Column, DIO_HIGH);
  }
  //}
  return LOC_u8Retrun;
}
u8 KPD_u8GetPressedNum(void){
	u8 LOC_VAL=0;
	u8 Result=0;
	while(LOC_VAL!='=')
	{
		Result = LOC_VAL*10 -'0' +KPD_u8GetPressedKey();
	}
	return Result;
}



