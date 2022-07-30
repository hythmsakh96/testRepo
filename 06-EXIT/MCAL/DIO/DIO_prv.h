/*
 * DIO_prv.h
 *
 *  Created on: Jul 12, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef DRIVERS_MCAL_DIO_DIO_PRV_H_
#define DRIVERS_MCAL_DIO_DIO_PRV_H_



#define DDRA		*((volatile u8 *)(0x3A))
#define PORTA		*((volatile u8 *)(0x3B))
#define PINA		*((volatile u8 *)(0x39))

#define DDRB		*((volatile u8 *)(0x37))
#define PORTB		*((volatile u8 *)(0x38))
#define PINB		*((volatile u8 *)(0x36))

#define DDRC		*((volatile u8 *)(0x34))
#define PORTC		*((volatile u8 *)(0x35))
#define PINC		*((volatile u8 *)(0x33))

#define DDRD		*((volatile u8 *)(0x31))
#define PORTD		*((volatile u8 *)(0x32))
#define PIND		*((volatile u8 *)(0x30))


#define conc(b7,b6,b5,b4,b3,b2,b1,b0)			conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 		0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif /* DRIVERS_MCAL_DIO_DIO_PRV_H_ */
