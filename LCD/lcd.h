/* 
 * File:   lcd.h
 * Author: ebrahim hamouda
 *
 * Created on March 15, 2018, 11:29 PM
 */
#include "Data_type.h"
#include "pic16f877a_regs.h"

#ifndef LCD_H
#define	LCD_H

#define DataDirc  DDRB 
#define DataPort  PINRB
#define lcd_con   PINRB
#define EN        3
#define RW        2
#define RS        1
#define bit_4_mode 


struct
{
}
/*commands*/
#define BUSY_FLAG DataPort&(1<<7)

#define ENTRY_MODE   0x06
#define CLEAR_SCREEN 0x01
#define BIT_4        0x28
#define BIT_8        0x38
#define CURSOR_BLINK 0x0f
#define CURSOR_ON    0x0e
#define CURSOR_OFF   0x0c
#define DISPLAY_OFF  0x08


void lcd_init();
u8 lcd_busy();
void lcd_cmd(u8 cmd);
void lcd_chr(u8 chr);
void lcd_clear();
void lcd_off();
void lcd_goto(u8 row, u8 col);

void lcd_str(u8 *pstr);
void lcd_unum(s32 num);
void lcd_snum(s32 num);
void lcd_fnum(f32 num);
#endif	/* LCD_H */





















//typedef enum mode {MODE_4BIT,MODE_8BIT} Mode;
//typedef enum cursor{CURSOROFF,CURSOR_ON_BLINK,CURSOR_ON_NBLINK} Cursor;
//typedef struct
//{
//    Mode  lcd_mode; 
//    Cursor lcd_cursor; 
//    u8 *data_port; 
//    u8 *data_dirc;  
//    u8 *ControlPort;
//} lcd;
