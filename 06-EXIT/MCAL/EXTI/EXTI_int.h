/*
 * EXIT_int.h
 *
 *  Created on: Jul 27, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

void MEXTI0_vIntEN(void);
void MEXTI0_vIntDIS(void);
/**
 * INTO Modes:
 * 				1-INT0_LOW_LEVEL
 * 				2-INT0_ON_CHANGE
 * 				3-INT0_FaLL_EDGE
 * 				4-INT0_RISE_EDGE
 */
void MEXTI0_vSenCon(u8 A_u8SenCon);

void MEXTI1_vIntEN(void);
void MEXTI1_vIntDIS(void);
/**
 * INT1 Modes:
 * 				1-INT1_LOW_LEVEL
 * 				2-INT1_ON_CHANGE
 * 				3-INT1_FaLL_EDGE
 * 				4-INT1_RISE_EDGE
 */
void MEXTI1_vSenCon(u8 A_u8SenCon);

void MEXTI2_vIntEN(void);
void MEXTI2_vIntDIS(void);
/**
 * INT2 Modes:
 * 				1-INT2_FaLL_EDGE
 * 				2-INT2_RISE_EDGE
 */
void MEXTI2_vSenCon(u8 A_u8SenCon);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
