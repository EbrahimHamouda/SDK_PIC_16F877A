#include "tmr1.h"

void tmr1_set_presclar(enum pre_scalar1 t) {
    T1CON.PRE_SCLAR = t;
}

void tmr1_mode(enum mode1 m) {
    T1CON.CS = m;
}

void tmr1_status(enum status_tmr1 s) {
    T1CON.ON = s;
}

void tmr1_sync(enum sync_tmr1 s) {
    T1CON.SYNC = s;
}

void tmr1_osc(enum osc_tmr1 s) {
    T1CON.OSCEN = s;
}

void tmr1_int_en() {
    INTCON.GIE = 1;
    INTCON.PEIE = 1;
//    PIE1.TMR1IE = 1;
}

u8 tmr1_flage() {
    return PIF1.TMR1IF;
}

u16 tmr1_read() {
    
   u16 temp = (unsigned) TMR1L + (unsigned) 256*TMR1H ;
 
   return  temp ;
}

void tmr1_clear() {
    TMR1L = 0;
    TMR1H = 0;
}
