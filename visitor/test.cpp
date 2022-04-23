#include <vector>

#include "acyclic_visitor.h"
#include "visitor.h"
#include "visitors.h"

int main() {
    std::vector<Element*> elements;
    elements.push_back(new Image);
    elements.push_back(new Paragraph);
    elements.push_back(new Paragraph);
    Statistics s;
    for (Element* e : elements) {
        e->accept(s);
    }
    s.summary();

    // ==================================

    std::vector<MyElement*> myElements;
    myElements.push_back(new MyImage);
    myElements.push_back(new MyParagraph);
    myElements.push_back(new MyParagraph);
    Stats stats;
    for (MyElement* e : myElements) {
        e->accept(stats);
    }
    stats.summary();

    // ==================================

    std::vector<Figure*> fig;
    fig.push_back(new Square(10));
    fig.push_back(new Circle(3));
    fig.push_back(new Circle(1));

    VisitorCountRect counterRect;

    for (Figure* f : fig) f->accept(counterRect);
    std::cout << "Number of squares = " << counterRect.get() << std::endl;

    VisitorArea counterArea;

    for (Figure* f : fig) f->accept(counterArea);
    std::cout << "Area = " << counterArea.getArea() << std::endl;

    VisitMaxSquare maxSquare;

    for (Figure* f : fig) f->accept(maxSquare);
    std::cout << "Max side = " << maxSquare.getMaxSide() << std::endl;

    for (Figure* f : fig) delete f;

    return 0;
}