#include <iostream>
#include "Character/Character.h"
#include "CharacterCreation/CharacterCreation.h"

int main() {
    std::cout << "Welcome to Mindbreaker!" << std::endl;

    Character player = createCharacter();

    std::cout << "Ah " << player.getCharName() << " is a great name "; 
    std::cout << "for a fierce " << player.getCharClass() << " like you." << std::endl;

    return 0;
}