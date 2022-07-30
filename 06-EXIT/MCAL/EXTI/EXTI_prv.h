/*
 * EXIT_prv.h
 *
 *  Created on: Jul 27, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define MCUCR		*((volatile u8*)(0x55))
#define MCUCSR		*((volatile u8*)(0x54))
#define GICR		*((volatile u8*)(0x5B))
#define GIFR		*((volatile u8*)(0x5A))

#define INT0_LOW_LEVEL	0x00
#define INT0_ON_CHANGE	0x01
#define INT0_FALL_EDGE	0x10
#define INT0_RISE_EDGE	0x11

#define INT1_LOW_LEVEL	0x00
#define INT1_ON_CHANGE	0x01
#define INT1_FALL_EDGE	0x10
#define INT1_RISE_EDGE	0x11

#define	INT2_FALL_EDGE	0
#define INT2_RISE_EDGE	1


#endif /* MCAL_EXTI_EXTI_PRV_H_ */
