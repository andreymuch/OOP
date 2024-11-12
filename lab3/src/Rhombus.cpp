#include <iostream>
#include "Rhombus.h"

std::pair<double, double> Rhombus::center()const{
    return { d1 / 2.0, d2 / 2.0 };
}

Rhombus::Rhombus(const Rhombus& other) : d1(other.d1), d2(other.d2) {}

Rhombus::Rhombus(Rhombus&& other) noexcept : d1(other.d1), d2(other.d2) {
    other.d1 = 0.0;
    other.d2 = 0.0;
}

Rhombus::Rhombus(double d1, double d2) : d1(d1), d2(d2) {}

void Rhombus::print(std::ostream& os)const{
    os << "Rhombus d1=" << d1 << ", d2=" << d2;
}

void Rhombus::read(std::istream& is){
    is >> d1 >> d2;
}

Rhombus::operator double()const{
    return 0.5 * d1 * d2;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        d1 = other.d1;
        d2 = other.d2;
    }
    return *this;
}


Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        d1 = std::move(other.d1);
        d2 = std::move(other.d2);

        other.d1 = 0.0;
        other.d2 = 0.0;
    }
    return *this;
}


bool Rhombus::operator==(const Rhombus& other) const {
    return d1 == other.d1 && d2 == other.d2;
}


void Rhombus::printVertices(std::ostream& os) const{
        os << "координаты: "
           << "(-" << d1 / 2 << ", 0), "
           << "(" << d1 / 2 << ", 0), "
           << "(0, -" << d2 / 2 << "), "
           << "(0, " << d2 / 2 << ")";
    }

std::ostream& operator<<(std::ostream& os, const Rhombus& fig) {
    fig.printVertices(os);
    return os;
}