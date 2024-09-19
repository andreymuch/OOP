#include <gtest/gtest.h>
#include <cmath>
#include "src/box_capacity.h"

// Тест с базовыми значениями
TEST(BoxCapacityTest, PositiveValues) {
    EXPECT_EQ(box_capacity(1, 1, 1), 1);  
    EXPECT_EQ(box_capacity(2, 2, 2), 8);  
    EXPECT_EQ(box_capacity(12, 12, 12), 1728);  
}
// Тест с нулевыми значениями
TEST(BoxCapacityTest, ZeroValues) {
    EXPECT_EQ(box_capacity(0, 1, 1), 0);  
    EXPECT_EQ(box_capacity(1, 0, 1), 0);  
    EXPECT_EQ(box_capacity(1, 1, 0), 0);  
}

// Тест с отрицательными значениями
TEST(BoxCapacityTest, NegativeValues) {
    EXPECT_EQ(box_capacity(-1, 1, 1), -1); 
    EXPECT_EQ(box_capacity(1, -1, 1), -1);  
    EXPECT_EQ(box_capacity(1, 1, -1), -1);  
}

// Тест с большими значениями
TEST(BoxCapacityTest, LargeValues) {
    EXPECT_GT(box_capacity(1000, 1000, 1000), 0); 
}

// Тест с дробными значениями
TEST(BoxCapacityTest, FloatingPointValues) {
    EXPECT_NEAR(box_capacity(1.5, 1.5, 1.5), 3.375, 0.001);  
}