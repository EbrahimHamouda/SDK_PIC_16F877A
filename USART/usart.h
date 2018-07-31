/* 
 * File:   usart.h
 * Author: ebrahim hamouda
 *
 * Created on April 14, 2018, 11:19 PM
 */
#include "pic16f877a_regs.h"
#include "CLOCK.h" 

#ifndef USART_H
#define	USART_H

typedef enum Baud_Mode{
    LOW_SPEED,HIGH_SPEED,SYNC_SPEED
}baud_mode;

enum usart_mode{
    ASYNC,SYNC
};

enum Switch{
    DISABLE,ENABLE
};

enum trans_data{
    _8BIT,_9BIT
};

enum sync_mode{
    SLAVE,MASTER
};

enum clock_source{
    EXTERNAL,INTERNAL 
};

 
void fbaud_rate(u16 x, baud_mode state) ;

void fuart_tx_init();

void fuart_tx_str(u8 *chart);

void fuart_tx(u8 chart);

void fuart_tx_int_en();

u8 fuart_rx();

void fuart_rx_init();

void fuart_rx_int_en();



#endif	/* USART_H */

