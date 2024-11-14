#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

int main() {
    Array<double> arr;

    std::cout << "Введите количество фигур и их тип (T - трапеция, P - пятиугольник, R - ромб):" << std::endl;
    std::cin >> arr;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        Figure<double>* fig = arr.get(i);
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        std::cout << "Центр : " << fig->center()->getX() << ", " << fig->center()->getY() << std::endl;
        std::cout << "Площадь: " << static_cast<double>(*fig) << std::endl;
        std::cout << *fig << std::endl;
        std::cout << std::endl;
    }
    Figure<double>* fig1 = arr.get(0);

    Trapezoid<double>* fig2 = dynamic_cast<Trapezoid<double>*>(fig1);
    if (fig2) {
        std::cout << "Это трапеция: " << *fig2 << std::endl;
    } else {
        std::cout << "fig1 не является трапецией." << std::endl;
    }

    Figure<double>* fig3 = arr.get(0);
    Figure<double>* fig4 = arr.get(1);

    Trapezoid<double>* trapezoid1 = dynamic_cast<Trapezoid<double>*>(fig3);
    Trapezoid<double>* trapezoid2 = dynamic_cast<Trapezoid<double>*>(fig4);

    if (trapezoid1 && trapezoid2) {
        std::cout << "Сравнение трапеций: " << (*trapezoid1 == *trapezoid2) << std::endl;
    } else {
        std::cout << "Обе фигуры не являются трапециями для сравнения." << std::endl;
    }

    Figure<double>* fig5 = arr.get(0);
    Trapezoid<double>* fig6 = dynamic_cast<Trapezoid<double>*>(fig5);

    if (fig6) {
        Trapezoid<double> movedTrapezoid = std::move(*fig6);
        std::cout << "Перемещенная трапеция: " << movedTrapezoid << std::endl;
    } else {
        std::cout << "fig5 не является трапецией для перемещения." << std::endl;
    }

    return 0;
}
