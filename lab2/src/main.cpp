#include "Money.h"
#include <iostream>
#include <string>

int main() {
    Money m1("123.45");
    Money m2("76.55");

    m1.printM();
    m2.printM();

    Money sum = m1.add(m2);
    sum.printM();

    Money diff = m1.subtract(m2);
    diff.printM();

    Money m3("100");
    Money m4("200");
    Money result = m3.add(m4);
    result.printM();

    return 0;
}
