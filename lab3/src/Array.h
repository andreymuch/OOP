#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"


#pragma once
class Array {
private:
    Figure** figures;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    Array();
    ~Array() ;
    void add(Figure* fig);
    void remove(size_t index);
    size_t getSize() const;
    Figure* get(size_t index) const ;
    double totalArea() const ;
};
std::istream& operator>>(std::istream& is, Array& arr);
