#include <iostream>
#include <stdexcept>
#include "Figure.h"
#include "Trapezoid.h"

Trapezoid::Trapezoid(double a, double b, double h) : a(a), b(b), h(h) {
}

Trapezoid::Trapezoid(const Trapezoid& other) : a(other.a), b(other.b), h(other.h) {
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept : a(other.a), b(other.b), h(other.h) {
    other.a = 0.0;
    other.b = 0.0;
    other.h = 0.0;
}

std::pair<double, double> Trapezoid::center() const{
        return { (a + b) / 2.0, h / 2.0 };
    }

void Trapezoid::print(std::ostream& os)const {
        os << "Trapezoid(a=" << a << ", b=" << b << ", h=" << h << ")";
    }

void Trapezoid::read(std::istream& is){
        is >> a >> b >> h;
    }

Trapezoid::operator double()const {
        return 0.5 * (a + b) * h;
    }

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        h = other.h;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        Trapezoid& otherTrapezoid = static_cast<Trapezoid&>(other);
        a = std::move(otherTrapezoid.a);
        b = std::move(otherTrapezoid.b);
        h = std::move(otherTrapezoid.h);

        otherTrapezoid.a = 0.0;
        otherTrapezoid.b = 0.0;
        otherTrapezoid.h = 0.0;
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    return otherTrapezoid && a == otherTrapezoid->a && b == otherTrapezoid->b && h == otherTrapezoid->h;
}

void  Trapezoid::printVertices(std::ostream& os) const{
    double halfBase1 = a / 2;
    double halfBase2 = b / 2;
    double halfHeight = h / 2;
    os << "координаты: "
        << "(-" << halfBase1 << ", " << halfHeight << "), "
        << "(" << halfBase1 << ", " << halfHeight << "), "
        << "(" << halfBase2 << ", -" << halfHeight << "), "
        << "(-" << halfBase2 << ", -" << halfHeight << ")";
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& fig) {
    fig.printVertices(os);
    return os;
}

