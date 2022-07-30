/*
 * LCD_cfg.h
 *
 *  Created on: Jul 29, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_


#define LCD_8BIT		1
#define LCD_4BIT		2

#define LCD_MODE		LCD_8BIT

#if 	LCD_MODE == LCD_4BIT

#define LCD_DB4			DIO_PIN0_D
#define LCD_DB5			DIO_PIN1_D
#define LCD_DB6			DIO_PIN2_D
#define LCD_DB7			DIO_PIN3_D

#define LCD_RS_PIN		DIO_PIN5_D
#define LCD_RW_PIN		DIO_PIN4_D
#define LCD_EN_PIN		DIO_PIN6_D

#elif	LCD_MODE == LCD_8BIT

#define LCD_DB0			DIO_PIN0_D
#define LCD_DB1			DIO_PIN1_D
#define LCD_DB2			DIO_PIN2_D
#define LCD_DB3			DIO_PIN3_D
#define LCD_DB4			DIO_PIN4_D
#define LCD_DB5			DIO_PIN5_D
#define LCD_DB6			DIO_PIN6_D
#define LCD_DB7			DIO_PIN7_D

#define LCD_RS_PIN		DIO_PIN2_C
#define LCD_RW_PIN		DIO_PIN1_C
#define LCD_EN_PIN		DIO_PIN0_C


#endif /* HAL_LCD_LCD_CFG_H_ */
#endif
