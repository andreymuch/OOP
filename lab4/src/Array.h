#pragma once

#include <iostream>
#include "Figure.h"

template <typename T>
class Array {
private:
    std::unique_ptr<Figure<T> *[]> figures;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity) {
        std::unique_ptr<Figure<T> *[]> newFigures(new Figure<T>*[newCapacity]);
        for (size_t i = 0; i < size; ++i) {
            newFigures[i] = figures[i];
        }
        figures = std::move(newFigures);
        capacity = newCapacity;
    }

public:
    Array();
    ~Array();
    void add(Figure<T>* fig);
    void remove(size_t index);
    size_t getSize() const;
    Figure<T>* get(size_t index) const;
    T totalArea() const;
};

template <typename T>
Array<T>::Array() : size(0), capacity(10) {
    figures = std::make_unique<Figure<T>*[]>(capacity);
}

template <typename T>
Array<T>::~Array() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
}

template <typename T>
void Array<T>::add(Figure<T>* fig) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    figures[size++] = fig;
}

template <typename T>
std::istream& operator>>(std::istream& is, Array<T>& arr) {
    size_t n;
    is >> n;
    for (size_t i = 0; i < n; ++i) {
        char figureType;
        is >> figureType;
        Figure<T>* newFig = nullptr;

        if (figureType == 'P') {
            T side;
            is >> side;
            newFig = new Pentagon<T>(side);
        }
        else if (figureType == 'T') {
            T a, b, h;
            is >> a >> b >> h;
            newFig = new Trapezoid<T>(a, b, h);
        }
        else if (figureType == 'R') {
            T d1, d2;
            is >> d1 >> d2;
            newFig = new Rhombus<T>(d1, d2);
        }
        if (newFig) {
            arr.add(newFig);
        }
    }
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    for (size_t i = 0; i < arr.getSize(); ++i) {
        os << arr.get(i) << " ";
    }
    return os;
}


template <typename T>
void Array<T>::remove(size_t index) {
    if (index >= size) return;

    delete figures[index];
    for (size_t i = index; i < size - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    --size;
}


template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
Figure<T>* Array<T>::get(size_t index) const {
    if (index >= size) return nullptr;
    return figures[index];
}


template <typename T>
T Array<T>::totalArea() const {
    T total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<T>(*figures[i]);
    }
    return total;
}
