#include "spi.h"



void spi_init(enum spi_mode m){
    SSPCON1.MODE =  m;
    SSPCON1.SERIAL_ENABLE = 1;
    SSPCON1.CKP = 0;
    SSPSTAT.CKE = 0; 
    SSPSTAT.SMP = 1;    
    DDRCbit.b5  = 0;  //SDO
    DDRCbit.b4  = 1;  //SDI 
}

void spi_master_tx(u8 data){
    DDRCbit.b3 = 0;
    SSPBUF =  data;
} 

u8 spi_master_rx(){
    DDRCbit.b3 = 0;
    while(!(SSPSTAT.BUFFER_FULL));
    return SSPBUF ; 
}   


void spi_slave_tx(u8 data){
    DDRCbit.b3 = 1;
    SSPBUF =  data;
} 

u8 spi_slave_rx(){
    DDRCbit.b3 = 1;
    while(!(SSPSTAT.BUFFER_FULL));
    return SSPBUF ; 
}   

void spi_int_en(){
    INTCON.GIE =1;
    INTCON.PEIE =1;
    PIE1.SSPIE =1;
}
