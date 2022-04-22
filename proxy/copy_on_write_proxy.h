#pragma once

class ObjectInterface {
  public:
    virtual int get() const = 0;
    virtual void set(int val) = 0;
    virtual ~ObjectInterface() {}
};

class CopyOnWriteProxy;

class Object : public ObjectInterface {
  public:
    Object(int val) : value_(val), count_(1) {}
    virtual int get() const { return value_; }
    virtual void set(int val) { value_ = val; }

  private:
    int value_;
    int count_;
    friend class CopyOnWriteProxy;
};

// Lazy copy for class Object, Object containst counter
class CopyOnWriteProxy : public ObjectInterface {
  public:
    CopyOnWriteProxy(int val) : obj_(new Object(val)) {}

    CopyOnWriteProxy(const CopyOnWriteProxy& c) { join(c.obj_); }
    ~CopyOnWriteProxy() { unjoin(); }

    int get() const { return obj_->get(); }
    void set(int val) {
        if (obj_->count_ == 1)
            obj_->set(val);
        else {
            --obj_->count_;
            obj_ = new Object(val);  // Deep copy
        }
    }

  private:
    void join(Object* o) {
        obj_ = o;
        ++obj_->count_;
    }
    void unjoin() {
        --obj_->count_;
        if (obj_->count_ == 0) delete obj_;
    }
    Object* obj_;
};