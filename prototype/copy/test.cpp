#include <iostream>
#include <vector>

#include "prototype.h"

int main() {
    std::vector<Base*> vector;
    vector.push_back(new Derived1);
    vector.push_back(new Derived2);

    std::vector<Base*> shallow_copy_vector = vector;

    // std::vector<Base*> deep_copy_with_cutting_out;
    // for (const Base* base : vector) {
    //     deep_copy_with_cutting_out.push_back(
    //         new Base(*base));  // Cutting out, so do not allow to copy
    // }

    std::vector<Base*> deep_copy_vector;
    for (const Base* base : vector) {
        deep_copy_vector.push_back(base->clone());
    }

    for (const Base* base : deep_copy_vector) {
        std::cout << base->value << std::endl;
    }

    return 0;
}