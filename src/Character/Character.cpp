#include "Character.h"


Character::Character(const std::string& charName, const std::string& charClass)
    : charName(charName), charClass(charClass){}

//Getters
std::string Character::getCharName() const {
    return charName;
}

std::string Character::getCharClass() const {
    return charClass;
}


//Setters
void Character::setCharName(const std::string& charName) {
    this->charName = charName;
}

void Character::setCharClass(const std::string& charClass) {
    this->charClass = charClass;
}
