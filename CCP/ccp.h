/* 
 * File:   ccp.h
 * Author: ebrahim hamouda
 *
 * Created on April 11, 2018, 11:42 AM
 */

#include "pic16f877a_regs.h"
#include "tmr1.h" 
#include "tmr2.h"

#ifndef _XTAL_FREQ 
#define _XTAL_FREQ 8000000
#endif



#ifndef CCP_H
#define	CCP_H

enum Ccp_Mode {
    CCP_OFF,CAPTURE_FALL=4,CAPTURE_RISE=5,CAPTURE_4RISE=6,CAPTURE_16RISE=7,COMPARE_SET=8,COMPARE_CLEAR=9,COMPARE_INT=10,COMPARE_TRIGGER=11,PWM=12
};


void ccp1_mode(enum Ccp_Mode m); 

void capture1_init();

u16 capture1();

void compare1_init(u16 comp); 

void pwm_start();

void pwm_duty_cycle(u16 d);

u16 pwm_max_duty();

void pwm_init(u16 fre);



#endif	/* CCP_H */

