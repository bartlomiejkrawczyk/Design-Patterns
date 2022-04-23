#pragma once

#include <iostream>

class Implementation {
  public:
    virtual ~Implementation() = default;
    virtual void operation1() = 0;
    virtual void operation2() = 0;
};

class ConcreteImplementation1 : public Implementation {
  public:
    virtual void operation1() { std::cout << "operation 1.1" << std::endl; }
    virtual void operation2() { std::cout << "operation 1.2" << std::endl; }
};

class ConcreteImplementation2 : public Implementation {
  public:
    virtual void operation1() { std::cout << "operation 2.1" << std::endl; }
    virtual void operation2() { std::cout << "operation 2.2" << std::endl; }
};

class Abstraction {
  public:
    Abstraction(Implementation& implementation)
        : implementation_(implementation) {}
    virtual ~Abstraction() = default;

    virtual void draw() = 0;

  protected:
    Implementation& implementation_;
};

class RefineAbstraction1 : public Abstraction {
  public:
    RefineAbstraction1(Implementation& implementation)
        : Abstraction(implementation) {}

    virtual void draw() { implementation_.operation1(); }
};

class RefineAbstraction2 : public Abstraction {
  public:
    RefineAbstraction2(Implementation& implementation)
        : Abstraction(implementation) {}

    virtual void draw() { implementation_.operation2(); }
};