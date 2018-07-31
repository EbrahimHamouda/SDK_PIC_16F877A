#include "ccp.h"

u16  freq;
#define TMR2PRESCALE T2CON.PRE_SCLAR  

void ccp1_mode(enum Ccp_Mode m){
    CCP1CON.MODE = m;
}

void capture1_init(){
    tmr1_mode(TIMER1);
    tmr1_status(tmr1_on);
    DDRCbit.b2 = 1;
}

u16 capture1(){
    return (((u16)CCPR1H)<<8)|((u16)CCPR1L);
}

void compare1_init(u16 comp){
    tmr1_mode(TIMER1);
    tmr1_status(tmr1_on);
    CCPR1L = (u8)(comp );
    CCPR1H = (u8)(comp>>8);
    DDRCbit.b2 = 0;
}


void pwm_duty_cycle(u16 d ){ // 0 : 100
    CCPR1L   = d >> 2;
    CCP1CON.PWM_L1  = d & 1;
    CCP1CON.PWM_L2  = d & 2;
}

void pwm_init(u16 fre){
    
     u32 prod = 4*fre;
     PR2 = ( _XTAL_FREQ / prod ) - 1;
    freq = fre ; 
}

void pwm_start(){
    DDRCbit.b2 = 0;
    ccp1_mode(PWM);
    T2CON.ON = 1;
}

u16 pwm_max_duty()
{
  return ( _XTAL_FREQ /( freq * T2CON.PRE_SCLAR ) );
}

