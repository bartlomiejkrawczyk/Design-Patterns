#include "factory.h"

int main() {
    AbstractCharacterFactory* factory = new BeginerCharacterFactory;
    factory->createMonster();
    factory->createWizard();

    factory = new AdvancedCharacterFactory;
    factory->createMonster();
    factory->createWizard();

    return 0;
}