#include "Player.h"

Player::Player(const std::string& charName, const std::string& charClass, int charHealth, int sanity)
    : Character(charName, charClass, charHealth), sanity(sanity) {}

// Getter
int Player::getSanity() const {
    return sanity;
}

// Setter
void Player::setSanity(const int& charSanity) {
    this->sanity = charSanity;
}