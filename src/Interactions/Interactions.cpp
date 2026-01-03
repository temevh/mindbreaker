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

int interactWithNpc(Character& npc, Character& player, GameState& gameState, const json& dialogueData){
    std::string npcName = npc.getCharName();
    std::vector<std::string> options = {"Talk", "Analyze"};

    std::string selectedOption = selectionMenu("What do you want to do?", options);
    std::cout << "You chose to " << selectedOption << "." << std::endl;
    
    if (selectedOption == "Talk"){
        runNPCDialogue(gameState, npcName, dialogueData);
    }
    return 0;
}   

void talkWithNpc(Character& npc, Character& player){

    std::cout << "NPC:" << npc.getCharName() << std::endl;
    std::cout << "player:" << player.getCharName() << std::endl;
    
    DialogueManager manager;

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

    manager.startDialogue("intro");


}

void talk(Character& npc, Character& player) {
    std::string talkPrompt = "What should you say?";
    std::string npcName = npc.getCharName();
    std::cout << "You talk with " << npcName << std::endl;
    std::vector<std::string> initialOptions = {"Who are you?", "Do you know where we are?"};
    std::string playerDialogue = selectionMenu(talkPrompt, initialOptions);

    std::vector<std::pair<std::string, std::string>> dialogues = {{"I am player", "player"}, {"I am an NPC", "npc"}};
    dialogues.push_back({playerDialogue, "player"});
    if (playerDialogue == "Who are you?") {
        std::string answer = "My name is " + npcName + ". What about you?";
        dialogues.push_back({answer, "npc"});
        dialogueText(dialogues);
    }

    std::vector<std::string> answerToQuestion = {"My name is...", "I would rather not answer"};
    std::string playerAnswer = selectionMenu("", answerToQuestion);

    dialogues.push_back({playerAnswer, "player"});
    dialogueText(dialogues);
}

