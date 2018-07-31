/* 
 * File:   tmr1.h
 * Author: ebrahim hamouda
 *
 * Created on April 8, 2018, 12:33 PM
 */

#include "pic16f877a_regs.h"

#ifndef TMR1_H
#define	TMR1_H

enum mode1 {
     TIMER1 , COUNTER1
};

enum pre_scalar1 {
    PRE1_1, PRE1_2, PRE1_4, PRE1_8
};

enum status_tmr1 { 
    tmr1_off,tmr1_on   
};

enum sync_tmr1 { 
   syn_on,syn_off    
};

enum osc_tmr1 {
    shut_off ,enable 
};



    

void tmr1_set_presclar(enum pre_scalar1 t) ;

void tmr1_mode(enum mode1 m) ;

void tmr1_status(enum status_tmr1 s);

void tmr1_sync(enum sync_tmr1 s);

void tmr1_osc(enum osc_tmr1 s);

void tmr1_int_en();

u16  tmr1_read();

u8   tmr1_flage(); 

void tmr1_int_en(); 

void tmr1_clear();

#endif	/* TMR1_H */

