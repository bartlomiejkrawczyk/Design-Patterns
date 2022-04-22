#pragma once

#include <iostream>

class Singleton {
  public:
    static Singleton* getInstance() {
        if (!pInstance_) pInstance_ = new Singleton;
        return pInstance_;
    }

  private:
    Singleton() {  // Private constructor
        std::cout << "Singleton Initialized" << std::endl;
    }
    Singleton(const Singleton&) = delete;             // forbidden, C++ 11
    Singleton& operator=(const Singleton&) = delete;  // forbidden, C++ 11
    static Singleton* pInstance_;
};

Singleton* Singleton::pInstance_ = nullptr;

// Presumably thread safe
// class ThreadSafeSingleton {
//   public:
//     static ThreadSafeSingleton& getInstance() {
//         static ThreadSafeSingleton singleton;
//         return singleton;
//     }

//   private:
//     ThreadSafeSingleton() {  // Private constructor
//         std::cout << "ThreadSafeSingleton Initialized" << std::endl;
//     }
//     ThreadSafeSingleton(const ThreadSafeSingleton&) =
//         delete;  // forbidden, C++ 11
//     ThreadSafeSingleton& operator=(const ThreadSafeSingleton&) =
//         delete;  // forbidden, C++ 11
//     static ThreadSafeSingleton* pInstance_;
// };