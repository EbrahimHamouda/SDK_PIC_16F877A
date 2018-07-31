/* 
 * File:   Data_type.h
 * Author: ebrahim hamouda
 *
 * Created on March 14, 2018, 10:17 AM
 */

#ifndef DATA_TYPE_H
#define	DATA_TYPE_H

typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} REG;

typedef unsigned char      u8;
typedef unsigned int       u16;
typedef unsigned long      u32;
typedef unsigned long long u64;

typedef signed char       s8;
typedef signed int        s16;
typedef signed long       s32;
typedef signed long long  s64;

typedef float      f32;
typedef double     f64;


#endif	/* DATA_TYPE_H */

