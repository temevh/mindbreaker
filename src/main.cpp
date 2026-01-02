#include <iostream>

#include "Player/Player.h"
#include "CharacterCreation/CharacterCreation.h"
#include "utils/UtilFunctions.h"
#include "Chapter_one/Chapter_one_main.h"
#include "GameState/GameState.h"

// Global gameState pointer
GameState* gameState = nullptr;

int main() {
    initializeRandomSeed();
    Player player = createPlayer();
    GameState localGameState(player);
    gameState = &localGameState; // Set the global pointer
    
    std::string prompt = "Are you ready?";
    char* options[2] = {"yes", "no"};

    std::string ready = selectionMenu(prompt, options, 2);
    if (ready == "yes") {
        clearScreen();
        std::string prompt = "Select difficulty";
        char* options[3] = {"easy", "medium", "hard"};
        std::string difficulty = selectionMenu(prompt, options, 3);
        if(difficulty == "easy"){
            gameState->setDifficulty(1);
        }else if (difficulty == "medium")
        {
            gameState->setDifficulty(2);
        }else if (difficulty == "hard"){
            gameState->setDifficulty(3);
        }
        
        //Go to chapter one
        chapterOneMain(localGameState);
    } else {
        std::cout << "\nMaybe next time!" << std::endl;
        return 0;
    }
    
    
    return 0;
}