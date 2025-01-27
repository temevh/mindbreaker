#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANAGER_H

#include <map>
#include <string>
#include "../DialogueNode/DialogueNode.h"

class DialogueManager {
public:
    DialogueManager();

    void loadDialogue(const std::string& id, const DialogueNode& node);

    void startDialogue(const std::string& startId);

private:
    void displayDialogue(const DialogueNode& node);
    std::string getPlayerChoice(const DialogueNode& node);

    std::map<std::string, DialogueNode> dialogueMap;
    std::string currentDialogueId; 
};
#endif 