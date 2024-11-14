#include <gtest/gtest.h>
#include "src\Trapezoid.h"
#include "src\Rhombus.h"
#include "src\Pentagon.h"
#include "src\Array.h"



TEST(TrapezoidTest, CopyConstructor) {
    Trapezoid trap1(3.0, 4.0, 5.0);
    Trapezoid trap2 = trap1;
    EXPECT_EQ(trap1, trap2);
}

TEST(TrapezoidTest, MoveConstructor) {
    Trapezoid trap1(3.0, 4.0, 5.0);
    Trapezoid trap2 = std::move(trap1);
    EXPECT_DOUBLE_EQ(trap2.operator double(), 17.5);
}

TEST(TrapezoidTest, AssignmentOperator) {
    Trapezoid trap1(3.0, 4.0, 5.0);
    Trapezoid trap2(0.0,0.0,0.0);
    trap2 = trap1;
    EXPECT_EQ(trap1, trap2);
}

TEST(TrapezoidTest, MoveAssignmentOperator) {
    Trapezoid trap1(3.0, 4.0, 5.0);
    Trapezoid trap2(0.0,0.0,0.0);
    trap2 = std::move(trap1);
    EXPECT_DOUBLE_EQ(trap2.operator double(), 17.5);
}

TEST(RhombusTest, CopyConstructor) {
    Rhombus rhombus1(4.0, 5.0);
    Rhombus rhombus2 = rhombus1;
    EXPECT_EQ(rhombus1, rhombus2);}

TEST(RhombusTest, MoveConstructor) {
    Rhombus rhombus1(4.0, 5.0);
    Rhombus rhombus2 = std::move(rhombus1);
   EXPECT_DOUBLE_EQ(rhombus2.operator double(), 10.0);
}

TEST(RhombusTest, AssignmentOperator) {
    Rhombus rhombus1(4.0, 5.0);
    Rhombus rhombus2(0.0,0.0);
    rhombus2 = rhombus1;
    EXPECT_EQ(rhombus1, rhombus2);
}

TEST(RhombusTest, MoveAssignmentOperator) {
    Rhombus rhombus1(4.0, 5.0);
    Rhombus rhombus2(0.0,0.0);
    rhombus2 = std::move(rhombus1);
    EXPECT_DOUBLE_EQ(rhombus2.operator double(), 10.0);
}

TEST(PentagonTest, CopyConstructor) {
    Pentagon pentagon1(5.0);
    Pentagon pentagon2 = pentagon1;
    EXPECT_EQ(pentagon1, pentagon2);
}

TEST(PentagonTest, MoveConstructor) {
    Pentagon pentagon1(5.0);
    Pentagon pentagon2 = std::move(pentagon1);
    EXPECT_DOUBLE_EQ(pentagon2.operator double(), 43.01193501472418);
}

TEST(PentagonTest, AssignmentOperator) {
    Pentagon pentagon1(5.0);
    Pentagon pentagon2(0.0);
    pentagon2 = pentagon1;
    EXPECT_EQ(pentagon1, pentagon2);
}

TEST(PentagonTest, MoveAssignmentOperator) {
    Pentagon pentagon1(5.0);
    Pentagon pentagon2(0.0);
    pentagon2 = std::move(pentagon1);
    EXPECT_DOUBLE_EQ(pentagon2.operator double(), 43.01193501472418);
}

TEST(ArrayTest, AddFigures) {
    Array <double> arr;
    arr.add(new Trapezoid(3.0, 4.0, 5.0));
    arr.add(new Rhombus(6.0, 8.0));
    
    EXPECT_EQ(arr.getSize(), 2);
}

TEST(ArrayTest, RemoveFigure) {
    Array <double>arr;
    arr.add(new Trapezoid(3.0, 4.0, 5.0));
    arr.add(new Rhombus(6.0, 8.0));
    arr.remove(0);
    EXPECT_EQ(arr.getSize(), 1);
}

TEST(ArrayTest, TotalArea) {
    Array <double>arr;
    arr.add(new Trapezoid(3.0, 4.0, 5.0));
    arr.add(new Rhombus(6.0, 8.0));
    
    double total = arr.totalArea();
    EXPECT_GT(total, 0.0);
}