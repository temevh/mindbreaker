#include "Interactions.h"
#include "../utils/UtilFunctions.h"

#include <iostream>

void talkPlayerNpc(Character& npc, Character& player){
    std::cout << "player: " << player.getCharName() << std::endl;
    std::cout << "NPC: " << npc.getCharName() << std::endl;
}

int interactWithNpc (Character& npc, Character& player){
    std::string npcName = npc.getCharName();
    std::string talkOption = "Talk";
    std::string analyzeOption = "Analyze";

     
    const char* options[] = {talkOption.c_str(), analyzeOption.c_str()};

    //std::cout << "You interact with " << npc.getCharName() << std::endl;
    std::string selectedOption = selectionMenu("What do you want to do?", const_cast<char**>(options), 2);
    std::cout << "You chose to " << selectedOption << "." << std::endl;
    return 0;
}   
