#pragma once

#include <iostream>
#include <vector>

class Figure {
   public:
    virtual void draw() = 0;
    virtual ~Figure() {}
};

class Circle : public Figure {
   public:
    virtual void draw() { std::cout << "Circle" << std::endl; }
};

class Triangle : public Figure {
   public:
    virtual void draw() { std::cout << "Triangle" << std::endl; }
};

class Composite : public Figure {
   public:
    void add(Figure* child) { children_.push_back(child); }
    virtual void draw() {
        for (Figure* figure : children_) {
            figure->draw();
        }
    }

   private:
    std::vector<Figure*> children_;
};