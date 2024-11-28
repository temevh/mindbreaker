#include "Character.h"

Character::Character(const std::string& charName, const std::string& charClass,  int charHealth,  int charSanity)
    : charName(charName), charClass(charClass), charHealth(charHealth), charSanity(charSanity){}

//Getters
std::string Character::getCharName() const {
    return charName;
}

std::string Character::getCharClass() const {
    return charClass;
}

int Character::getCharHealth() const {
    return charHealth;
}

int Character::getCharSanity() const {
    return charSanity;
}


//Setters
void Character::setCharName(const std::string& charName) {
    this->charName = charName;
}

void Character::setCharClass(const std::string& charClass) {
    this->charClass = charClass;
}

void Character::setCharHealth(const int& charHealth){
    this->charHealth = charHealth;
}

void Character::setCharSanity(const int& charSanity){
    this->charSanity = charSanity;
}
