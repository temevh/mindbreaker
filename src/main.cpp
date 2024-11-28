#include <iostream>
#include "Character/Character.h"
#include "CharacterCreation/CharacterCreation.h"

int main() {
    std::cout << "Welcome to Mindbreaker!" << std::endl;

    Character player = createCharacter();
    char ready;

    std::cout << "\nAre you ready to begin your adventure? (y/n) " << std::endl;
    std::cin >> ready;
    if (ready == 'y') {
        std::cout << "\nGood" << std::endl;
        //Go to chapter one
    } else {
        std::cout << "\nMaybe next time!" << std::endl;
    }


    return 0;
}