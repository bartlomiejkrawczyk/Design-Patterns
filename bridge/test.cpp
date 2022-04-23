#include "bridge.h"

int main() {
    ConcreteImplementation1 c1;
    ConcreteImplementation2 c2;

    RefineAbstraction1 r11(c1);
    RefineAbstraction1 r12(c2);

    r11.draw();
    r12.draw();

    RefineAbstraction2 r21(c1);
    RefineAbstraction2 r22(c2);

    r21.draw();
    r22.draw();

    return 0;
}