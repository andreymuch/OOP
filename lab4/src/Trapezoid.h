#pragma once
#include "Figure.h"
#include "Point.h"

template <typename T>
class Trapezoid : public Figure<T> {
private:
    T a, b, h;

public:
    Trapezoid(T a = 1, T b = 1, T h = 1);

    virtual ~Trapezoid() = default;
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;

    std::unique_ptr<Point<T>> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const;
    void printVertices(std::ostream& os) const override;    
};



template <typename T>
Trapezoid<T>::Trapezoid(T a, T b, T h) : a(a), b(b), h(h) {}

template <typename T>
Trapezoid<T>::Trapezoid(const Trapezoid& other) : a(other.a), b(other.b), h(other.h) {}

template <typename T>
Trapezoid<T>::Trapezoid(Trapezoid&& other) noexcept : a(other.a), b(other.b), h(other.h) {
    other.a = 0;
    other.b = 0;
    other.h = 0;
}

template <typename T>
std::unique_ptr<Point<T>> Trapezoid<T>::center() const {
    auto centerPoint = std::make_unique<Point<T>>();
    centerPoint->setX((a + b) / 2.0);
    centerPoint->setY(h / 2.0);
    return centerPoint;
}
template <typename T>
void Trapezoid<T>::print(std::ostream& os) const {
    os << "Trapezoid(a=" << a << ", b=" << b << ", h=" << h << ")";
}

template <typename T>
void Trapezoid<T>::read(std::istream& is) {
    is >> a >> b >> h;
}

template <typename T>
Trapezoid<T>::operator double() const {
    return 0.5 * (a + b) * h;
}

template <typename T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid<T>& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        h = other.h;
    }
    return *this;
}

template <typename T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid<T>&& other) noexcept {
    if (this != &other) {
        a = std::move(other.a);
        b = std::move(other.b);
        h = std::move(other.h);
        other.a = 0;
        other.b = 0;
        other.h = 0;
    }
    return *this;
}

template <typename T>
bool Trapezoid<T>::operator==(const Trapezoid<T>& other) const {
    return a == other.a && b == other.b && h == other.h;
}

template <typename T>
void Trapezoid<T>::printVertices(std::ostream& os) const {
    T halfBase1 = a / 2;
    T halfBase2 = b / 2;
    T halfHeight = h / 2;
    os << "Coordinates of vertices: "
       << "(-" << halfBase1 << ", " << halfHeight << "), "
       << "(" << halfBase1 << ", " << halfHeight << "), "
       << "(" << halfBase2 << ", -" << halfHeight << "), "
       << "(-" << halfBase2 << ", -" << halfHeight << ")";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Trapezoid<T>& fig) {
    fig.printVertices(os);
    return os;
}
