#include "composite.h"

int main() {
    Composite composite1;
    Circle circle;
    Composite composite2;
    for (int i = 0; i < 3; ++i) {
        composite2.add(new Triangle);
    }
    composite1.add(&circle);
    composite1.add(&composite2);

    composite1.draw();

    return 0;
}