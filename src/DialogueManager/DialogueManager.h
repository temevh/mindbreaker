#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANAGER_H

#include <map>
#include <string>
#include "../DialogueNode/DialogueNode.h"

class DialogueManager {
public:
    // Constructor
    DialogueManager();

    // Load a dialogue node into the manager
    void loadDialogue(const std::string& id, const DialogueNode& node);

    // Start a dialogue with a given starting ID
    void startDialogue(const std::string& startId);

private:
    // Display the current dialogue node
    void displayDialogue(const DialogueNode& node);

    // Get the player's choice and return the next dialogue ID
    std::string getPlayerChoice(const DialogueNode& node);

    std::map<std::string, DialogueNode> dialogueMap; // Stores all dialogue nodes by ID
    std::string currentDialogueId; // Tracks the current dialogue ID
};
#endif // DIALOGUEMANAGER_H