/*
 * SPI.c
 *
 * Created: 1/8/2021 05:10:42 م
 *  Author: REHAM
 */ 
#include "SPI.h"

void SPI_Init(SPI_InitType *InitData){
	switch (InitData->status){
		case Master:
		
		SPI->My_SPCR.AllReg =0x10;
		SPI->My_SPCR.Bits.SSPE =1;
		DDRB|=((1<<SCK)|(1<<MOSI)|(1<<SS));
		DDRB&=~(1<<MISO);
		Slave_Disable ();
		break;
		case Slave:
		
		DDRB |=(1<< MISO);
		DDRB&=~((1<<MOSI)|(1<<SCK)|(1<<SS));
		SPCR=(1<<SPE);
		break;
		
	}
}
unsigned char SPI_TXRX(unsigned char data){
	SPDR =data;
	
	while(SPI->MY_SPSR.SSPIF==0);
	
	return SPDR ;
	
}