#pragma once

#include <iostream>
#include <string>

class Command {
  public:
    virtual void run() = 0;
};

class ConcreteCommand : public Command {
  public:
    ConcreteCommand(std::string s) : text_(s) {}
    virtual void run() { std::cout << text_ << std::endl; }

  private:
    std::string text_;
};
