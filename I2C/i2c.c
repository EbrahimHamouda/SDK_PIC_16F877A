#include "i2c.h"
#include "CLOCK.h"

void i2c_init(enum i2c_mod m, enum i2c_speed s, u32 x) {


    SSPCON1.SERIAL_ENABLE = 1; // start module 
    SSPCON1.MODE = m; // selct el mode
    DDRCbit.b3 = 1; // make sure they are input like data sheet 
    DDRCbit.b4 = 1;
    SSPSTAT.SPEED = 0; // select speed

    switch (m) {
        case MASTER:
        {
            SSPADD = (_XTAL_FREQ / 4 / x) - 1; // set clock
            break; 
        }
        case SLAVE_7BIT:
        {
            SSPADD = (u8) x; // set addrass 
            SSPCON1.CLOCK_CONTROL =1;   
            SSPCON2.START_EN =1;
            break; 
        }
    }
}

void i2c_master_wait() {
    while (R_W | SEN | RSEN | PEN | RCEN | ACKEN); //Transmit is in progress
}

void i2c_master_start() {
    i2c_master_wait();
    SEN = 1; //Initiate start condition
}

void i2c_master_restart() {
    i2c_master_wait();
    RSEN = 1; //Initiate repeated start condition
}

void i2c_master_stop() {
    i2c_master_wait();
    PEN = 1; //Initiate stop condition
}

void i2c_master_write(u8 d) {
    i2c_master_wait();
    SSPBUF = d; //Write data to SSPBUF
}

u8 i2c_master_read(unsigned short a) {
    unsigned short temp;
    i2c_master_wait();
    SSPCON2.RX_EN = 1;
    i2c_master_wait();
    temp = SSPBUF; //Read data from SSPBUF
    i2c_master_wait();
    SSPCON2.ACK_DT = (a) ? 0 : 1; //Acknowledge bit
    SSPCON2.ACK_EN = 1; //Acknowledge sequence
    return temp;
}


void interrupt i2c_slave_int_read() {
    u8 z;
    if (SSPIF == 1) {
        SSPCON1.CLOCK_CONTROL = 0;

        if ((SSPCON1.OVERFLOW_DETECT) || (SSPCON1.COLLISION_DETECT)) //If overflow or collision
        {
            z = SSPBUF; // Read the previous value to clear the buffer
            SSPCON1.OVERFLOW_DETECT = 0; // Clear the overflow flag
            SSPCON1.COLLISION_DETECT = 0; // Clear the collision bit
            SSPCON1.CLOCK_CONTROL = 1;
        }
    }

    if ((!SSPSTAT.ADD_DATA) && (!SSPSTAT.WRITE_READ)) //If last byte was Address + Write
    {
        z = SSPBUF;
        while (!SSPSTAT.BUFFER_FULL);
        PINRD = SSPBUF;
        SSPCON1.CLOCK_CONTROL = 1;
    } else if (!SSPSTAT.ADD_DATA && SSPSTAT.WRITE_READ) //If last byte was Address + Read
    {
        z = SSPBUF;
        SSPSTAT.BUFFER_FULL = 0;
        SSPBUF = PINRD;
        SSPCON1.CLOCK_CONTROL = 1;
        while (SSPSTAT.BUFFER_FULL);
    }

    SSPIF = 0;
}

void i2c_slave_init(u8 addrass) {
    
    SSPADD = addrass;
    SSPCON1.MODE = SLAVE_7BIT;
    SSPCON1.CLOCK_CONTROL=1;
    SSPCON1.SERIAL_ENABLE=1;
    DDRCbit.b3 = 1; // make sure they are input like data sheet 
    DDRCbit.b4 = 1;
    INTCON.GIE = 1;
    INTCON.PEIE = 1;
    PIE1.SSPIE = 1;
    SSPIF = 0;
}


















