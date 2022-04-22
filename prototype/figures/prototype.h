#pragma once

// #include <iostream>

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

    virtual Figure* clone();
    virtual void draw();

   private:
    int a_;
    int b_;
};

class Circle : public Figure {
   public:
    Circle(int r) : r_(r) {}

    virtual Figure* clone();
    virtual void draw();

   private:
    int r_;  // radius
};