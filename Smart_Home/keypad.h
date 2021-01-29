/*
 * keypad.h
 *
 * Created: 12/12/2020 03:43:09 م
 *  Author: REHAM
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "LCD.h"


#define C0 DIO_ChannelD2 
#define C1 DIO_ChannelD3 
#define C2 DIO_ChannelC2 
#define C3 DIO_ChannelC3 
#define R0 DIO_ChannelC4 
#define R1 DIO_ChannelC5 
#define R2 DIO_ChannelC6 
#define R3 DIO_ChannelC7 


void KeyPad_Init();

Uint8 checkR0();
Uint8 checkR1();
Uint8 checkR2();
Uint8 checkR3();
Uint8 GetKey();



	

#endif


 