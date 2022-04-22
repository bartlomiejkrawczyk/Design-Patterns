#pragma once

#include <vector>

// Abstract observer
// Observer or View or Slot
class Observer {
   public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

// Abstract target of observation
// Subject or Model or Signal
class Subject {
   public:
    void add(Observer* o) { obs_.push_back(o); }

    void notify() {  // call o->update() on every observer
        for (Observer* o : obs_) {
            o->update();
        }
    }
    virtual ~Subject(){};

   private:
    std::vector<Observer*> obs_;
};
