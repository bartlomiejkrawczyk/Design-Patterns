#pragma once

#include <iostream>

#include "observer.h"

class Clock : public Subject {
  public:
    Clock() : h(23), m(1) {}
    int min() const { return m; }
    int hour() const { return h; }
    void timer_tick() {
        ++m;
        h = (h + m / 60) % 24;
        m = m % 60;
        notify();
    }

  private:
    int h;
    int m;
};

// concrete observer
class Alarm : public Observer {
  public:
    Alarm(Clock &c, std::ostream &os, int h, int m)
        : clk_(c), os_(os), h_(h), m_(m) {
        clk_.add(this);
    }

    virtual void update() {
        if (clk_.min() == m_ && clk_.hour() == h_)
            // signal alarm
            os_ << "Alarm - " << h_ << ":" << m_ << std::endl;
    }

  private:
    Clock &clk_;
    std::ostream &os_;
    int h_;
    int m_;
};

class Display : public Observer {
  public:
    Display(Clock &c, std::ostream &os) : clk_(c), os_(os) { clk_.add(this); }

    virtual void update() {
        os_ << clk_.hour() << ":" << clk_.min() << std::endl;
    }

  private:
    Clock &clk_;
    std::ostream &os_;
};