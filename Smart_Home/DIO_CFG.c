/*
* DIO_CFG.c
*
* Created: 12/19/2020 01:18:20 ص
*  Author: REHAM
*/

#include "DIO_CFG.h"

const DIO_PinGFCType PinGFC[]={
	//portA
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	
	//portB
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	//portC
	{output,STD_High},
	{input,STD_Low},
	{input,STD_Low},
	{input,STD_Low},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	//portD
	{output,STD_High},
	{output,STD_High},
	{input, STD_Low },
	{input,STD_Low},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	{output,STD_High},
	
};

void DIO_Init(){
	DIO_PortTypes Portx;
	DIO_ChannelTypes Channelpos;
	Uint8 count =0;
	for(count=DIO_ChannelA0;count<PINCOUNT;count++){
		Portx=count/8;
		Channelpos=count%8;
		switch(Portx){
			case DIO_PortA:
			if(PinGFC[count].PinDir== output){
				SetBit(DDRA_Reg,Channelpos);
				
			}
			else{
				ClearBit(DDRA_Reg,Channelpos);
				
			}
			break;
			
			case DIO_PortB:
			if(PinGFC[count].PinDir== output){
				SetBit(DDRB_Reg,Channelpos);
				
			}
			else{
				ClearBit(DDRB_Reg,Channelpos);
				
			}
			break;
			case DIO_PortC:
			if(PinGFC[count].PinDir== output){
				SetBit(DDRC_Reg,Channelpos);
				
			}
			else{
				ClearBit(DDRC_Reg,Channelpos);
				
			}
			break;
			case DIO_PortD:
			if(PinGFC[count].PinDir== output){
				SetBit(DDRD_Reg,Channelpos);
				
			}
			else{
				ClearBit(DDRD_Reg,Channelpos);
				
			}
			break;
		}
		
	}
	
	
	
}