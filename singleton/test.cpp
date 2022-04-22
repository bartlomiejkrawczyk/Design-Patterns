#include "logger.h"
#include "singleton.h"

void f() { Logger::getInstance().msg("funkcja f"); }

void g() { Singleton::getInstance(); }

int main() {
    Logger::getInstance().msg("start main");
    f();
    f();
    Logger::getInstance().msg("end main");

    g();
    g();
    g();

    return 0;
}
