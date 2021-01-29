/*
* keypad.c
*
* Created: 12/12/2020 03:42:46 م
*  Author: REHAM
*/
# include "keypad.h"


void KeyPad_Init(){
	DIO_WriteChannel(C0,STD_High);
	DIO_WriteChannel(C1,STD_High);
	DIO_WriteChannel(C2,STD_High);
	DIO_WriteChannel(C3,STD_High);
	
}

Uint8 checkR0()
{
	Uint8 data=0xFF;
	DIO_WriteChannel(R3,STD_High);
	DIO_WriteChannel(R0,STD_Low);
	DIO_WriteChannel(R1,STD_High);
	DIO_WriteChannel(R2,STD_High);

	if(DIO_ReadChannel(C0)== STD_Low){
		data='7';
		while(DIO_ReadChannel(C0)==STD_Low);
	}
	
	if(DIO_ReadChannel(C1)==STD_Low){
		data='8';
		while(DIO_ReadChannel(C1)==STD_Low);
	}
	
	if(DIO_ReadChannel(C2)==STD_Low){	
		data='9';
		while(DIO_ReadChannel(C2)==STD_Low);
	}
	
	if(DIO_ReadChannel(C3)==STD_Low){	
		data='/';
		while(DIO_ReadChannel(C3)==STD_Low);
	}
	
	return data;
}
Uint8 checkR1(){
	Uint8 data1=0xFF;
	DIO_WriteChannel(R0,STD_High);
	DIO_WriteChannel(R1,STD_Low);
	DIO_WriteChannel(R2,STD_High);
	DIO_WriteChannel(R3,STD_High);
	
	if(DIO_ReadChannel(C0)== STD_Low){
		data1='4';
		while(DIO_ReadChannel(C0)==STD_Low);
	}
	
	if(DIO_ReadChannel(C1)==STD_Low){
		data1='5';
		while(DIO_ReadChannel(C1)==STD_Low);
	}
	
	if(DIO_ReadChannel(C2)==STD_Low){
		data1='6';
		while(DIO_ReadChannel(C2)==STD_Low);
	}
	
	if(DIO_ReadChannel(C3)==STD_Low){
		data1='*';
		while(DIO_ReadChannel(C3)==STD_Low);
	}
	
	return data1;
}
Uint8 checkR2(){
	Uint8 data2=0xFF;
	DIO_WriteChannel(R0,STD_High);
	DIO_WriteChannel(R1,STD_High);
	DIO_WriteChannel(R2,STD_Low);
	DIO_WriteChannel(R3,STD_High);
	
	if(DIO_ReadChannel(C0)== STD_Low){
		data2='1';
		while(DIO_ReadChannel(C0)==STD_Low);
	}
	
	if(DIO_ReadChannel(C1)==STD_Low){
		data2='2';
		while(DIO_ReadChannel(C1)==STD_Low);
	}
	
	if(DIO_ReadChannel(C2)==STD_Low){
		data2='3';
		while(DIO_ReadChannel(C2)==STD_Low);	
	}
	
	if(DIO_ReadChannel(C3)==STD_Low){	
		data2='-';
		while(DIO_ReadChannel(C3)==STD_Low);
	}
	
	return data2;
}
Uint8 checkR3(){
	Uint8 data3=0xFF;
	DIO_WriteChannel(R0,STD_High);
	DIO_WriteChannel(R1,STD_High);
	DIO_WriteChannel(R2,STD_High);
	DIO_WriteChannel(R3,STD_Low);
	
	if(DIO_ReadChannel(C0)== STD_Low){
		LCD_Clear();
		data3='\0';
		while(DIO_ReadChannel(C0)==STD_Low);
	}
	
	if(DIO_ReadChannel(C1)==STD_Low){
		data3='0';
		while(DIO_ReadChannel(C1)==STD_Low);
	}
	
	if(DIO_ReadChannel(C2)==STD_Low){
		data3='=';
		while(DIO_ReadChannel(C2)==STD_Low);
	}
	
	if(DIO_ReadChannel(C3)==STD_Low){
		data3='+';
		while(DIO_ReadChannel(C3)==STD_Low);
	}
	
	return data3;
}

Uint8 GetKey(){
	Uint8 Rdat=0XFF;
	
	Rdat=checkR0();
	if (Rdat == 0XFF){
		Rdat=checkR1();
		if (Rdat == 0XFF){
			Rdat=checkR2();
			if (Rdat ==0XFF){
			Rdat=checkR3();}
		}
	}
		return Rdat;
	

}