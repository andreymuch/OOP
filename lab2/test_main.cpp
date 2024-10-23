#include <gtest/gtest.h>
#include <string>
#include "./src/Money.h"

TEST(MoneyTest, ConstructorWithString) {
    std::string str = "100";
    Money m1(str);
    Money m2("100");
    EXPECT_TRUE(m1.equals(m2));
}
TEST(MoneyTest, CopyConstructor) {
    Money m1("200");
    Money m2(m1);
    EXPECT_TRUE(m1.equals(m2));
}
TEST(MoneyTest, MoveConstructor) {
    Money m1("300");
    Money m2(std::move(m1));
    EXPECT_TRUE(m2.equals(Money("300")));
}
TEST(MoneyTest, AddFunction) {
    Money m1("100");
    Money m2("200");
    Money result = m1.add(m2);
    EXPECT_TRUE(result.equals(Money("300")));
}
TEST(MoneyTest, SubtractFunction) {
    Money m1("500");
    Money m2("200");
    Money result = m1.subtract(m2);
    EXPECT_TRUE(result.equals(Money("300")));
}
TEST(MoneyTest, EqualsFunction) {
    Money m1("100");
    Money m2("100");
    Money m3("200");
    EXPECT_TRUE(m1.equals(m2));
    EXPECT_FALSE(m1.equals(m3));
}
TEST(MoneyTest, LessThanFunction) {
    Money m1("100");
    Money m2("200");
    EXPECT_TRUE(m1.lessThan(m2));
    EXPECT_FALSE(m2.lessThan(m1));
}

TEST(MoneyTest, GreaterThanFunction) {
    Money m1("300");
    Money m2("100");
    EXPECT_TRUE(m1.greaterThan(m2));
    EXPECT_FALSE(m2.greaterThan(m1));
}

TEST(MoneyTest, MoveAssignFunction) {
    Money m1("400");
    Money m2("100");
    m2.moveAssign(std::move(m1));
    EXPECT_TRUE(m2.equals(Money("400")));

}


TEST(MoneyTest, AddAssignFunction) {
    Money m1("200");
    Money m2("300");
    m1.addAssign(m2);
    EXPECT_TRUE(m1.equals(Money("500")));
}

TEST(MoneyTest, SubtractAssignFunction) {
    Money m1("500");
    Money m2("300");
    m1.subtractAssign(m2);
    EXPECT_TRUE(m1.equals(Money("200")));
}