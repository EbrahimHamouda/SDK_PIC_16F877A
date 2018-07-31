#include "tmr2.h"


void tmr2_init(enum tmr2_Pre ps,enum tmr2_post post){
    T2CON.PRE_SCLAR = ps;
    T2CON.POST_SCLAR = post; 
}

void tmr2_sw(enum tmr2_SW sw){
    T2CON.ON = sw; 
}

void tmr2_int_en(){

    INTCON.GIE  = 1; 
    INTCON.PEIE = 1;
    PIE1.TMR2IE = 1;
}

u8 tmr2_flage() {
    return PIF1.TMR2IF;
}

