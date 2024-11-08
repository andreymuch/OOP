#include <iostream>
#include "Figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}