#pragma once

// Degenerated bridge
// Pointer to implementation

class Foo {
  public:
    ~Foo() { delete pImpl_; }
    // Class interface
    // ...
  private:
    struct Impl;
    Impl* pImpl_;
};

struct Foo::Impl {
    // variables and private methods
};

Foo::Foo() { pImpl_ = new Impl; }