#include "prototype.h"

#include <iostream>

Figure* Rectangle::clone() { return new Rectangle(*this); }

void Rectangle::draw() {
    std::cout << "Rectangle, sides: " << a_ << ", " << b_ << std::endl;
}

Figure* Circle::clone() { return new Circle(*this); }

void Circle::draw() { std::cout << "Circle, radius: " << r_ << std::endl; }
