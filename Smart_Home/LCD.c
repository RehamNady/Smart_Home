/*
* LCD.c
*
* Created: 12/24/2020 04:21:00 م
*  Author: REHAM
*/

#include "LCD.h"

void LCD_Init(void){
	_delay_ms(20);//more than 15ms
	DIO_WriteChannel(RW,STD_Low);//always write
	LCD_Cmd(0x33);
	_delay_us(150);//more than 100
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);//function set
	LCD_Cmd(0x06);//entrymode
	LCD_Cmd(0x0C);//display
	LCD_Cmd(0x01);//clear lcd
	_delay_ms(2);
}
void LCD_Cmd(Uint8 cmd ){
	// most bit
	LCDDataPort =(LCDDataPort & 0x0F)|(cmd & 0xF0);
	DIO_WriteChannel(RS,STD_Low);//command
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	
	_delay_ms(5);
	
	//least bit
	LCDDataPort =(LCDDataPort & 0x0F)|(cmd<<4);
	DIO_WriteChannel(RS,STD_Low);//command
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(2);
	
}
void LCD_SendChar(Uint8 data ){
	// most bit
	LCDDataPort =(LCDDataPort & 0x0F)|(data & 0xF0);
	DIO_WriteChannel(RS,STD_High);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	
	
	_delay_ms(5);
	
	//least bit
	LCDDataPort =(LCDDataPort & 0x0F)|(data <<4);
	DIO_WriteChannel(RS,STD_High);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(2);
	
	
	
}
void LCD_SendString(Sint8 *string ){
	Uint8 i=0;
	while(string[i]!='\0'){
		
		LCD_SendChar(string[i]);
		i++;
	}
}

void LCD_SendStringpos(Sint8 *string ,Uint8 line, Uint8 pos){
	switch (line){
		case 1:
		LCD_Cmd( (0x80 | (pos & 0x0F)));
		LCD_SendString(string);
		break;
		case 2:
		LCD_Cmd( (0xC0 | (pos & 0x0F)));
		LCD_SendString(string);
		break;
	}
}
void LCD_CustomChar(Uint8 loc,Uint8 *msg){
	if(loc < 8){
		Uint8 i=0;
		LCD_Cmd((0x40 + loc*8));
		for(i=0; i<8; i++){
			LCD_SendChar(msg[i]);
		}
	}
}

void LCD_Clear(){
	LCD_Cmd(0x01);
}