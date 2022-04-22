#include "nvi.h"

// test
int main() {
    Stack s;
    s.push(1.0);
    s.push(2.0);
    OperationAdd add(s);
    add.calculate();
    std::cout << s.top() << std::endl;
}