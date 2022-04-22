#pragma once

#include <iostream>
#include <string>

class Monster {
  public:
    Monster(std::string str) { std::cout << str << std::endl; }
};
class LittleMonster : public Monster {
  public:
    LittleMonster() : Monster("Little Monster") {}
};
class BigMonster : public Monster {
  public:
    BigMonster() : Monster("Big Monster") {}
};

class Wizard {
  public:
    Wizard(std::string str) { std::cout << str << std::endl; }
};
class Charlatan : public Wizard {
  public:
    Charlatan() : Wizard("Charlatan") {}
};
class Mage : public Wizard {
  public:
    Mage() : Wizard("Mage") {}
};

// Abstract factory

class AbstractCharacterFactory {
  public:
    virtual Monster* createMonster() = 0;
    virtual Wizard* createWizard() = 0;
};

class BeginerCharacterFactory : public AbstractCharacterFactory {
    virtual Monster* createMonster() { return new LittleMonster; }
    virtual Wizard* createWizard() { return new Charlatan; }
};

class AdvancedCharacterFactory : public AbstractCharacterFactory {
    virtual Monster* createMonster() { return new BigMonster; }
    virtual Wizard* createWizard() { return new Mage; }
};