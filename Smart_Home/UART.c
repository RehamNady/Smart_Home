/*
 * UART.c
 *
 * Created: 1/3/2021 02:59:04 م
 *  Author: REHAM
 */ 
#include "UART.h"
#include "BitMath.h"

void Uart_Init(){
	SetBit(UCSRB,RXEN);
	SetBit(UCSRB,TXEN);
	SetBit(UCSRC,URSEL);
	SetBit(UCSRC,UCSZ0);
	SetBit(UCSRC,UCSZ1);
	UBRRL = (char)MYUBRR; 
	UBRRH = (char)(MYUBRR>>8); 
}
void Uart_TxChar(char data){
	
	while(((UCSRA >> UDRE)&1)==0);
	UDR = data ;
}
char Uart_RxChar(){
	while(!(UCSRA>>RXC)&1);
	return UDR ; 
}
void Uart_TxString(char *string){
	unsigned char i=0;
	while (string[i] !='\0'){
		Uart_TxChar(string [i]);
		i++;
	}
	
	
}
