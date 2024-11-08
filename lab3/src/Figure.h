#pragma once
#include <iostream>

class Figure {
public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual std::pair<double, double> center() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual operator double() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};



