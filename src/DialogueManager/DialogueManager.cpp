#include "DialogueManager.h"
#include <iostream>

DialogueManager::DialogueManager() : currentDialogueId("") {}

void DialogueManager::loadDialogue(const std::string& id, const DialogueNode& node) {
    dialogueMap[id] = node;
}

void DialogueManager::startDialogue(const std::string& startId) {
    currentDialogueId = startId;
    while (currentDialogueId != "end") {
        DialogueNode& currentNode = dialogueMap[currentDialogueId];
        displayDialogue(currentNode);
        currentDialogueId = getPlayerChoice(currentNode);
    }
}

void DialogueManager::displayDialogue(const DialogueNode& node) {
    std::cout << "NPC: " << node.getNpcLine() << std::endl;
    const std::vector<std::pair<std::string, std::string>>& options = node.getOptions();
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i].first << std::endl;
    }
}

std::string DialogueManager::getPlayerChoice(const DialogueNode& node) {
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;

    const std::vector<std::pair<std::string, std::string>>& options = node.getOptions();
    if (choice > 0 && choice <= options.size()) {
        return options[choice - 1].second;
    }
    return "end"; 
}