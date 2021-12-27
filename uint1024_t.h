//
// Created by mailo on 16.09.2021.
//
#include "gtest/gtest.h"
#include <stdint.h>

#ifndef UINT1024_T_UINT1024_T_H
#define UINT1024_T_UINT1024_T_H

#endif //UINT1024_T_UINT1024_T_H


typedef struct{
    uint32_t *ranks;
} uint1024_t;

uint1024_t from_uint(unsigned int x);

uint1024_t add_op(uint1024_t x, uint1024_t y);
uint1024_t sub_op(uint1024_t x, uint1024_t y);
uint1024_t mul_op(uint1024_t x, uint1024_t y);

uint32_t char_to_int(char a);

void printf_value(uint1024_t x);
void scanf_value(uint1024_t *x);

char* uint1024_to_hex(uint1024_t x);
uint1024_t hex_to_uint1024(char* str_value);
