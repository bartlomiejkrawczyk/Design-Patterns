#pragma once

class ObjectInterface {
  public:
    virtual int method_1() = 0;
};

class ObjectAdaptee {
  public:
    int method1() { return 1; }
};

class ObjectAdapter : public ObjectInterface {
  public:
    virtual int method_1() { return obj_.method1(); }

  private:
    ObjectAdaptee obj_;
};