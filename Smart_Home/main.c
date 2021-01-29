/*
 * SPI_SLAVE.c
 *
 * Created: 1/8/2021 06:04:35 م
 * Author : REHAM
 */ 

#include "SPI.h"
#include "UART.h"
#include "keypad.h"

#include <avr/interrupt.h>
#include <stdlib.h>

#define F_CPU 16000000UL 
#include <util/delay.h>

volatile Uint8 data_ch;
char array[3];
int i=0;
int T1=80;

void clear_array(char *array);
int set_T1();


int main(void)
{
	Uint8 data_send=0xAA;
	Uint8 data_rec;
	
	char string[10];
	char string2[10];
	
	DIO_Init();
	LCD_Init();
	KeyPad_Init();
	Uart_Init();
	
	GICR|=(1<<INT0);
	MCUCR|=(1<<ISC01);
	MCUCR&=~(1<<ISC00);
	
    SPI_InitType InitData ={Master,MSB};
    SPI_Init(&InitData);
    Slave_EN();
	
    sei();
	
   
    while (1) 
    {

	    _delay_ms(400);
	    LCD_Clear();
		if (GetBit(UCSRA,RXC) ==1){
			data_send=UDR;
			
			}
				
		data_rec=SPI_TXRX(data_send);
		itoa(data_rec,string,10);
		itoa(T1,string2,10);
		LCD_SendStringpos("1_setR1=",1,0);
		LCD_SendStringpos(string2,1,9);
		LCD_SendStringpos("T_R1=",2,0);
		LCD_SendStringpos(string,2,5);
		
		if (data_rec >T1)
		{
			data_send='W';
			DIO_WriteChannel(DIO_ChannelA0,STD_High);
			DIO_WriteChannel(DIO_ChannelA1,STD_High);
	
		}
		else {
		data_send=0xAA;
		DIO_WriteChannel(DIO_ChannelA0,STD_Low);
		DIO_WriteChannel(DIO_ChannelA1,STD_Low);
		}
		
		
}
}
ISR(INT0_vect){
	data_ch=checkR2();
	if(data_ch =='1'){
		LCD_Clear();
		T1=set_T1();
	}
	
}

int set_T1(){
	LCD_Clear();
	int T1;
	Uint8 key;
	data_ch=0xFF;
	GICR&=~(1<<INT0);
	while(1){
		key=GetKey();
		if((key!=0xFF)&(key!='=')){
			array[i]=key;
			LCD_SendChar(key);
			i++;
		}
		if(key=='='){
 			T1=atoi(array);
			LCD_Clear();
			data_ch=checkR2();
			i=0;
			clear_array(array);
			GICR|=(1<<INT0);
			break;
		}
		if(key == 0xFF){
			continue;
		}
		
	}
	return T1;
}

void clear_array(char *array){
	int k=0;
	for(k=0 ; k<= 3 ; k++){
		array[k]='\0' ;
	}
}
