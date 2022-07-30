#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/********************************* CHOOSE LCD Mode&size ***********************************************/
	#define LCD_MODE  			LCD_4BIT_MODE
	#define LCD_SIZE  			LCD_2X16
/********************************* SELECT LCD DATA PINS OR PORT ***************************************/
	#if 	LCD_MODE==LCD_8BIT_MODE
	#define LCD_PORT			GPIO_A

	#elif   LCD_MODE==LCD_4BIT_MODE
	#define LCD_D4  				DIO_PIN0_D
	#define LCD_D5  				DIO_PIN1_D
	#define LCD_D6  				DIO_PIN2_D
	#define LCD_D7  				DIO_PIN3_D
	#endif
  
  
/********************************* SELECT CONTROL PINS ************************************************/
	
  	#define RS    				DIO_PIN4_D
	#define RW   			 	DIO_PIN5_D
	#define EN    				DIO_PIN6_D


#endif
