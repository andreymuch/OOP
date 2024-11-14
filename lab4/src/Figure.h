#pragma once
#include <iostream>
#include "Point.h"

template <typename T>
class Figure {

public:
    Figure() = default;
    virtual ~Figure() = default;
    virtual std::unique_ptr<Point<T>> center() const = 0;
    virtual void print(std::ostream& os) const = 0;  
    virtual void read(std::istream& is) = 0;
    virtual operator double() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& fig) {
    fig.printVertices(os);
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Figure<T>& fig) {
    fig.read(is);
    return is;
}



