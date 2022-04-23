#pragma once

#include <iostream>

// Base class for visitors
class AcyclicVisitor {
  public:
    virtual ~AcyclicVisitor() {}
};

class MyElement {  // Base Class
  public:
    virtual void accept(AcyclicVisitor& v) = 0;
};

class MyParagraph : public MyElement {
  public:
    virtual void accept(AcyclicVisitor& v);
    int symbols() { return 10; }
    int words() { return 3; }
};

class MyImage : public MyElement {
  public:
    virtual void accept(AcyclicVisitor& v);
};

// Abstract Visitor for every class in visited hierarchy
class ParagraphVisitor : public virtual AcyclicVisitor {
  public:
    virtual void visit(MyParagraph&) = 0;
};

// Abstract Visitor for every class in visited hierarchy
class ImageVisitor : public virtual AcyclicVisitor {
  public:
    virtual void visit(MyImage&) = 0;
};

// Implementation of a accept function
void MyParagraph::accept(AcyclicVisitor& v) {
    if (ParagraphVisitor* p = dynamic_cast<ParagraphVisitor*>(&v))
        p->visit(*this);
}

// Implementation of a accept function
void MyImage::accept(AcyclicVisitor& v) {
    if (ImageVisitor* i = dynamic_cast<ImageVisitor*>(&v)) i->visit(*this);
}

// Concrete visitor
class Stats : public virtual AcyclicVisitor,
              public ParagraphVisitor,
              public ImageVisitor {
  public:
    Stats() : symbols_(0), words_(0), images_(0) {}

    virtual void visit(MyParagraph& p) {
        symbols_ += p.symbols();
        words_ += p.words();
    }
    virtual void visit(MyImage& i) {
        ++images_;
        (void)i;
    }

    void summary() {
        std::cout << "Symbols: " << symbols_ << std::endl;
        std::cout << "Words: " << words_ << std::endl;
        std::cout << "Images: " << images_ << std::endl;
    }

  private:
    int symbols_;
    int words_;
    int images_;
};