#include "GameState.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Constructor
GameState::GameState(Player& playerRef) 
    : player(&playerRef), currentChapter(1) {
}

// Player access
Player& GameState::getPlayer() {
    return *player;
}

const Player& GameState::getPlayer() const {
    return *player;
}

// Chapter management
int GameState::getCurrentChapter() const {
    return currentChapter;
}

void GameState::setCurrentChapter(int chapter) {
    currentChapter = chapter;
}

void GameState::completeChapter(int chapter) {
    if (std::find(completedChapters.begin(), completedChapters.end(), chapter) == completedChapters.end()) {
        completedChapters.push_back(chapter);
    }
}

bool GameState::isChapterCompleted(int chapter) const {
    return std::find(completedChapters.begin(), completedChapters.end(), chapter) != completedChapters.end();
}

const std::vector<int>& GameState::getCompletedChapters() const {
    return completedChapters;
}

// Story flags management
void GameState::setStoryFlag(const std::string& flagName, bool value) {
    storyFlags[flagName] = value;
}

bool GameState::getStoryFlag(const std::string& flagName) const {
    auto it = storyFlags.find(flagName);
    if (it != storyFlags.end()) {
        return it->second;
    }
    return false;
}

bool GameState::hasStoryFlag(const std::string& flagName) const {
    return storyFlags.find(flagName) != storyFlags.end();
}

// Choices tracking
void GameState::recordChoice(const std::string& choiceName,  const std::string& selection) {
    choicesHistory.push_back({choiceName, selection});
}

const std::vector<GameState::Choice>& GameState::getChoicesHistory() const {
    return choicesHistory;
}

std::string GameState::getLastChoice() const {
    if (!choicesHistory.empty()) {
        return choicesHistory.back().second;
    }
    return "";
}

// NPC relationships
void GameState::setNPCRelationship(const std::string& npcName, int value) {
    npcRelationships[npcName] = value;
}

int GameState::getNPCRelationship(const std::string& npcName) const {
    auto it = npcRelationships.find(npcName);
    if (it != npcRelationships.end()) {
        return it->second;
    }
    return 0;
}

void GameState::modifyNPCRelationship(const std::string& npcName, int delta) {
    npcRelationships[npcName] += delta;
}

// Game variables
void GameState::setGameVariable(const std::string& varName, int value) {
    gameVariables[varName] = value;
}

int GameState::getGameVariable(const std::string& varName) const {
    auto it = gameVariables.find(varName);
    if (it != gameVariables.end()) {
        return it->second;
    }
    return 0;
}

void GameState::modifyGameVariable(const std::string& varName, int delta) {
    gameVariables[varName] += delta;
}

void GameState::setDifficulty(int difficulty) {
    gameVariables["difficulty"] = difficulty;
}

int GameState::getDifficulty() const {
    return getGameVariable("difficulty");
}


// Inventory management
void GameState::addItem(const std::string& item) {
    if (!hasItem(item)) {
        inventory.push_back(item);
    }
}

bool GameState::hasItem(const std::string& item) const {
    return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
}

void GameState::removeItem(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
    }
}

const std::vector<std::string>& GameState::getInventory() const {
    return inventory;
}

// Debug/utility
void GameState::printGameState() const {
    std::cout << "\n===== GAME STATE DEBUG =====\n";
    std::cout << "Player: " << player->getCharName() << " (" << player->getCharClass() << ")\n";
    std::cout << "Health: " << player->getCharHealth() << " | Sanity: " << player->getSanity() << "\n";
    std::cout << "Current Chapter: " << currentChapter << "\n";
    
    std::cout << "Completed Chapters: ";
    for (int chapter : completedChapters) {
        std::cout << chapter << " ";
    }
    std::cout << "\n";
    
    std::cout << "Story Flags (" << storyFlags.size() << "):\n";
    for (const auto& flag : storyFlags) {
        std::cout << "  " << flag.first << ": " << (flag.second ? "true" : "false") << "\n";
    }
    
    std::cout << "Choices History (" << choicesHistory.size() << "):\n";
    for (size_t i = 0; i < choicesHistory.size(); ++i) {
        std::cout << "  " << (i+1) << ". " << choicesHistory[i].first << ": " << choicesHistory[i].second << "\n";
    }
    
    std::cout << "Inventory (" << inventory.size() << "):\n";
    for (const auto& item : inventory) {
        std::cout << "  - " << item << "\n";
    }
    
    std::cout << "============================\n\n";
}
