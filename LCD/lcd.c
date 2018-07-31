/* 
 * File:   lcd.c
 * Author: ebrahim hamouda
 *
 * Created on March 15, 2018, 11:23 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include "lcd.h"
#include "delays.h"

static void kick() {
    lcd_con &= ~(1 << EN);
    delay_ms(10);
    lcd_con |= (1 << EN);
}

void lcd_init() {
    delay_ms(10);
#ifdef bit_4_mode
    lcd_cmd(0x02);
    lcd_cmd(BIT_4);
#endif

#ifdef bit_8_mode

    lcd_cmd(BIT_8);

#endif

    lcd_cmd(ENTRY_MODE);
    lcd_goto(0, 0);
    lcd_cmd(CURSOR_BLINK);
    lcd_clear();
}

u8 lcd_busy() {

    DataDirc = (DataDirc & (unsigned) 0x0f) | (in_put & (unsigned) 0xf0);
    lcd_con |= (1 << RW);
    lcd_con &= ~(1 << RS);
    return (unsigned) BUSY_FLAG;
}

void lcd_cmd(u8 cmd) {
    while (lcd_busy());
    lcd_con &= ~(1 << RW);
    lcd_con &= ~(1 << RS);

#ifdef bit_4_mode

    DataDirc = (DataDirc & (unsigned) 0x0f) | (out_put & (unsigned) 0xf0);
    DataPort = (DataPort & (unsigned) 0x0f) | (cmd & (unsigned) 0xf0);
    kick();
    DataPort = (DataPort & (unsigned) 0x0f) | (unsigned) (cmd << 4);
    kick();
#endif

#ifdef bit_8_mode

    DataDirc = out_put;
    DataPort = cmd;
    kick();

#endif


}

void lcd_chr(u8 chr) {
    while (lcd_busy());
    lcd_con &= ~(1 << RW);
    lcd_con |= (1 << RS);

#ifdef bit_4_mode

    DataDirc = (DataDirc & (unsigned) 0x0f) | (out_put & (unsigned) 0xf0);
    DataPort = (DataPort & (unsigned) 0x0f) | (chr & (unsigned) 0xf0);
    kick();
    DataPort = (DataPort & (unsigned) 0x0f) | (unsigned) (chr << 4);
    kick();

#endif

#ifdef bit_8_mode

    DataDirc = out_put;
    DataPort = chr;
    kick();

#endif

}

void lcd_clear() {
    lcd_cmd(CLEAR_SCREEN);
}

void lcd_off() {
    lcd_cmd(DISPLAY_OFF);
}

void lcd_goto(u8 row, u8 col) {
    if (row == 0) {
        lcd_cmd((unsigned) 0x80 | col);
    } else if (row == 1) {
        lcd_cmd((unsigned) 0xc0 | col);
    }
}

void lcd_str(u8 *pstr) {
    while (*pstr != '\0') {
        lcd_chr(*pstr);
        pstr++;
    }
}

void lcd_unum(s32 num) {
    u8 str[15];
    sprintf(str,"%u",num);
    lcd_str(str);
}

void lcd_snum(s32 num) {
    u8 str[15];
    sprintf(str,"%d",num);
    lcd_str(str);
}

void lcd_fnum(f32 num) {

    
char str[16];
    volatile char *sign= (num<0)? "-" :"";
    float realValue= (num<0)? -num : num ;

    int intValue = (int)realValue;
    float diffValue = realValue - (float)intValue;
    int anotherIntValue = (int)(diffValue * 10000.0);

    sprintf(str,"%s%d.%04d",sign,intValue,anotherIntValue);
    
    lcd_str(str);

}