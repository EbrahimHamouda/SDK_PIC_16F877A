/* 
 * File:   key_pad.h
 * Author: ebrahim hamouda
 *
 * Created on March 21, 2018, 5:52 PM
 */
#include "pic16f877a_regs.h"
#include "Data_type.h"

#ifndef KEY_PAD_H
#define	KEY_PAD_H

#define kpad_port PINRC
#define kpad_DDR  DDRC

void kpad_init(); 
u8 get_key();
u8 key_pressed();


#endif	/* KEY_PAD_H */

