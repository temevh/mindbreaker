#include "Interactions.h"
#include "../Character/Character.h"
#include "../utils/UtilFunctions.h"

#include "../DialogueManager/DialogueManager.h"
#include "../DialogueNode/DialogueNode.h"

#include <iostream>
#include <vector>

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
    if (selectedOption == "Talk"){
        talkWithNpc(npc, player);
    }
    return 0;
}   

void talkWithNpc(Character& npc, Character& player){

    std::cout << "NPC:" << npc.getCharName() << std::endl;
    std::cout << "player:" << player.getCharName() << std::endl;
    
     DialogueManager manager;

    // Load dialogue nodes
    manager.loadDialogue("intro", DialogueNode(
        "Hello, traveler! What brings you here?",
        {{"I'm looking for adventure.", "adventure"},
         {"I need directions.", "directions"}}
    ));

    manager.loadDialogue("adventure", DialogueNode(
        "Adventure, you say? Be careful out there!",
        {{"Thanks for the warning!", "end"}}
    ));

    manager.loadDialogue("directions", DialogueNode(
        "The town is to the east. Follow the path.",
        {{"Thank you!", "end"}}
    ));

    // Start the dialogue
    manager.startDialogue("intro");


}

void talk(Character& npc, Character& player) {
    std::string talkPrompt = "What should you say?";
    std::string npcName = npc.getCharName();
    std::cout << "You talk with " << npcName << std::endl;
    const char* initialOptions[2] = {"Who are you?", "Do you know where we are?"};
    std::string playerDialogue = selectionMenu(talkPrompt, const_cast<char**>(initialOptions), 2);

    std::vector<std::pair<std::string, std::string>> dialogues = {{"I am player", "player"}, {"I am an NPC", "npc"}};
    dialogues.push_back({playerDialogue, "player"});
    if (playerDialogue == "Who are you?") {
        std::string answer = "My name is " + npcName + ". What about you?";
        dialogues.push_back({answer, "npc"});
        dialogueText(dialogues);
    }

    const char* answerToQuestion[2] = {"My name is...", "I would rather not answer"};
    std::string playerAnswer = selectionMenu("", const_cast<char**>(answerToQuestion), 2);

    dialogues.push_back({playerAnswer, "player"});
    dialogueText(dialogues);
}

