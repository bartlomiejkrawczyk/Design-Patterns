#pragma once
#include <iostream>
#include <map>

// =================================================================================
// Prototype Design Pattern

// abstract Figure class
class Figure {
  public:
    // virtual constructor
    virtual Figure* clone() = 0;
    // draws figure
    virtual void draw() = 0;

    virtual ~Figure(){};
};

class Rectangle : public Figure {
  public:
    Rectangle(int a, int b) : a_(a), b_(b) {}

    virtual Figure* clone() { return new Rectangle(*this); };
    virtual void draw() {
        std::cout << "Rectangle, sides: " << a_ << ", " << b_ << std::endl;
    }

  private:
    int a_;
    int b_;
};

class Circle : public Figure {
  public:
    Circle(int r) : r_(r) {}

    virtual Figure* clone() { return new Circle(*this); }
    virtual void draw() { std::cout << "Circle, radius: " << r_ << std::endl; }

  private:
    int r_;  // radius
};

// =================================================================================

class FigureCloneFactory {
  public:
    // Register new type in factory
    bool registerFigure(int id, Figure* prototype) {
        return prototypes_.insert(std::make_pair(id, prototype)).second;
    }

    // Create object of specific type
    Figure* create(int id) {
        auto i = prototypes_.find(id);
        if (i == prototypes_.end()) return nullptr;  // Error - unknown type

        // Call clone method on the right prototype
        return i->second->clone();
    }

  private:
    std::map<int, Figure*> prototypes_;
};