#include <iostream>

#include "multimethod.h"

int main() {
    Circle c1;
    Circle c2;
    Rectangle r1;
    Rectangle r2;

    Figure* f1 = &c1;
    Figure* f2 = &c2;
    Figure* f3 = &r1;
    Figure* f4 = &r2;

    std::cout << intersect(*f1, *f2) << std::endl;
    std::cout << intersect(*f1, *f4) << std::endl;
    std::cout << intersect(*f3, *f2) << std::endl;
    std::cout << intersect(*f3, *f4) << std::endl;
    return 0;
}