/* 
 * File:   pic16f877a_regs.h
 * Author: ebrahim hamouda
 *
 * Created on March 14, 2018, 10:06 AM
 */

#include "Data_type.h"  


#ifndef PIC16F877A_REGS_H
#define	PIC16F877A_REGS_H

// port A
#define DDRAbit  (*(volatile  REG* )(0x85)) // access bit field 
#define PINRAbit (*(volatile  REG* )(0x05))  
#define DDRA      *((volatile  u8* )(0x85)) // diriection input output register 
#define PINRA     *((volatile  u8* )(0x05)) // pin input output register

// port B
#define DDRBbit  (*(volatile  REG* )(0x86)) // access bit field 
#define PINRBbit (*(volatile  REG* )(0x06))  
#define DDRB      *((volatile  u8* )(0x86)) // diriection input output register 
#define PINRB     *((volatile  u8* )(0x06)) // pin input output register

// port C
#define DDRCbit  (*(volatile  REG* )(0x87)) // access bit field 
#define PINRCbit (*(volatile  REG* )(0x07))  
#define DDRC      *((volatile  u8* )(0x87)) // diriection input output register 
#define PINRC     *((volatile  u8* )(0x07)) // pin input output register

// port D
#define DDRDbit  (*(volatile  REG* )(0x88)) // access bit field 
#define PINRDbit (*(volatile  REG* )(0x08))  
#define DDRD      *((volatile  u8* )(0x88)) // diriection input output register 
#define PINRD     *((volatile  u8* )(0x08)) // pin input output register

// port E
#define DDREbit  (*(volatile  REG* )(0x89)) // access bit field 
#define PINREbit (*(volatile  REG* )(0x09))  
#define DDRE      *((volatile  u8* )(0x89)) // diriection input output register 
#define PINRE     *((volatile  u8* )(0x09)) // pin input output register

// INTERRUPTS 

typedef struct {
    unsigned char RBIF   : 1;
    unsigned char INTF   : 1;
    unsigned char TMR0IF : 1;
    unsigned char RBIE   : 1;
    unsigned char INTE   : 1;
    unsigned char TMR0IE : 1;
    unsigned char PEIE   : 1;
    unsigned char GIE    : 1;
} INT0;
#define INTCON    (*(volatile  INT0* )(0x0B)) 

typedef struct {
    unsigned char TMR1IE   : 1;
    unsigned char TMR2IE   : 1;
    unsigned char CCP1IE   : 1;
    unsigned char SSPIE    : 1;
    unsigned char TXIE     : 1;
    unsigned char RCIE     : 1;
    unsigned char ADIE     : 1;
    unsigned char PSPIE    : 1;
} INTe;
#define PIE1    (*(volatile  INTe* )(0x8C)) 

typedef struct {
    unsigned char TMR1IF   : 1;
    unsigned char TMR2IF   : 1;
    unsigned char CCP1IF   : 1;
    unsigned char SSPIF    : 1;
    unsigned char TXIF     : 1;
    unsigned char RCIF     : 1;
    unsigned char ADIF     : 1;
    unsigned char PSPIF    : 1;
} INT2;
#define PIF1    (*(volatile  INT2* )(0x0C)) 



// timers

typedef struct {
    unsigned char PRE_SCLAR    : 3;
    unsigned char PRE_SELECT   : 1;
    unsigned char EDGE_SELECT  : 1;
    unsigned char CLOCK_SELECT : 1;
    unsigned char INTEDG       : 1;
    unsigned char RBPU         : 1;
} Tmr;
#define T0CON    (*(volatile  Tmr* )(0x81)) 
#define TMR0     *((volatile  u8*  )(0x01))


typedef struct {
    unsigned char ON           : 1;
    unsigned char CS           : 1;
    unsigned char SYNC         : 1;
    unsigned char OSCEN        : 1;
    unsigned char PRE_SCLAR    : 2;    
} Tmr1;
#define T1CON    (*(volatile  Tmr1* )(0x10)) 
#define TMR1H     *((volatile  u8*  )(0x0F))
#define TMR1L     *((volatile  u8*  )(0x0E))


typedef struct {
    unsigned char PRE_SCLAR    : 2;
    unsigned char ON           : 1;
    unsigned char POST_SCLAR   : 4;
} Tmr2;
#define T2CON    (*(volatile  Tmr2* )(0x12)) 
#define TMR2      *((volatile  u8*  )(0x11))
#define PR2       *((volatile  u8*  )(0x92))



/*ccp1 modual 
 * 
 */

typedef struct {
    unsigned char MODE      : 4;
    unsigned char PWM_L1    : 1;
    unsigned char PWM_L2    : 1;
} ccp_struct;

#define CCP1CON  (*(volatile  ccp_struct* )(0x17)) 
#define CCPR1L   *((volatile  u8*  )(0x15))
#define CCPR1H   *((volatile  u8*  )(0x16))


typedef struct {
    unsigned char TX9D               : 1;
    unsigned char TX_SHIFT_REG       : 1;
    unsigned char BAUD_RATE_SELECT   : 1;
    unsigned char NC                 : 1;
    unsigned char USART_MODE         : 1;
    unsigned char TX_ENABLE          : 1;
    unsigned char BIT_SELECT         : 1;
    unsigned char CLOCK_SOURCE       : 1;
    
} txsta_struct;

#define TXSTA  (*(volatile  txsta_struct* )(0x98)) 
#define TXREG  *((volatile  u8*  )(0x19))

typedef struct {
    unsigned char RX9D               : 1;
    unsigned char OVER_RUN_ERROR     : 1;
    unsigned char FRAM_ERROR         : 1;
    unsigned char NC                 : 1;
    unsigned char RX_EN              : 1;
    unsigned char SREN               : 1;
    unsigned char BIT_SELECT         : 1;
    unsigned char SERIAL_EN          : 1;
    
} rxsta_struct;

#define RXSTA  (*(volatile  rxsta_struct* )(0x18)) 
#define SPBRGH  *((volatile  u8*)(0x99))
#define RCREG  *((volatile  u8*  )(0x1a))






#endif	/* PIC16F877A_REGS_H */

