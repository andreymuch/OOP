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

Rhombus& Rhombus::operator=(const Rhombus& other){
    if (this != &other) {
        const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
        if (otherRhombus) {
            d1 = otherRhombus->d1;
            d2 = otherRhombus->d2;
        } else {
            throw std::invalid_argument("Rhombus Eror");
        }
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept{
    if (this != &other) {
        Rhombus& otherRhombus = static_cast<Rhombus&>(other);
        d1 = std::move(otherRhombus.d1);
        d2 = std::move(otherRhombus.d2);
        otherRhombus.d1 = 0.0;
        otherRhombus.d2 = 0.0;
    }
    return *this;
}

bool Rhombus::operator==(const Rhombus& other)const{
    const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    return otherRhombus && d1 == otherRhombus->d1 && d2 == otherRhombus->d2;
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