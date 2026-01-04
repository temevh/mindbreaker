#include "Character.h"

Character::Character(const std::string& charName, const std::string& charId, const std::string& charClass, int charHealth)
    : charName(charName), charId(charId), charClass(charClass), charHealth(charHealth) {}

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

std::string Character::getCharId() const {
    return charId;
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

void Character::setCharId(const std::string& charId){
    this->charId = charId;
}