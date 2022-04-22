#pragma once

class Base {
  public:
    Base(int val) : value(val){};
    virtual Base* clone() const = 0;  // Creates copy of the object
    Base(const Base&) = delete;       // Copy constructor not allowed

    int value;

  protected:
    Base() {}
};

class Derived1 : public Base {
  public:
    Derived1() : Base(1) {}
    Derived1(const Derived1& r) : Base() {  // Copy constructor
        this->value = r.value;
    }
    virtual Base* clone() const {
        return new Derived1(*this);  // Now, it is clear which type to copy!
    }
};

class Derived2 : public Base {
  public:
    Derived2() : Base(2) {}
    Derived2(const Derived2& r) : Base() {  // Copy constructor
        this->value = r.value;
    }
    virtual Base* clone() const {
        return new Derived2(*this);  // Now, it is clear which type to copy!
    }
};
