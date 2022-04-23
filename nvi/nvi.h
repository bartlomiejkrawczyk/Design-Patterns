/*  file demonstrates NVI pattern (non virtual interface) */
#include <deque>
#include <iostream>
#include <stack>

using Number = double;
using Stack = std::stack<Number>;

class Operation2Arg {
  public:
    Operation2Arg(Stack &st) : stack_(st) {}

    // interface, mutual code
    void calculate() {
        Number a = stack_.top();
        stack_.pop();
        Number b = stack_.top();
        stack_.pop();
        stack_.push(doCalculate(a, b));
    };

  private:
    // implementation, virtual function, NVI
    virtual Number doCalculate(Number, Number) = 0;
    Stack &stack_;
};

// addition
class OperationAdd : public Operation2Arg {
  public:
    OperationAdd(Stack &st) : Operation2Arg(st) {}

  private:
    // specific operation, addition
    virtual Number doCalculate(Number a, Number b) { return a + b; }
};
