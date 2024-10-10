#include "src/Money.h"
#include <gtest/gtest.h>


TEST(MoneyTest, ConstructorValidTest) {
    Money m1("123.45");
    Money m2("76.55");

    ASSERT_EQ(m1.operator==(Money("123.45")), true);
    ASSERT_EQ(m2.operator==(Money("76.55")), true);
}


TEST(MoneyTest, ConstructorInvalidTest) {
    ASSERT_THROW(Money m("12a.45"), std::invalid_argument);
    ASSERT_THROW(Money m(""), std::invalid_argument);
}


TEST(MoneyTest, AdditionTest) {
    Money m1("123.45");
    Money m2("76.55");

    Money result = m1 + m2;
    ASSERT_EQ(result.operator==(Money("200.00")), true);
}

TEST(MoneyTest, SubtractionTest) {
    Money m1("123.45");
    Money m2("76.55");

    Money result = m1 - m2;
    ASSERT_EQ(result.operator==(Money("46.90")), true);
}


TEST(MoneyTest, AdditionAssignmentTest) {
    Money m1("123.45");
    Money m2("76.55");

    m1 += m2;
    ASSERT_EQ(m1.operator==(Money("200.00")), true);
}


TEST(MoneyTest, SubtractionAssignmentTest) {
    Money m1("123.45");
    Money m2("76.55");

    m1 -= m2;
    ASSERT_EQ(m1.operator==(Money("123.45")), true);
}


TEST(MoneyTest, ComparisonTest) {
    Money m1("123.45");
    Money m2("76.55");

    ASSERT_EQ(m1 > m2, true);
    ASSERT_EQ(m1 < m2, false);
    ASSERT_EQ(m1 == m2, false);
}


TEST(MoneyTest, AdjustLengthTest) {
    Money m1("123.45");
    Money m2("76.555"); 

    m1.adjustLengths(m2);  

    ASSERT_EQ(m1.operator==(Money("123.450")), true);
}
