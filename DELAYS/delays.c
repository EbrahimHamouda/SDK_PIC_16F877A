/* 
 * File:   delays.c
 * Author: ebrahim hamouda
 *
 * Created on March 15, 2018, 3:41 PM
 */
#include "Data_type.h"
#include "pic16f877a_regs.h"
void delay_ms(u32 n) {
    
    volatile u32 count;
    while ((n+1) > 0) {
        for (count = 0; count <100 ; count++) {
            asm("nop");
        }
       
          n--;
    }
    
    
}

