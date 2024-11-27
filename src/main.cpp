#include <iostream>
#include "Character/Character.h"
#include "CharacterCreation/CharacterCreation.h"

int main() {
    std::cout << "Welcome to Mindbreaker!" << std::endl;

    Character player = createCharacter();

    std::cout << "Ah " << player.getName() << " is a great name!"  <<std::endl;

    return 0;
}