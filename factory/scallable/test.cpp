#include "factory.h"

int main() {
    FigureFactory factory;

    factory.registerFigure(0, createSquareFunction);
    factory.registerFigure(1, createCircleFunction);

    factory.create(0);
    factory.create(1);

    return 0;
}