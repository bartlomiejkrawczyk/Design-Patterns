#pragma once

#include <string>

// Interface
class Coffee {
   public:
    virtual std::string getIngredients() = 0;  // the ingredients of the coffee
};

// Object
class SimpleCoffee : public Coffee {  // Concrete class
   public:
    virtual std::string getIngredients() { return "Coffee"; }
};

class Decorator : public Coffee {
   public:
    Decorator(Coffee* c) : decorated_(c) {}

    virtual std::string getIngredients() {
        return decorated_->getIngredients();
    }

   private:
    Coffee* decorated_;
};

// Concrete Decorator
class Milk : public Decorator {
   public:
    Milk(Coffee* decorated) : Decorator(decorated) {}
    virtual std::string getIngredients() {
        return Decorator::getIngredients() + " Milk";
    }
};

// Concrete Decorator
class Sugar : public Decorator {
   public:
    Sugar(Coffee* decorated) : Decorator(decorated) {}
    virtual std::string getIngredients() {
        return Decorator::getIngredients() + " Sugar";
    }
};