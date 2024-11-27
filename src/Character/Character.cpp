#include "Character.h"


Character::Character(const std::string& name)
    : name(name){}

//Getters
std::string Character::getName() const {
    return name;
}


//Setters
void Character::setName(const std::string& name) {
    this->name = name;
}
