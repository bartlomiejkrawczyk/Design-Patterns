#pragma once

#include <iostream>

class Rectangle;
class Circle;

struct Visitor {  // Base visitor
    virtual void visit(const Rectangle&) = 0;
    virtual void visit(const Circle&) = 0;
};

class Figure {
  public:
    virtual void accept(Visitor& v) const = 0;
};

class Rectangle : public Figure {
  public:
    virtual void accept(Visitor& v) const { v.visit(*this); }
};

class Circle : public Figure {
  public:
    virtual void accept(Visitor& v) const { v.visit(*this); }
};

double intersect(const Circle& a, const Circle& b) {
    (void)a;
    (void)b;
    return 0;
}
double intersect(const Circle& a, const Rectangle& b) {
    (void)a;
    (void)b;
    return 1;
}
double intersect(const Rectangle& a, const Circle& b) {
    (void)a;
    (void)b;
    return 2;
}
double intersect(const Rectangle& a, const Rectangle& b) {
    (void)a;
    (void)b;
    return 3;
}

double intersect(Figure& a, Figure& b);

struct RectangleVisitor : public Visitor {
    RectangleVisitor(const Rectangle& r) : r_(r), value_(0.0) {
        std::cout << "Rectangle visitor" << std::endl;
    }
    virtual void visit(const Rectangle& r) { value_ = intersect(r, r_); }
    virtual void visit(const Circle& c) { value_ = intersect(c, r_); }
    const Rectangle& r_;  // first object stored as a concrete type
    double value_;
};

struct CircleVisitor : public Visitor {
    CircleVisitor(const Circle& c) : c_(c), value_(0.0) {
        std::cout << "Circle visitor" << std::endl;
    }
    virtual void visit(const Circle& c) { value_ = intersect(c, c_); }
    virtual void visit(const Rectangle& r) { value_ = intersect(r, c_); }
    const Circle& c_;  // first object stored as a concrete type
    double value_;
};

struct IntersectVisitor : public Visitor {
    IntersectVisitor(Figure& fig) : fig_(fig), value_(0.0) {
        std::cout << "Intersect visitor" << std::endl;
    }
    virtual void visit(const Rectangle& r) {
        RectangleVisitor rectangleVisitor(r);
        fig_.accept(rectangleVisitor);
        value_ = rectangleVisitor.value_;
    }
    virtual void visit(const Circle& c) {
        CircleVisitor circleVisitor(c);
        fig_.accept(circleVisitor);
        value_ = circleVisitor.value_;
    }
    Figure& fig_;
    double value_;
};

double intersect(Figure& a, Figure& b) {
    IntersectVisitor visitor(a);
    b.accept(visitor);
    return visitor.value_;
}
