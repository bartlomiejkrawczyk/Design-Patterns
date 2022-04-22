#include <iostream>

#include "decorator.h"

int main() {
    std::cout << Sugar(new Milk(new SimpleCoffee)).getIngredients()
              << std::endl;

    return 0;
}