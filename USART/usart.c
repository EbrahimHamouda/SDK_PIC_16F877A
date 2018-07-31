
#include "usart.h"


void fbaud_rate(u16 x, baud_mode state ){
    TXSTA.BAUD_RATE_SELECT = state ;
    
    switch (state){
        case LOW_SPEED  : SPBRGH =(( _XTAL_FREQ / x / 64 ) -1); break;
        case HIGH_SPEED : SPBRGH =(( _XTAL_FREQ / x / 16 ) -1); break;
        case SYNC_SPEED : SPBRGH =(( _XTAL_FREQ / x / 4 ) -1); break;
    }
}

void fuart_tx_init(){
    DDRCbit.b6  = 0;
    TXSTA.USART_MODE = ASYNC;
    RXSTA.SERIAL_EN = ENABLE; 
    TXSTA.BIT_SELECT = _8BIT;
    TXSTA.TX_ENABLE = ENABLE;
}

void fuart_tx(u8 chart){
    while(!(PIF1.TXIF));
    TXREG = chart;
}

void fuart_tx_str(u8 *chart){
    while((*chart)!='\0'){
        fuart_tx(*chart);
        chart++;
    }
}

void fuart_rx_init(){
    DDRCbit.b7  = 1;
    TXSTA.USART_MODE = ASYNC;
    RXSTA.SERIAL_EN = ENABLE; 
    RXSTA.BIT_SELECT = _8BIT;
    RXSTA.RX_EN = ENABLE ;
}

u8 fuart_rx(){
    while(!(PIF1.RCIF)); 
    return RCREG ;
}

void fuart_rx_int_en(){
    INTCON.GIE  = 1;
    INTCON.PEIE = 1;
    PIE1.RCIE   = 1;
}