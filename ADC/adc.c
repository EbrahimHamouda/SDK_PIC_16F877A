
#include "ADC.h" 

void adc_init() {

    ADCON0 |= (1 << 0) | (1 << 7); // power up && Fosc/64 "BEST COHICE"

    ADCON1 |= (1 << 6) | (1 << 7); //port a all analog  && fosc/64 && right-justified 

    
}

u16 adc_read(u8 x) {
    
    x &= 0x07; //make sure x=00000[channel];

    ADCON0 |= (unsigned)x << 3;//set channel

    ADCON0 |= 1 << GO; //Go

    while (ADCON0 & (1 << DONE)); //check done 

    return (unsigned)((ADRESH * 256) + ADRESL); //read rigisters     
}




