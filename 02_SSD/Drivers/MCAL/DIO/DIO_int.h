/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_

#define DIO_HIGH_PIN		1
#define DIO_HIGH_PORT		0XFF
#define DIO_LOW			0

#define DIO_PORTA		0xa0
#define DIO_PORTB		0xb0
#define DIO_PORTC		0xc0
#define DIO_PORTD		0xd0

#define PIN_A_0			0xa0
#define PIN_A_1			0xa1
#define PIN_A_2			0xa2
#define PIN_A_3			0xa3
#define PIN_A_4			0xa4
#define PIN_A_5			0xa5
#define PIN_A_6			0xa6
#define PIN_A_7			0xa7

#define PIN_B_0			0xb0
#define PIN_B_1			0xb1
#define PIN_B_2			0xb2
#define PIN_B_3			0xb3
#define PIN_B_4			0xb4
#define PIN_B_5			0xb5
#define PIN_B_6			0xb6
#define PIN_B_7			0xb7

#define PIN_C_0			0xc0
#define PIN_C_1			0xc1
#define PIN_C_2			0xc2
#define PIN_C_3			0xc3
#define PIN_C_4			0xc4
#define PIN_C_5			0xc5
#define PIN_C_6			0xc6
#define PIN_C_7			0xc7

#define PIN_D_0			0xd0
#define PIN_D_1			0xd1
#define PIN_D_2			0xd2
#define PIN_D_3			0xd3
#define PIN_D_4			0xd4
#define PIN_D_5			0xd5
#define PIN_D_6			0xd6
#define PIN_D_7			0xd7


void DIO_vSetInputPin(u8 A_u8PinNo);
void DIO_vSetInputPort(u8 A_u8PortNo);
void DIO_vPinPullUpEN(u8 A_u8PinNo);
void DIO_vPortPullUpEN(u8 A_u8PortNo);
u8 DIO_u8PinRead(u8 A_u8PinNo);
u8 DIO_u8PortRead(u8 A_u8PortNo);
void DIO_vSetOutputPin(u8 A_u8PinNo);
void DIO_vSetOutputPort(u8 A_u8PortNo);
void DIO_vPinWrite(u8 A_u8PinNo,u8 A_u8PinValue);
void DIO_vPortWrite(u8 A_u8PortNo,u8 A_u8PortValue);
#endif /* DIO_DIO_INT_H_ */
