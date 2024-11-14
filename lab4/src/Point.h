#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Point {
private:
    T x, y;

public:
    Point(T x = T(), T y = T()) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    bool operator==(const Point<T>& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point<T>& other) const {
        return !(*this == other);
    }
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& point);
    friend std::istream& operator>>(std::istream& is, Point<T>& point);
};
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
    template <typename T>
    std::istream& operator>>(std::istream& is, Point<T>& point) {
        is >> point.x >> point.y;
        return is;
    }

