#pragma once

#include <cmath>

class Visitor;

class Figure {  // base class in hierarchy
  public:
    virtual void accept(Visitor& v) const = 0;
    virtual ~Figure() {}
};

class Square;
class Circle;

class Visitor {  // abstract visitor
  public:
    virtual void visit(const Square& k) = 0;
    virtual void visit(const Circle& o) = 0;
    virtual ~Visitor() {}
};

class Square : public Figure {
  public:
    Square(int s) : side_(s) {}
    int getSide() const { return side_; }
    virtual void accept(Visitor& v) const { v.visit(*this); }

  private:
    int side_;
};

class Circle : public Figure {
  public:
    Circle(int r) : r_(r) {}
    int getRadius() const { return r_; }
    virtual void accept(Visitor& v) const { v.visit(*this); }

  private:
    int r_;
};

// Concrete visitors

class VisitorCountRect : public Visitor {
  public:
    VisitorCountRect() : count_(0) {}

    virtual void visit(const Square&) { ++count_; }
    virtual void visit(const Circle&) {}

    int get() const { return count_; }

  private:
    int count_;
};

class VisitorArea : public Visitor {
  public:
    VisitorArea() : area_(0.0) {}

    virtual void visit(const Square& s) { area_ += s.getSide() * s.getSide(); }
    virtual void visit(const Circle& c) {
        area_ += c.getRadius() * c.getRadius() * M_PI;
    }

    double getArea() const { return area_; }

  private:
    double area_;
};

class VisitMaxSquare : public Visitor {
  public:
    VisitMaxSquare() : maxSide_(0) {}

    virtual void visit(const Square& s) {
        if (s.getSide() > maxSide_) maxSide_ = s.getSide();
    }
    virtual void visit(const Circle&) {}

    int getMaxSide() const { return maxSide_; }

  private:
    int maxSide_;
};