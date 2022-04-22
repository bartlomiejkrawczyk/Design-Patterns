#pragma once

// module for managing diagnostic communicates

#include <iostream>
#include <string>

// singleton for registration of communicates

class Logger {
  public:
    static Logger& getInstance() {
        static Logger logger;
        return logger;
    }

    // register message
    void msg(const std::string& m) {
        std::cout << ++counter_ << ":" << m << std::endl;
    }

  private:
    int counter_;
    Logger() : counter_(0) {}

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};