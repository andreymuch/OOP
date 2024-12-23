#include <iostream>
#include <cmath>
#include "Pentagon.h"


double pi = atan(1)*4;

Pentagon::Pentagon(double side) : side(side) {
}

Pentagon::Pentagon(const Pentagon& other) : side(other.side), R(other.R) {}
Pentagon::Pentagon(Pentagon&& other) noexcept : side(other.side), R(other.R) {
    other.side = 0.0;
    other.R = 0.0;}

std::pair<double, double> Pentagon::center()const{
    return {0.0, 0.0};
}

void Pentagon::print(std::ostream& os)const{
    os << "pentagon side=" << side;
}

void Pentagon::read(std::istream& is) {
    is >> side;
    R = side / (2 * sin(atan(1)*4 / 5)); 
}

Pentagon::operator double()const{
    double area = (5.0 * side * (R * cos(pi / 5))) / 2.0;
    return area;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        side = other.side;
        R = side / (2 * sin(atan(1)*4 / 5)); 
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        side = other.side;
        R = side / (2 * sin(atan(1)*4 / 5)); 
        other.side = 0.0;
    }
    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    return side == other.side;
}

void Pentagon::printVertices(std::ostream& os) const {
        os << "Координаты: ";
        const double angleStep = 2 * pi / 5;
        for (int i = 0; i < 5; ++i) {
            double angle = i * angleStep;
            double x = R * cos(angle);
            double y = R * sin(angle);
            os << "(" << x << ", " << y << ")";
            if (i < 4) os << ", ";
        }
    }

std::ostream& operator<<(std::ostream& os, const Pentagon& fig) {
    fig.printVertices(os);
    return os;
}
