#pragma once

#include <iostream>

class Figure {
  public:
    enum { SQUARE, CIRCLE };
    virtual bool save(std::ostream& os) = 0;
    virtual void read(std::istream& is) = 0;

    static Figure* create(std::istream& is);
};

class Square : public Figure {
  public:
    virtual bool save(std::ostream& os) {
        os << SQUARE;
        os << " s";
        return true;
    }
    virtual void read(std::istream& is) {
        std::cout << "Square" << std::endl;
        char s;
        is >> s;
    }
};

class Circle : public Figure {
  public:
    virtual bool save(std::ostream& os) {
        os << CIRCLE;
        os << " c";
        return true;
    }
    virtual void read(std::istream& is) {
        std::cout << "Circle" << std::endl;
        char c;
        is >> c;
    }
};

Figure* Figure::create(std::istream& is) {
    int type;
    is >> type;
    Figure* object;  // Loaded object
    switch (type) {
        case SQUARE:
            object = new Square;
            break;
        case CIRCLE:
            object = new Circle;
            break;

        default:
            // Error - unknown type
            return nullptr;
    }
    object->read(is);  // read attributes
    return object;
}