#include <iostream>
#include "Character/Character.h"
#include "CharacterCreation/CharacterCreation.h"
#include "utils/UtilFunctions.h"

int main() {
    Character player = createCharacter();
    std::string prompt = "Are you ready to begin your adventure?";
    char* options[2] = {"yes", "no"};

    std::string ready = selectionMenu(prompt, options, 2);
    if (ready == "yes") {
        std::cout << "\nGood" << std::endl;
        writeText(prompt);
        //Go to chapter one
    } else {
        std::cout << "\nMaybe next time!" << std::endl;
    }


    return 0;
}