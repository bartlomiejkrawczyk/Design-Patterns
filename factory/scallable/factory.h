#pragma once

#include <iostream>
#include <map>
#include <string>

class Figure {
  public:
    Figure(std::string fig) : fig(fig) { std::cout << fig << std::endl; }
    std::string fig;
};

class Square : public Figure {
  public:
    Square() : Figure("Square") {}
};
class Circle : public Figure {
  public:
    Circle() : Figure("Circle") {}
};

// Scallable Factory
class FigureFactory {
  public:
    using createFigureFunction = Figure* (*)();

    // Register new type in factory
    bool registerFigure(int id, createFigureFunction callback) {
        return callbacks_.insert(std::make_pair(id, callback)).second;
    };

    // Create object of type
    Figure* create(int id) {
        std::map<int, Figure* (*)()>::const_iterator i = callbacks_.find(id);
        if (i == callbacks_.end()) {
            return nullptr;  // Error - unknown type
        }
        return (i->second)();
    }

  private:
    std::map<int, Figure* (*)()> callbacks_;
};

// Creators for specific type
Figure* createSquareFunction() { return new Square; }
Figure* createCircleFunction() { return new Circle; }
