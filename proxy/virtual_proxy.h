#pragma once

#include <iostream>

class Interface {
  public:
    virtual void operation() = 0;
};

// "Heavy" class, realizes the functionality
class RealObject : public Interface {
  public:
    virtual void operation() { std::cout << "RealObject" << std::endl; }
};

// "Light" class - handle
// Creates the object on first use
class VirtualProxy : public Interface {
  public:
    VirtualProxy() : real_(nullptr) {}
    virtual void operation() { getReal()->operation(); }  // mediates

  private:
    RealObject* real_;  // handle
    RealObject* getReal() {
        if (!real_) real_ = new RealObject;
        return real_;
    }
};