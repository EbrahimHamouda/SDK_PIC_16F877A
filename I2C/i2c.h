/* 
 * File:   i2c.h
 * Author: ebrahim hamouda
 *
 * Created on April 19, 2018, 4:41 PM
 */
#include "pic16f877a_regs.h" 
#include "delays.h"
#ifndef I2C_H
#define	I2C_H

typedef struct {
    unsigned char BUFFER_FULL          : 1;
    unsigned char UPDATE_ADD_DETECT    : 1;
    unsigned char WRITE_READ           : 1;
    unsigned char START_BIT            : 1;
    unsigned char STOP_BIT             : 1;
    unsigned char ADD_DATA             : 1;
    unsigned char SM_BUS               : 1;
    unsigned char SPEED                : 1;
} sspstat_struct;

#define SSPSTAT  (*(volatile  sspstat_struct* )(0x94)) 

typedef struct {
    unsigned char MODE                 : 4;
    unsigned char CLOCK_CONTROL        : 1;
    unsigned char SERIAL_ENABLE        : 1;
    unsigned char OVERFLOW_DETECT      : 1;
    unsigned char COLLISION_DETECT     : 1;
} sspcon1_struct;

#define SSPCON1  (*(volatile  sspcon1_struct* )(0x14))

typedef struct {
    unsigned char START_EN             : 1;
    unsigned char RESTART_EN           : 1;
    unsigned char STOP_EN              : 1;
    unsigned char RX_EN                : 1;
    unsigned char ACK_EN               : 1;
    unsigned char ACK_DT               : 1;
    unsigned char ACK_STAT             : 1;
    unsigned char GENERAL_INT_EN       : 1;
} sspcon2_struct;

#define SSPCON2  (*(volatile  sspcon2_struct* )(0x91)) 
#define SSPBUF   *((volatile  u8*)(0x13))
#define SSPADD   *((volatile  u8*)(0x93))


#define  SEN     SSPCON2.START_EN
#define  RSEN    SSPCON2.RESTART_EN
#define  PEN     SSPCON2.STOP_EN
#define  RCEN    SSPCON2.RX_EN
#define  ACKEN   SSPCON2.ACK_EN
#define  SSPIF   PIF1.SSPIF 
#define  R_W     SSPSTAT.WRITE_READ



enum i2c_mod {
     MASTER = 8, SLAVE_7BIT = 6
};

enum i2c_speed{ 
    _400KHZ,_100KHZ
};


void i2c_init(enum i2c_mod m,enum i2c_speed s,u32 x);
void i2c_master_wait();
void i2c_master_start();
void i2c_master_restart();
void i2c_master_stop();
void i2c_master_write(u8 d);
u8   i2c_master_read(unsigned short a);


#endif	/* I2C_H */

