/*
 * KPD_int.h
 *
 *  Created on: Jul 23, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef HAL_KEYPAD_KPD_INT_H_
#define HAL_KEYPAD_KPD_INT_H_

#define NOT_PRESSED 	0
#define PRESSED			1

#define KPD_PORT	DIO_PORTD

u8 KPD_u8GetPressedKey(void);
void KPD_vInit(u8 A_u8PortNo);
u8 KPD_u8GetPressedNum(void);


#endif /* HAL_KEYPAD_KPD_INT_H_ */
