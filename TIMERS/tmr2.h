/* 
 * File:   tmr2.h
 * Author: ebrahim hamouda
 *
 * Created on April 11, 2018, 6:31 AM
 */

#include "pic16f877a_regs.h" 

#ifndef TMR2_H
#define	TMR2_H

enum tmr2_Pre {
   PRE2_1, PRE2_4, PRE2_16
};

enum tmr2_SW{
    TMR2_OFF,TMR2_ON 
};

enum tmr2_post{
    POST_1,POST_2,POST_3,POST_4,POST_5,POST_6,POST_7,POST_8,POST_9,POST_10,POST_11,POST_12,POST_13,POST_14,POST_15,POST_16
};


void tmr2_init(enum tmr2_Pre ps,enum tmr2_post post);    // initialize timer2 

void tmr2_sw(enum tmr2_SW sw);

void tmr2_int_en(); 

u8  tmr2_flage(); 


#endif	/* TMR2_H */

