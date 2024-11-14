#pragma once
#include "Figure.h"
#include<iostream>
#include <cmath>

template <typename T>
class Pentagon : public Figure<T> {
private:
    T side;
    T R;

public:
    Pentagon(T side = 1.0);

    virtual ~Pentagon() = default;
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;

    std::unique_ptr<Point<T>> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    bool operator==(const Pentagon& other) const;
    void printVertices(std::ostream& os) const override;
};
template <typename T>
Pentagon<T>::Pentagon(T side) : side(side), R(side / (2 * std::sin(atan(1)*4 / 5))) {}

template <typename T>
Pentagon<T>::Pentagon(const Pentagon& other) : side(other.side), R(other.R) {}

template <typename T>
Pentagon<T>::Pentagon(Pentagon&& other) noexcept : side(other.side), R(other.R) {
    other.side = 0.0;
    other.R = 0.0;
}

template <typename T>
 std::unique_ptr<Point<T>> Pentagon<T>::center() const {
    auto centerPoint = std::make_unique<Point<T>>();
    centerPoint->setX(0);
    centerPoint->setY(0);
    return centerPoint;
}

template <typename T>
void Pentagon<T>::print(std::ostream& os) const {
    os << "Pentagon side=" << side;
}

template <typename T>
void Pentagon<T>::read(std::istream& is) {
    is >> side;
    R = side / (2 * std::sin(atan(1)*4 / 5));
}

template <typename T>
Pentagon<T>::operator double() const {
    T area = (5.0 * side * (R * std::cos(atan(1)*4 / 5))) / 2.0;
    return area;
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon& other) {
    if (this != &other) {
        side = other.side;
        R = other.R;
    }
    return *this;
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        side = std::move(other.side);
        R = std::move(other.R);
        other.side = 0.0;
        other.R = 0.0;
    }
    return *this;
}

template <typename T>
bool Pentagon<T>::operator==(const Pentagon& other) const {
    return side == other.side;
}

template <typename T>
void Pentagon<T>::printVertices(std::ostream& os) const {
    os << "Coordinates: ";
    const T angleStep = 2 * atan(1)*4 / 5;
    for (int i = 0; i < 5; ++i) {
        T angle = i * angleStep;
        T x = R * std::cos(angle);
        T y = R * std::sin(angle);
        os << "(" << x << ", " << y << ")";
        if (i < 4) os << ", ";
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& fig) {
    fig.printVertices(os);
    return os;
}


