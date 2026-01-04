#include "Interactions.h"
#include "../Character/Character.h"
#include "../utils/UtilFunctions.h"

#include "../DialogueNode/DialogueNode.h"

#include <iostream>
#include <vector>

int interactWithNpc(Character& npc, Character& player, GameState& gameState, const json& dialogueData){
    std::string npcId = npc.getCharId();
    std::vector<std::string> options = {"Talk", "Analyze"};

    std::string selectedOption = selectionMenu("What do you want to do?", options);
    std::cout << "You chose to " << selectedOption << "." << std::endl;
    clearScreen();
    if (selectedOption == "Talk"){
        runNPCDialogue(gameState, npcId, dialogueData);
        int relationship = gameState.getNPCRelationship(npcId);

        std::cout << "\nRelationship with " << npcId << ": " << relationship << std::endl;
        gameState.printGameState();
    }
    return 0;
}   
