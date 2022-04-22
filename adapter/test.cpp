#include <iostream>

#include "class_adapter.h"
#include "object_adapter.h"

int main() {
    ObjectAdapter objectAdapter;
    std::cout << objectAdapter.method_1() << std::endl;

    ClassAdapter classAdapter;
    std::cout << classAdapter.method_1() << std::endl;

    return 0;
}