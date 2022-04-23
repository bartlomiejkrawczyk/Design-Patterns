#pragma once

class Foo {};

class NeedsFoo {
  public:
    NeedsFoo(Foo* foo) : foo_(foo) {}

  private:
    Foo* foo_;
};

// example use case
// object injected is managed by derived class
class ConcreteNeedsFoo : public NeedsFoo {
    ConcreteNeedsFoo() : NeedsFoo(&foo_) {}

  private:
    Foo foo_;
};