#pragma once
#include "Figure.h"

class Trapezoid : public Figure {
private:
    double a, b, h;

public:
    Trapezoid(double a = 1, double b = 1, double h = 1);

    virtual ~Trapezoid() = default;
    Trapezoid(const Trapezoid&);
    Trapezoid(Trapezoid&& other) noexcept;

    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is);
    operator double() const override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other)const ;
    void printVertices(std::ostream& os) const override;

};
std::ostream& operator<<(std::ostream& os, const Trapezoid& fig);
