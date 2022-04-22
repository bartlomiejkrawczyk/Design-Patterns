/*  plik demonstruje wzorzec NVI (non virtual interface) */
#include <deque>
#include <iostream>
#include <stack>

using Number = double;
using Stack = std::stack<Number>;

// operacja dla kalkulatora w odwrotnej notacji polskiej
class Operation2Arg {
  public:
    Operation2Arg(Stack &st) : stack_(st) {}

    // interfejs, kod wspolny
    void calculate() {
        Number a = stack_.top();
        stack_.pop();
        Number b = stack_.top();
        stack_.pop();
        stack_.push(doCalculate(a, b));
    };

  private:
    // implementacja, funkcja wirtualna, NVI
    virtual Number doCalculate(Number, Number) = 0;
    Stack &stack_;
};

// dodawanie
class OperationAdd : public Operation2Arg {
  public:
    OperationAdd(Stack &st) : Operation2Arg(st) {}

  private:
    // specyficzna operacja, dodawanie
    virtual Number doCalculate(Number a, Number b) { return a + b; }
};
