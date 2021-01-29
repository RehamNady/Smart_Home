/*
 * SPI.h
 *
 * Created: 1/8/2021 05:10:54 م
 *  Author: REHAM
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7
#define Slave_EN() (PORTB &=~(1<<SS))
#define Slave_Disable() (PORTB |=(1<<SS))

typedef enum{
	Master =0,
	Slave
} SPI_StatusTypes;

typedef enum{
	LSB =0,
	MSB
} SPI_DataTypes;


typedef struct{
	unsigned char SSPR:2;
	unsigned char SCPHA:1;
	unsigned char SCPOL:1;
	unsigned char SSMSTR:1 ;
	unsigned char SSDORD:1;
	unsigned char SSPE:1;
	unsigned char SSPIE:1;

}SPI_SPCRBits;
typedef struct{
	unsigned char SSPI2X:1;
	unsigned char RES:5;
	unsigned char SWCOL:1 ;
	unsigned char SSPIF:1 ;

}SPI_SPSRBits;


typedef union{
	SPI_SPCRBits Bits;
	unsigned char AllReg;
}SPI_SPCRTypes;

typedef struct{
	SPI_SPCRTypes My_SPCR;
	SPI_SPSRBits MY_SPSR;
	unsigned char MY_SPDR;
}SPI_RegTypes;


typedef struct{
	SPI_StatusTypes status;
	SPI_DataTypes DataOrder;
	
	
}SPI_InitType;

#define  SPI ((volatile SPI_RegTypes*)0x2D)
void SPI_Init(SPI_InitType *InitData);
unsigned char SPI_TXRX(unsigned char data);
#endif /* SPI_H_ */