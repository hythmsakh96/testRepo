/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_
#define DIO_OUTPUT 1
#define DIO_INPUT  0

#define DIO_INPUT_FLOATING 0
#define DIO_INPUT_PULLUP   1

#define DIO_OUTPUT_HIGH 1
#define DIO_OUTPUT_LOW  0

#define DIO_PORTA		0xA0
#define DIO_PORTB 		0xB0
#define DIO_PORTC 		0xC0
#define DIO_PORTD 		0xD0

#define DIO_PIN0_A		0xA0
#define DIO_PIN1_A		0xA1
#define DIO_PIN2_A		0xA2
#define DIO_PIN3_A		0xA3
#define DIO_PIN4_A		0xA4
#define DIO_PIN5_A		0xA5
#define DIO_PIN6_A		0xA6
#define DIO_PIN7_A		0xA7

#define DIO_PIN0_B	    0xB0
#define DIO_PIN1_B	    0xB1
#define DIO_PIN2_B	    0xB2
#define DIO_PIN3_B	    0xB3
#define DIO_PIN4_B	    0xB4
#define DIO_PIN5_B	    0xB5
#define DIO_PIN6_B	    0xB6
#define DIO_PIN7_B	    0xB7

#define DIO_PIN0_C	    0xC0
#define DIO_PIN1_C	    0xC1
#define DIO_PIN2_C	    0xC2
#define DIO_PIN3_C	    0xC3
#define DIO_PIN4_C	    0xC4
#define DIO_PIN5_C	    0xC5
#define DIO_PIN6_C	    0xC6
#define DIO_PIN7_C	    0xC7

#define DIO_PIN0_D	    0xD0
#define DIO_PIN1_D	    0xD1
#define DIO_PIN2_D	    0xD2
#define DIO_PIN3_D	    0xD3
#define DIO_PIN4_D	    0xD4
#define DIO_PIN5_D	    0xD5
#define DIO_PIN6_D	    0xD6
#define DIO_PIN7_D	    0xD7

/*	PIN DIRECTION:
*//*1-        DIO_OUTPUT
*//*2-        DIO_INPUT
*//*
*//*INPUT MODE:
*//*        DIO_INPUT_FLOATING
*//*        DIO_INPUT_PULLUP
*//*
*//*OUTPUT STATE
*//*        DIO_OUTPUT_HIGH
*//*        DIO_OUTPUT_LOW
*//*
*//*PORTS
*//*        DIO_PORTA
*//*        DIO_PORTB
*//*        DIO_PORTC
*//*        DIO_PORTD
*//*
*//*PINS
*//*        DIO_PIN0_A
*//*        DIO_PIN1_A
*//*        DIO_PIN2_A
*//*        DIO_PIN3_A
*//*        DIO_PIN4_A
*//*        DIO_PIN5_A
*//*        DIO_PIN6_A
*//*        DIO_PIN7_A
*//*
*//*        DIO_PIN0_B
*//*        DIO_PIN1_B
*//*        DIO_PIN2_B
*//*        DIO_PIN3_B
*//*        DIO_PIN4_B
*//*        DIO_PIN5_B
*//*        DIO_PIN6_B
*//*        DIO_PIN7_B
*//*
*//*        DIO_PIN0_C
*//*        DIO_PIN1_C
*//*        DIO_PIN2_C
*//*        DIO_PIN3_C
*//*        DIO_PIN4_C
*//*        DIO_PIN5_C
*//*        DIO_PIN6_C
*//*        DIO_PIN7_C
*//*
*//*        DIO_PIN0_D
*//*        DIO_PIN1_D
*//*        DIO_PIN2_D
*//*        DIO_PIN3_D
*//*        DIO_PIN4_D
*//*        DIO_PIN5_D
*//*        DIO_PIN6_D
*//*        DIO_PIN7_D
*/

void MDIO_vSetPinDir(u8 A_u8PinNo,u8 A_u8Dir);
void MDIO_vSetPinVal(u8 A_u8PinNo,u8 A_u8Val);
void MDIO_vSetPortDir(u8 A_u8PortNo,u8 A_u8Dir);
void MDIO_vSetPortVal(u8 A_u8PortNo,u8 A_u8Dir);
void MDIO_vTogPinVal(u8 A_u8PinNo);
u8 MDIO_u8GetPortVal(u8 A_u8PortNo);
u8 MDIO_u8GetPintVal(u8 A_u8PinNo);
#endif /* DIO_DIO_INT_H_ */
