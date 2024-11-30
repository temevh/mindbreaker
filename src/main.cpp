#include <iostream>
#include "Character/Character.h"
#include "CharacterCreation/CharacterCreation.h"
#include "utils/UtilFunctions.h"
#include "Chapter_one/Chapter_one_main.h"

int main() {
    initializeRandomSeed();
    Character player = createCharacter();
    /*
    std::string prompt = "Are you ready to begin your adventure?";
    char* options[2] = {"yes", "no"};

    std::string ready = selectionMenu(prompt, options, 2);
    if (ready == "yes") {
        clearScreen();
        chapterOneMain();
        //Go to chapter one
    } else {
        std::cout << "\nMaybe next time!" << std::endl;
    }
    */
    
   
   chapterOneMain(player);


    return 0;
}