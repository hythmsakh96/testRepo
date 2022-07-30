/*
 * SSD_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef SSD_SSD_INT_H_
#define SSD_SSD_INT_H_

#define SSD_ZERO	(u8)0b00111111
#define SSD_ONE		(u8)0b00000110
#define SSD_TWO		(u8)0b01011011
#define SSD_THREE	(u8)0b01001111
#define SSD_FOUR	(u8)0b01100110
#define SSD_FIVE	(u8)0b01101101
#define SSD_SIX		(u8)0b01111101
#define SSD_SEVEN	(u8)0b00000111
#define SSD_EIGHT	(u8)0b01111111
#define SSD_NINE	(u8)0b01101111


typedef struct{
	u8 SSD_PINa;
	u8 SSD_PINb;
	u8 SSD_PINc;
	u8 SSD_PINd;
	u8 SSD_PINe;
	u8 SSD_PINf;
	u8 SSD_PINg;
	u8 SSD_PINh;
}SSD;



void SSD_vDisplayNum(u8 A_u8Num, SSD* S_D);

void SSD_vSSDPortSetup(u8 A_u8PortNo,SSD* S_D);

void SSD_vSSDPinsSetup(u8 A_u8PinN0,u8 A_u8PinN1,u8 A_u8PinN2,u8 A_u8PinN3,u8 A_u8PinN4,u8 A_u8PinN5,u8 A_u8PinN6,u8 A_u8PinN7,SSD* S_D);

void SSD_vTurnOff();

void SSD_vCountUp();

void SSD_vCountDown();

/**
 *
 */

#endif /* SSD_SSD_INT_H_ */
