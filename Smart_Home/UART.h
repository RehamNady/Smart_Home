/*
 * UART.h
 *
 * Created: 1/3/2021 02:59:28 م
 *  Author: REHAM
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL

#define BaudRate 9600

#define Douplespeed 0

#if (Douplespeed == 0)
  #define MYUBRR ((F_CPU/(16UL*BaudRate))-1)
#else 
  #define MYUBRR ((F_CPU/(8UL*BaudRate))-1)
#endif

void Uart_Init();
void Uart_TxChar(char data);
char Uart_RxChar();
void Uart_TxString(char *string);



#endif /* UART_H_ */