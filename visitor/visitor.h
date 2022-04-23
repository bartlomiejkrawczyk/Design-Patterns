#pragma once
#include <iostream>

class Paragraph;
class Image;

class AbstractVisitor {
  public:
    virtual void visit(Paragraph&) = 0;
    virtual void visit(Image&) = 0;
};

class Element {  // Base Class
  public:
    virtual void accept(AbstractVisitor& v) = 0;
};

class Paragraph : public Element {
  public:
    virtual void accept(AbstractVisitor& v) {
        v.visit(*this);  // Calls visit(Paragraph&)
    }
    int symbols() { return 10; }
    int words() { return 3; }
};

class Image : public Element {
  public:
    virtual void accept(AbstractVisitor& v) {
        v.visit(*this);  // Calls visit(Image&)
    }
};

// Concrete visitor
class Statistics : public AbstractVisitor {
  public:
    Statistics() : symbols_(0), words_(0), images_(0) {}
    virtual void visit(Paragraph& p) {
        symbols_ += p.symbols();
        words_ += p.words();
    }
    virtual void visit(Image& i) {
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