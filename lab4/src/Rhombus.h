#pragma once
#include "Figure.h"
#include "Point.h"

template <typename T>
class Rhombus : public Figure<T> {
private:
    T d1, d2;

public:
    Rhombus(T d1 = 1.0, T d2 = 1.0);
    virtual ~Rhombus() = default;

    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;

    std::unique_ptr<Point<T>> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    bool operator==(const Rhombus& other) const;
    void printVertices(std::ostream& os) const override;
};
template <typename T>
Rhombus<T>::Rhombus(T d1, T d2) : d1(d1), d2(d2) {}

template <typename T>
Rhombus<T>::Rhombus(const Rhombus<T>& other) : d1(other.d1), d2(other.d2) {}

template <typename T>
Rhombus<T>::Rhombus(Rhombus<T>&& other) noexcept : d1(other.d1), d2(other.d2) {
    other.d1 = 0;
    other.d2 = 0;
}

template <typename T>
std::unique_ptr<Point<T>> Rhombus<T>::center() const {
    auto centerPoint = std::make_unique<Point<T>>();
    centerPoint->setX(d1 / 2.0);
    centerPoint->setY(d2 / 2.0);
    
    return centerPoint;
}

template <typename T>
void Rhombus<T>::print(std::ostream& os) const {
    os << "Rhombus d1=" << d1 << ", d2=" << d2;
}

template <typename T>
void Rhombus<T>::read(std::istream& is) {
    is >> d1 >> d2;
}

template <typename T>
Rhombus<T>::operator double() const {
    return 0.5 * d1 * d2;
}

template <typename T>
Rhombus<T>& Rhombus<T>::operator=(const Rhombus<T>& other) {
    if (this != &other) {
        d1 = other.d1;
        d2 = other.d2;
    }
    return *this;
}

template <typename T>
Rhombus<T>& Rhombus<T>::operator=(Rhombus<T>&& other) noexcept {
    if (this != &other) {
        d1 = std::move(other.d1);
        d2 = std::move(other.d2);
        other.d1 = 0;
        other.d2 = 0;
    }
    return *this;
}

template <typename T>
bool Rhombus<T>::operator==(const Rhombus<T>& other) const {
    return d1 == other.d1 && d2 == other.d2;
}

template <typename T>
void Rhombus<T>::printVertices(std::ostream& os) const {
    os << "координаты: "
       << "(-" << d1 / 2 << ", 0), "
       << "(" << d1 / 2 << ", 0), "
       << "(0, -" << d2 / 2 << "), "
       << "(0, " << d2 / 2 << ")";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Rhombus<T>& fig) {
    fig.printVertices(os);
    return os;
}
