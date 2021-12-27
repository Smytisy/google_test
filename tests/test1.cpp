//
// Created by mailo on 27.12.2021.
//

#include "gtest/gtest.h"
#include "uint.h"
#include "../uint1024_t.h"


TEST(black_box_test, black) {

    EXPECT_EQ(test_1("10", "10", "100"),
              true);


    EXPECT_EQ(test_1("100", "100", "10000"),
              true);

    EXPECT_EQ(test_1("ffff", "ffff", "fffe0001"),
              true);
    EXPECT_EQ(test_1("ffffffff", "dddd", "dddcffff2223"),
              true);
}
TEST(gray_box_test, gray) {

    EXPECT_EQ(test_1("0", "0", "0"),
              true);


    EXPECT_EQ(test_1("100", "100", "10000"),
              true);

    EXPECT_EQ(test_1("ffff", "ffff", "fffe0001"),
              true);
    EXPECT_EQ(test_1("ffffffff", "dddd", "dddcffff2223"),
              true);
}
TEST(white_box_test, white) {

    EXPECT_EQ(test_1("101", "101", "10201"),
              true);


    EXPECT_EQ(test_1("10000", "10000", "100000000"),
              true);

    EXPECT_EQ(test_1("ffff", "ffff", "fffe0001"),
              true);
    EXPECT_EQ(test_1("ffffffff", "dddd", "dddcffff2223"),
              true);
}