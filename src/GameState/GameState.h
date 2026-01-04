#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <unordered_map>
#include "../Player/Player.h"
#include "nlohmann/json.hpp"

class GameState; 
extern GameState* gameState;

struct NPCState {
    std::string name = "Stranger";
    std::string realName;
    std::string id = "";
    bool hasMet = false;
    int relationship = 0;
    std::string dialogueNode = "start";
};

class GameState
{
private:
    Player *player;
    int currentChapter;
    std::vector<int> completedChapters;
    std::map<std::string, bool> storyFlags;
    std::unordered_map<std::string, NPCState> npcStates;
    using Choice = std::pair<std::string, std::string>;
    std::vector<Choice> choicesHistory;
    std::map<std::string, int> npcRelationships;
    std::map<std::string, int> gameVariables;
    std::vector<std::string> inventory;

public:
    // Constructor
    GameState(Player &playerRef);

    // Player access
    Player &getPlayer();
    const Player &getPlayer() const;

    // Chapter management
    int getCurrentChapter() const;
    void setCurrentChapter(int chapter);
    void completeChapter(int chapter);
    bool isChapterCompleted(int chapter) const;
    const std::vector<int> &getCompletedChapters() const;

    // Story flags management
    void setStoryFlag(const std::string &flagName, bool value);
    bool getStoryFlag(const std::string &flagName) const;
    bool hasStoryFlag(const std::string &flagName) const;

    // Choices tracking
    void recordChoice(const std::string &choiceName, const std::string &selection);
    const std::vector<GameState::Choice> &getChoicesHistory() const;
    std::string getLastChoice() const;

    // NPC states
    NPCState& getNPCState(const std::string& npc);
    const NPCState& getNPCState(const std::string& npc) const;

    // NPC relationships
    bool hasMetNPC(const std::string& npc) const;
    void meetNPC(const std::string& npc);
    int getNPCRelationship(const std::string& npc) const;
    void setNPCRelationship(const std::string& npcName, int value);
    

    std::string getNPCDialogueNode(const std::string& npc) const;
    void setNPCDialogueNode(const std::string& npc, const std::string& node);


    // Game variables (for counters, timers, etc.)
    void setGameVariable(const std::string &varName, int value);
    int getGameVariable(const std::string &varName) const;
    void modifyGameVariable(const std::string &varName, int delta);
    void setDifficulty(int difficulty);
    int getDifficulty() const;

    // Inventory management
    void addItem(const std::string &item);
    bool hasItem(const std::string &item) const;
    void removeItem(const std::string &item);
    const std::vector<std::string> &getInventory() const;

    // Debug/utility
    void printGameState() const;
};

#endif
