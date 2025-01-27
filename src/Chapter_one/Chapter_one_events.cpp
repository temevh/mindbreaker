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
#include "../NPC/Npc.h"

using json = nlohmann::json;

std::string checkPocket() {
    std::string prompt = "Check your pocket?";
    char* options[2] = {"yes", "no"};

    std::string checked = selectionMenu(prompt, options, 2);
    if(checked == "no"){
        writeText("Whatever, its most likely empty anyways.", 10);
    }else if(checked == "yes"){
        writeText("It's empty. Guess I was just imagining stuff.", 10);
    }
    return checked;
}

void twoDoors(){
    std::string prompt = "Which door do you open?";
    char* options[2] = {"left door", "right door"};

    std::string checked = selectionMenu(prompt, options, 2);
    //Return which door was opened and use later?
    //Save users choices and use to add randomness?
}

int numbersMinigame(Player& player){
    clearScreen();
    int numbers[5]; //Change based on difficulty?
    int playerNumbers[5];
    for (int i = 0; i < 5; ++i){
        numbers[i] = generateRandomNumber(10);
    }
    for (auto num : numbers){
        int spaces = generateRandomNumber(10);
        for (int i = 1; i < spaces; i++){
            std::cout << " ";
        }
        std::cout << num << std::endl;
    }
    std::cout << std::endl;
    sleep(3);
    clearScreen();
    std::cout << "THE NUMBERS!! WHAT WERE THEY??\n" << std::endl;
    std::cout << "The numbers were: " << std::endl;
    
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);

    for (int i = 0; i < 5; ++i) {
        ss >> playerNumbers[i];
    }
    
    bool correct = true;
    for (int i = 0; i < 5; ++i){
        if (playerNumbers[i] != numbers[i]){
            correct = false;
            break;
        }
    }
    
    if (correct){
        return 1;
    } else {
        player.setSanity(player.getSanity() - 1);
        return 0;
    }

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
        writeText(dialogueData["firstEncounterPrompt"], player.getSanity());
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
                npcInteraction(npcs[selectedIndex], player);
            } else {
                std::cout << "Invalid selection." << std::endl;
            }
        }
    } else {
        std::cout << "The room seems to be mostly empty, with you being the only person there." << std::endl; 
    }
}