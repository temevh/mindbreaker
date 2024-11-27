#include "CharacterCreation.h"
#include <iostream>

Character createCharacter() {
    std::string name;

    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    return Character(name);

}