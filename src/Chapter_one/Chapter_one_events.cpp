#include <string>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <vector>
#include "nlohmann/json.hpp"

#include "../utils/UtilFunctions.h"
#include "../Player/Player.h"
#include "../CharacterCreation/CharacterCreation.h"
#include "../Interactions/Interactions.h"
#include "../GameState/GameState.h"

using json = nlohmann::json;

std::string checkPocket() {
    std::string prompt = "Check your pocket?";
    char* options[2] = {"yes", "no"};

    std::string checked = selectionMenu(prompt, options, 2);
    if(checked == "no"){
        writeText("Whatever, its most likely empty anyways.");
    }else if(checked == "yes"){
        writeText("It's empty. Guess I was just imagining stuff.");
    }
    return checked;
}

void twoDoors(GameState& gameState){
    std::string prompt = "Which door do you open?";
    char* options[2] = {"left door", "right door"};

    std::string checked = selectionMenu(prompt, options, 2);
    
    // Record the choice in history
    gameState.recordChoice("Two doors", checked);
    
    // Set story flags for easy conditional checks later
    if (checked == "left door") {
        gameState.setStoryFlag("chose_left_door", true);
    } else if (checked == "right door") {
        gameState.setStoryFlag("chose_right_door", true);
    }
}

int numbersMinigame(GameState& gameState) {
    clearScreen();

    int difficulty = gameState.getDifficulty() * 2;

    std::vector<int> numbers(difficulty);
    std::vector<int> playerNumbers(difficulty);

    for (int i = 0; i < difficulty; ++i) {
        numbers[i] = generateRandomNumber(10);
    }

    for (int i = 0; i < difficulty; ++i) {
        std::cout << std::string(generateRandomNumber(10), ' ')
                  << numbers[i] << '\n';
    }

    sleep(difficulty);
    clearScreen();

    std::cout << "THE NUMBERS!! WHAT WERE THEY??\n\n"; 
    std::cout << "Enter the numbers separated by spaces:\n";

    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    for (int i = 0; i < difficulty; ++i) {
        ss >> playerNumbers[i];
    }

    for (int i = 0; i < difficulty; ++i) {
        if (playerNumbers[i] != numbers[i]) {
            gameState.getPlayer().setSanity(
                gameState.getPlayer().getSanity() - 1);
            clearScreen();
            return 0;
        }
    }
    clearScreen();
    return 1;
}


void firstEncounter(Player& player, nlohmann::json dialogueData){
    int npcAmount = generateRandomNumber(5);
    std::vector<Character> npcs;
    for (int i = 0; i < npcAmount; ++i){
        npcs.push_back(createNPC());
    }

    if (npcAmount > 0){
        std::cout << "In the room with you there seems to be " << npcAmount << " other people." << std::endl;
        pressEnter();
        writeText(dialogueData["firstEncounterPrompt"]);
        char* options[2] = {"yes", "no"};
        std::string interact = selectionMenu("Interact with others?", options, 2);
        if(interact == "yes"){
            std::vector<std::string> npcOptions;
            for(int i = 0; i < npcAmount; i++){
                npcOptions.push_back("Person " + std::to_string(i + 1));
            }

            std::vector<const char*> cstrOptions;
            for (const auto& option : npcOptions) {
                cstrOptions.push_back(option.c_str());
            }

            std::string selectedPerson = selectionMenu("Which person do you want to interact with?", const_cast<char**>(cstrOptions.data()), npcAmount);
            std::cout << "You chose to interact with " << selectedPerson << "." << std::endl;

            int selectedIndex = std::stoi(selectedPerson.substr(7)) - 1;
            if (selectedIndex >= 0 && selectedIndex < npcAmount) {
                int result = interactWithNpc(npcs[selectedIndex], player);
            } else {
                std::cout << "Invalid selection." << std::endl;
            }
        }
    } else {
        std::cout << "The room seems to be mostly empty, with you being the only person there." << std::endl; 
    }
}