/* 
 * File:   spi.h
 * Author: ebrahim hamouda
 *
 * Created on April 21, 2018, 4:25 AM
 */
#include "pic16f877a_regs.h"

#ifndef SPI_H
#define	SPI_H

typedef struct {
    unsigned char BUFFER_FULL          : 1;
    unsigned char UPDATE_ADD_DETECT    : 1;
    unsigned char WRITE_READ           : 1;
    unsigned char START_BIT            : 1;
    unsigned char STOP_BIT             : 1;
    unsigned char ADD_DATA             : 1;
    unsigned char CKE                  : 1;
    unsigned char SMP                  : 1;
} sspstat_struct;

#define SSPSTAT  (*(volatile  sspstat_struct* )(0x94)) 

typedef struct {
    unsigned char MODE                 : 4;
    unsigned char CKP                  : 1;
    unsigned char SERIAL_ENABLE        : 1;
    unsigned char OVERFLOW_DETECT      : 1;
    unsigned char COLLISION_DETECT     : 1;
} sspcon1_struct;

#define SSPCON1  (*(volatile  sspcon1_struct* )(0x14))

enum spi_mode{
    SLAVE_SS_DISABLE=5, SLAVE_SS_ENABLE=4, MASTER_OSC_DIV_4=0, MASTER_OSC_DIV_16=1, MASTER_OSC_DIV_64=2
};

void spi_init(enum spi_mode m);

void spi_master_tx(u8 data);

u8 spi_master_rx();

void spi_int_en();

u8 spi_slave_rx();

void spi_slave_tx(u8 data);


#endif	/* SPI_H */

