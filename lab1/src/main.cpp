#include <iostream>
#include "box_capacity.h"

int main() {
    int length, width, height = 0;
    std::cin >> length >> width >> height;
    std::cout << box_capacity(length, width, height) << std::endl;
    return 0;
}