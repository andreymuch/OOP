#include <iostream>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

Array::Array() : size(0), capacity(10) {
    figures = std::make_unique<Figure*[]>(capacity);
}

Array::~Array() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
}

void  Array::add(Figure* fig) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    figures[size++] = fig;
}

std::istream& operator>>(std::istream& is, Array& arr) {
    size_t n;
    is >> n; 
    for (size_t i = 0; i < n; ++i) {
        char figureType;
        is >> figureType;
        Figure* newFig = nullptr;

        if (figureType == 'P') {
            double side;
            is >> side;
            newFig = new Pentagon(side);
        }
        else if (figureType == 'T') { 
            double a, b, h;
            is >> a >> b >> h;
            newFig = new Trapezoid(a, b, h);
        }
        else if (figureType == 'R') {
            double d1, d2;
            is >> d1 >> d2;
            newFig = new Rhombus(d1, d2);
        }
        if (newFig) {
            arr.add(newFig);
        }
    }

    return is;
}

void  Array::remove(size_t index) {
    if (index >= size) return;

    delete figures[index];
    for (size_t i = index; i < size - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    --size;
}

size_t  Array::getSize() const {
    return size;
}

Figure*  Array::get(size_t index) const {
    if (index >= size) return nullptr;
    return figures[index];
}

double  Array::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<double>(*figures[i]);
    }
    return total;
}
