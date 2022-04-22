#include <vector>

#include "prototype.h"

int main() {
    std::vector<Figure *> v;
    v.push_back(new Rectangle(2, 3));
    v.push_back(new Circle(1));
    v.push_back(new Circle(4));

    for (Figure *f : v) {
        f->draw();
    }

    std::vector<Figure *> w;
    for (Figure *f : v) {
        w.push_back(f->clone());
    }

    for (Figure *f : w) {
        f->draw();
    }

    for (Figure *f : v) {
        delete f;
    }

    for (Figure *f : w) {
        f->draw();
    }

    for (Figure *f : w) {
        delete f;
    }
    return 0;
}