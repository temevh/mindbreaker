#include <iostream>
#include <vector>


#include "Npc.h"
#include "../Character/Character.h"
#include "../utils/UtilFunctions.h"

void npcInteraction(Character& npc, Character& player){
    std::string npcName = npc.getCharName();
    std::string talkOption = "Talk";
    std::string analyzeOption = "Analyze";

    const char* options[] = {talkOption.c_str(), analyzeOption.c_str()};

    //std::cout << "You interact with " << npc.getCharName() << std::endl;
    std::string selectedOption = selectionMenu("What do you want to do?", const_cast<char**>(options), 2);
    std::cout << "You chose to " << selectedOption << "." << std::endl;

    if (selectedOption == "Talk") {
        talk(npc, player);
    }
}   

void talk(Character& npc, Character& player){
    std::string talkPrompt = "What should you say?";
    std::cout<< "You talk with ???" << npc.getCharName() << std::endl;
    char* talkOptions[2] = {"Who are you?", "Do you know where we are?"};
    std::string playerDialogue = selectionMenu(talkPrompt, talkOptions, 2);

    std::vector<std::pair<std::string, std::string>> dialogues = {{"I am player", "player"}, {"I am an NPC", "npc"}};

    //dialogueText function
    dialogueText(dialogues);

}
