/* 
 * File:   ADC.h
 * Author: ebrahim hamouda
 *
 * Created on March 25, 2018, 12:53 PM
 */

#include "Data_type.h"

#ifndef ADC_H
#define	ADC_H

#define ADCON0      *((volatile  u8* )(0x1F)) // diriection input output register 
#define ADCON1      *((volatile  u8* )(0x9F)) // diriection input output register 
#define ADRESH      *((volatile  u8* )(0x1E))
#define ADRESL      *((volatile  u8* )(0x9E))
#define GO    2
#define DONE  2


void adc_init();
u16 adc_read(u8 x);

#endif	/* ADC_H */

