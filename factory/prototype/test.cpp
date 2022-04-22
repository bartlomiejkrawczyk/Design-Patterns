#include "factory.h"

int main() {
    Rectangle rectangle(2, 4);
    Circle circle(1);

    FigureCloneFactory factory;

    factory.registerFigure(0, &rectangle);
    factory.registerFigure(1, &circle);

    factory.create(0)->draw();
    factory.create(1)->draw();
}