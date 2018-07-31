/* 
 * File:   tmr0.h
 * Author: ebrahim hamouda
 *
 * Created on April 6, 2018, 5:31 PM
 */

#include "pic16f877a_regs.h"




#ifndef TMR0_H
#define	TMR0_H

enum mode {
    COUNTER0, TIMER0};

enum pre_scalar {
    PRE0_2, PRE0_4, PRE0_8, PRE0_16, PRE0_32, PRE0_64, PRE0_128, PRE0_256
};

enum edge {
    LOW2HIGH, HIGH2LOW
};

void tmr0_set_presclar(enum pre_scalar t) ;

void tmr0_mode(enum mode m) ;

void tmr0_counter_edge(enum edge e) ;

void tmr0_int_en();

#endif	/* TMR0_H */

