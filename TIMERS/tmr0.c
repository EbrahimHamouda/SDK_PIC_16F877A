#include "tmr0.h"

void tmr0_set_presclar(enum pre_scalar t) {
    T0CON.PRE_SELECT = 0;
    T0CON.PRE_SCLAR = t;
}

void tmr0_mode(enum mode m) {
    if (m == 0) {
        T0CON.CLOCK_SELECT = 1;
    } else {
        T0CON.CLOCK_SELECT = 0;
    }
}

void tmr0_counter_edge(enum edge e) {
    if (e == 0) {
        T0CON.EDGE_SELECT = 0;
    } else {
        T0CON.EDGE_SELECT = 0;
        ;
    }
}

void tmr0_int_en() {
    INTCON.GIE = 1;
    INTCON.PEIE = 1;
    INTCON.TMR0IE = 1;
}

