/*
 * BitMath.h
 *
 * Created: 12/18/2020 02:34:47 م
 *  Author: REHAM
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) (Reg|=(1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg&=~(1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg^=(1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)




#endif /* BITMATH_H_ */