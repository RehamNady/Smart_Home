/*
 * DIO_CFG.h
 *
 * Created: 12/19/2020 01:18:55 ص
 *  Author: REHAM
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO_HW.h"
#include "DIO_Types.h"
#include "STD_Types.h"
#include "BitMath.h"

typedef struct{
	DIO_Dirtypes PinDir;
	STD_levelTypes level;
	
	}DIO_PinGFCType;
	
	#define PINCOUNT 32
	
	void DIO_Init(void);
	




#endif /* DIO_CFG_H_ */