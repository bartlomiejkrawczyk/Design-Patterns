#pragma once

#include <iostream>
#include <memory>

class Foo {
   public:
    Foo(int v) : val_(v) { std::cout << "Foo constructor" << std::endl; }
    int get() const { return val_; }
    void set(int v) { val_ = v; }

   private:
    int val_;
};

class LazyFoo {
   public:
    LazyFoo(int i) : ptr_(new Foo(i)) {}
    LazyFoo(const LazyFoo &l) : ptr_(l.ptr_) {}
    int get() const { return ptr_->get(); }
    void set(int i) {
        if (ptr_.unique()) {
            ptr_->set(i);
        } else {
            ptr_ = PFoo(new Foo(i));  // Deep copy
        }
    }

   private:
    typedef std::shared_ptr<Foo> PFoo;
    PFoo ptr_;
};