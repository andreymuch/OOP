#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"

int main() {
    Array arr;

    std::cout << "n \n T-Trap(a,b,h) P-pentagon(side) R -rhomb(d):" << std::endl;
    std::cin >> arr;

    
    for (size_t i = 0; i <  arr.getSize(); ++i) {
        Figure* fig = arr.get(i);
        std::cout << "Фигура" << i+1 << ":" << std::endl;
        std::cout << "Центр : " << fig->center().first << ", " << fig->center().second << std::endl;
        std::cout << "Площадь: " << double(*fig) << std::endl;
        std::cout << *fig << std::endl;
        std::cout <<  std::endl;
    }


    Figure* fig1 = arr.get(0);
    Trapezoid* fig2 = new Trapezoid();
    fig2 = (Trapezoid*)(fig1);

    std::cout<<"= " << *fig2 << std::endl;

    Figure* fig3 = arr.get(0);
    Figure* fig4 = arr.get(1);
    std::cout <<"== "<< (*(Trapezoid*)(fig3) == *(Trapezoid*)(fig4)) << std::endl;


    Figure* fig5 = arr.get(0);
    Trapezoid* fig6 = new Trapezoid();
    *fig6 = std::move(*(Trapezoid*)(fig5));

    std::cout <<"move "<< *fig6 << std::endl;
    return 0;
}