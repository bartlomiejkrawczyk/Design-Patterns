
#include <sstream>

#include "factory.h"

int main() {
    Square square;
    Circle circle;

    std::stringstream ss;

    square.save(ss);

    std::cout << ss.str() << std::endl;
    // Figure* figSquare =
    Figure::create(ss);

    ss.str("");
    ss.clear();

    circle.save(ss);

    std::cout << ss.str() << std::endl;
    // Figure* figCircle =
    Figure::create(ss);

    return 0;
}