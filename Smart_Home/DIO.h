/*
 * DIO.h
 *
 * Created: 12/19/2020 01:17:14 ص
 *  Author: REHAM
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "STD_Types.h"
#include "BitMath.h"


void DIO_WriteChannel(DIO_ChannelTypes ChannelId, STD_levelTypes level);
STD_levelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId);




#endif /* DIO_H_ */