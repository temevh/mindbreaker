#include "Interactions.h"
#include "../Character/Character.h"
#include "../utils/UtilFunctions.h"

#include "../DialogueNode/DialogueNode.h"

#include <iostream>
#include <vector>

void talkPlayerNpc(Character& npc, Character& player){
    std::cout << "player: " << player.getCharName() << std::endl;
    std::cout << "NPC: " << npc.getCharName() << std::endl;
}

int interactWithNpc(Character& npc, Character& player, GameState& gameState, const json& dialogueData){
    std::string npcName = npc.getCharName();
    std::vector<std::string> options = {"Talk", "Analyze"};

    std::string selectedOption = selectionMenu("What do you want to do?", options);
    std::cout << "You chose to " << selectedOption << "." << std::endl;
    
    if (selectedOption == "Talk"){
        runNPCDialogue(gameState, npcName, dialogueData);
        int relationship = gameState.getNPCRelationship(npcName);

         std::cout << "\nRelationship with " << npcName << ": " << relationship << std::endl;
    }
    return 0;
}   
