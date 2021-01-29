/*
 * LCD.h
 *
 * Created: 12/24/2020 04:21:17 م
 *  Author: REHAM
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "DIO_CFG.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCDDataPort PORTA_Reg 
#define RS DIO_ChannelB1
#define RW DIO_ChannelB2
#define E DIO_ChannelB3

void LCD_Init(void);
void LCD_Cmd(Uint8 cmd );
void LCD_SendChar(Uint8 data);
void LCD_SendString(Sint8 *string );
void LCD_SendStringpos(Sint8 *string ,Uint8 line, Uint8 pos);
void LCD_CustomChar(Uint8 location,Uint8 *msg);
void LCD_Clear();




#endif /* LCD_H_ */