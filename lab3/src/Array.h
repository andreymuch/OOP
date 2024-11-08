#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"


#pragma once
class Array {
private:
    std::unique_ptr<Figure*[]> figures;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity) {
        std::unique_ptr<Figure*[]> newFigures(new Figure*[newCapacity]);
        for (size_t i = 0; i < size; ++i) {
            newFigures[i] = figures[i];
        }
        figures = std::move(newFigures);
        capacity = newCapacity;
    }

public:
    Array();
    ~Array() ;
    void add(Figure* fig);
    friend std::istream& operator>>(std::istream& is, Array& arr);
    void remove(size_t index);
    size_t getSize() const;
    Figure* get(size_t index) const ;
    double totalArea() const ;
};
