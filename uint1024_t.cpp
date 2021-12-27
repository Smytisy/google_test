//
// Created by mailo on 27.12.2021.
//

//
// Created by mailo on 16.09.2021.
//
#include<stdio.h>
#include "malloc.h"
#include "uint1024_t.h"
#include "string.h"
#include "gtest/gtest.h"


uint1024_t mul_op(uint1024_t x, uint1024_t y) {
    uint1024_t mul_res;
    mul_res.ranks = (uint32_t *) malloc(sizeof(uint32_t) * 32);
    uint64_t rank[32][64] = {0};
    uint64_t mult;
    uint64_t x1, y1;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            x1 = x.ranks[i];
            y1 = y.ranks[j];
            mult = x1 * y1;
            rank[i][j + i] += mult;
            rank[i][j + i + 1 ] += rank[i][i + j] >> (32);
            rank[i][j + i] = rank[i][i + j] << (32) >> (32);
        }
    }
    for (int j = 0; j < 32; j++) {
        for (int i = 1; i < 32; i++) {
            rank[i][j] += rank[i - 1][j];
        }
        rank[31][j + 1] += rank[31][j] >> (32);
        rank[31][j] = rank[31][j] << (32) >> (32);
    }
    for (int i = 0; i < 32; i++) {
        mul_res.ranks[i] = rank[31][i];
    }
    if(rank[31][32] > 0) {
        printf("\nUndefined Behavior! \n\n");
    }
    return mul_res;
}


uint1024_t sub_op(uint1024_t x, uint1024_t y) {
    uint1024_t sub_res = from_uint(0);
    uint32_t pred;
    int64_t tmp, x1, y1;
    uint32_t carryOver = 0;
    for (int i = 0; i < 32; i++) {
        x1 = x.ranks[i];
        y1 = y.ranks[i];
        tmp = x1 - y1 - carryOver;
        if (tmp < 0) {
            pred = 4294967295 + 1 + tmp;
            carryOver = 1;
        } else {
            pred = tmp;
            carryOver = 0;
        }
        sub_res.ranks[i] = pred;
    }
    if (carryOver == 1) {
        printf("\nOut of range! \n\n");
        return from_uint(0);
    }
    return sub_res;
}


uint1024_t add_op(uint1024_t x, uint1024_t y) {
    uint64_t a, x1, y1;
    uint1024_t sum_res = from_uint(0);
    uint64_t pred = 0;
    for (int i = 0; i < 32; i++) {
        x1 = x.ranks[i];
        y1 = y.ranks[i];
        a = x1 + y1 + pred;
        pred = a >> (32);
        sum_res.ranks[i] = a << (32) >> (32);
    }
    if(pred > 0) {
        printf("\nUndefined Behavior! \n\n");
    }
    return sum_res;
}

uint1024_t from_uint(unsigned int x) {
    uint1024_t uint1024;
    uint1024.ranks = (uint32_t *) malloc(sizeof(uint32_t) * 32);
    uint1024.ranks[0] = x;
    for (int i = 1; i < 32; i++) {
        uint1024.ranks[i] = 0;
    }
    return uint1024;
}

uint32_t char_to_int(char a) {
    uint32_t value;
    if (a >= 'a' && a <= 'f') {
        value = a - 'a' + 10;
    } else {
        if (a >= 'A' && a <= 'F') {
            value = a - 'A' + 10;
        } else {
            value = a - '0';
        }
    }
    return value;
}

uint1024_t hex_to_uint1024(char *str_value) {
    unsigned int len = strlen(str_value);
    uint1024_t uint1024_res;
    uint1024_res = from_uint(0);
    unsigned int rank = len / 8;

    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < 8; j++) {
            uint1024_res.ranks[i] += char_to_int(str_value[len - 1 - i * 8 - j]) << (4 * j);
        }
        //printf("%u\n", uint1024_res.ranks[i]);
    }
    for (int i = 0; i < len % 8; i++) {
        uint1024_res.ranks[rank] += char_to_int(str_value[len - 1 - rank * 8 - i]) << (4 * i);
    }
    //printf("%u\n",uint1024_res.ranks[rank]);

    return uint1024_res;
}

char *uint1024_to_hex(uint1024_t uint1024) {
    char *value_res = (char *) malloc(sizeof(char) * (1024 / 4 + 1));
    char *alphabet = "0123456789abcdef";
    for (int i = 31; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            value_res[256 - (i + 1) * 8 + j] = alphabet[((uint1024.ranks[i] << (j * 4)) >> (7 * 4))];
        }
    }
    value_res[256] = '\0';
    return value_res;
}


void scanf_value(uint1024_t *x) {
    char a[256];
    printf("Enter your hex number 1024 bit: \n");
    scanf("%s", a);
    uint1024_t uint1024 = hex_to_uint1024(a);
    *x = uint1024;
}

void printf_value(uint1024_t x) {
    printf("This is your hex number 1024 bit: \n");
    printf("%s\n", uint1024_to_hex(x));
}


