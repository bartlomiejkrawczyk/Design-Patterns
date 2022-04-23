#include "command.h"

void f(Command* cmd) { cmd->run(); }

int main() {
    Command* cmd1 = new ConcreteCommand("Hello, World - 1");
    Command* cmd2 = new ConcreteCommand("Hello, World - 2");

    cmd2->run();
    cmd1->run();
    cmd2->run();

    f(cmd1);
    f(cmd2);

    return 0;
}