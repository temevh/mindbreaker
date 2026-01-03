#include "Character.h"

Character::Character(const std::string& charName, const std::string& id, const std::string& charClass, int charHealth)
    : charName(charName), id(id), charClass(charClass), charHealth(charHealth) {}

// Getters
std::string Character::getCharName() const {
    return charName;
}

std::string Character::getCharClass() const {
    return charClass;
}

int Character::getCharHealth() const {
    return charHealth;
}

// Setters
void Character::setCharName(const std::string& charName) {
    this->charName = charName;
}

void Character::setCharClass(const std::string& charClass) {
    this->charClass = charClass;
}

void Character::setCharHealth(const int& charHealth) {
    this->charHealth = charHealth;
}