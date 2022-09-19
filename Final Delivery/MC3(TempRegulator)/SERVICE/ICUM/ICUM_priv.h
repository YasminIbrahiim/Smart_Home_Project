#ifndef ICUM_PRIV_H
#define ICUM_PRIV_H


typedef struct
{
   tvpf    pfcallback    ;
   tvpf    pfOvfCallback ;
   tu16pf  pfCntrValue   ;
   tpfu8   pfChangesense ;
   uint16  u16OvfCount   ;    
   uint32  u32TimerFreq  ;
}tstrIcuCfg;

extern tstrIcuCfg ICUM_apfConfigSet[2];

void ICUM_voidExtIntISR(void);
void ICUM_voidOvfIsr(void);
#endif