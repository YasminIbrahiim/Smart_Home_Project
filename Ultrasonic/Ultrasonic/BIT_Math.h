/********************************************/
/* Description : bit manipulation STD lib   */
/* Author      : Ahmed abo elnour           */
/* Date        : 17/8/2022    V0.1          */
/* Version     : 0.1V   Initial Creation    */
/********************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg , BitNum)   (Reg) |= (1<<(BitNum))  
#define CLR_BIT(Reg , BitNum)   (Reg) &=~(1<<(BitNum))
#define TGL_BIT(Reg , BitNum)   (Reg) ^= (1<<(BitNum))
#define GET_BIT(Reg , BitNum)   (((Reg) >> (BitNum))&0x01)
#endif


