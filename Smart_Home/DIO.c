/*
* DIO.c
*
* Created: 12/19/2020 01:17:41 ص
*  Author: REHAM
*/
#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId, STD_levelTypes level){
	DIO_PortTypes Portx=ChannelId/8;
	DIO_ChannelTypes Channelpos= ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		if(level == STD_High){
			SetBit(PORTA_Reg,Channelpos);
			
		}
		else{
			ClearBit(PORTA_Reg,Channelpos);
		}
		break;
		
		case DIO_PortB:
		if(level == STD_High){
			SetBit(PORTB_Reg,Channelpos);
			
		}
		else{
			ClearBit(PORTB_Reg,Channelpos);
		}
		break;
		
		case DIO_PortC:
		if(level == STD_High){
			SetBit(PORTC_Reg,Channelpos);
			
		}
		else{
			ClearBit(PORTC_Reg,Channelpos);
		}
		break;
		
		case DIO_PortD:
		if(level == STD_High){
			SetBit(PORTD_Reg,Channelpos);
			
		}
		else{
			ClearBit(PORTD_Reg,Channelpos);
		}
		break;
	}
}


STD_levelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx=ChannelId/8;
	DIO_ChannelTypes Channelpos= ChannelId%8;
	STD_levelTypes level =STD_Low;
	switch(Portx){
		case DIO_PortA:
		level= GetBit(PINA_Reg,Channelpos);
		break;
		case DIO_PortB:
		level= GetBit(PINB_Reg,Channelpos);
		break;
		
		case DIO_PortC:
		level= GetBit(PINC_Reg,Channelpos);
		break;
		
		case DIO_PortD:
		level= GetBit(PIND_Reg,Channelpos);
		break;
		
	}
	return level;
}
