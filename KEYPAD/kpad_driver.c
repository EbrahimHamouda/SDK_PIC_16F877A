/*
 * File:   kpad_driver.c
 * Author: ebrahim hamouda
 *
 * Created on March 21, 2018, 5:56 PM
 */


#include "key_pad.h"

void kpad_init() {
    kpad_DDR = 0xf0;
}

u8 get_key() {
    int i, j;
    for (i = 0; i < 4; i++) {
        kpad_port = 0x00;
        kpad_port |= (unsigned) 1 << i;
        for (j = 0; j < 4; j++) {
            if (kpad_port & (1 << (j + 4))) {
                while (kpad_port & (1 << (j + 4)));
                switch (i) {
                    case (0):
                    {
                        if (j == 0) return '7';
                        else if (j == 1) return '8';
                        else if (j == 2) return '9';
                        else if (j == 3) return '/';
                        break;
                    }
                    case (1):
                    {
                        if (j == 0) return '4';
                        else if (j == 1) return '5';
                        else if (j == 2) return '6';
                        else if (j == 3) return '*';
                        break;
                    }
                    case (2):
                    {
                        if (j == 0) return '1';
                        else if (j == 1) return '2';
                        else if (j == 2) return '3';
                        else if (j == 3) return '-';
                        break;
                    }
                    case (3):
                    {
                        if (j == 0) return 'c';
                        else if (j == 1) return '0';
                        else if (j == 2) return '=';
                        else if (j == 3) return '+';
                        break;
                    }
                }
                kpad_port=0x00;
            }
        }
    }
 return '\0';    
}

u8 key_pressed()
{
     return get_key();
}