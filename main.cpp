#include "uint1024_t.h"
#include <stdio.h>
#include <malloc.h>
#include "gtest/gtest.h"
#include "tests/uint.h"


bool equals(uint1024_t a, uint1024_t b) {
    char *x1 = uint1024_to_hex(a);
    char *x2 = uint1024_to_hex(b);
    for (int i = 0; i < 256; i++) {
        if (x1[i] != x2[i]) {
            return false;
        }
    }

    return true;
}

bool test_1(char a[256], char b[256], char c[256]) {
    //char a[256] = "1000000000000000000000000000000000000000";


    uint1024_t uint1024_1 = hex_to_uint1024(a);

    //char b[256] = "1000000000000000000000000000000000000000";
    uint1024_t uint1024_2 = hex_to_uint1024(b);

    uint1024_1 = mul_op(uint1024_2, uint1024_1);

    uint1024_t uint1024_3 = hex_to_uint1024(c);

    return equals(uint1024_1, uint1024_3);
}


int main() {
    /*
    uint1024_t a, b;
    scanf_value(&a);
    scanf_value(&b);
    printf("Multiply: \n");
    printf_value(mul_op(a, b));
    printf("Add: \n");
    printf_value(add_op(a, b));
    printf("Sub: \n");
    printf_value(sub_op(a, b));
    */
    //printf_value(from_uint(1414144111));

    return RUN_ALL_TESTS();
}
