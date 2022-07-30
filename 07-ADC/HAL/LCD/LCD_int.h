/*
 * LCD_int.h
 *
 *  Created on: May 19, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_
/*
*//* LCD_CTRL_PORT
*//* LCD_DATA_PORT
*//*
*//* LCD_RS_PIN
*//* LCD_RW_PIN
*//* LCD_EN_PIN
*/
void HLCD_vSendCmd(u8 A_u8Cmd);
void HLCD_vSendChar(u8 A_u8Cmd);
void HLCD_vInit(void);
void HLCD_vPrintStr(u8 A_u8Str[]);
void HLCD_vPrintNum(s32 A_s32Num);
void HLCD_vSetCursorPosition(u8 A_u8LinePos,u8 A_u8LineNum);
void HLCD_vClear(void);
//void HLCD_vSaveCusChar(u8 A_u8PatternNum,u8 A_u8Pattern[]);
//void HLCD_vDispCusChar(/* TODO: to be implemented*/);

#endif /* LCD_LCD_INT_H_ */
