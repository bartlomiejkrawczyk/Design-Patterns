#pragma once

class ClassInterface {
   public:
    virtual int method_1() = 0;
};

class ClassAdaptee {
   public:
    int method1() { return 1; }
};

class ClassAdapter : public ClassInterface, private ClassAdaptee {
   public:
    virtual int method_1() { return method1(); }
};