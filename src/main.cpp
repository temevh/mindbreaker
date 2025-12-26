#include <iostream>

#include "Player/Player.h"
#include "CharacterCreation/CharacterCreation.h"
#include "utils/UtilFunctions.h"
#include "Chapter_one/Chapter_one_main.h"
#include "GameState/GameState.h"

int main() {
    initializeRandomSeed();
    Player player = createPlayer();
    GameState gameState(player);
    
    std::string prompt = "Are you ready?";
    char* options[2] = {"yes", "no"};

    std::string ready = selectionMenu(prompt, options, 2);
    if (ready == "yes") {
        clearScreen();
        //Go to chapter one
        chapterOneMain(gameState);
    } else {
        std::cout << "\nMaybe next time!" << std::endl;
        return 0;
    }
    
    
    return 0;
}