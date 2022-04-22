#include <iostream>

#include "clock.h"

int main() {
    Clock clock;
    Alarm alarm1(clock, std::cout, 23, 5);
    Alarm alarm2(clock, std::cout, 23, 7);
    Display display(clock, std::cout);

    // Simulate clock
    for (int i = 0; i < 10; ++i) {
        std::cout << "----tick----" << std::endl;
        clock.timer_tick();
    }

    return 0;
}