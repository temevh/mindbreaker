#ifndef UTILFUNCTIONS_H
#define UTILFUNCTIONS_H

#include <string>
#include <nlohmann/json.hpp>
#include <vector>
#include "../GameState/GameState.h"

using nlohmann::json;


std::string selectionMenu(const std::string& prompt, const std::vector<std::string>& options);
void clearScreen();
void pressEnter();
void writeText(std::string text);
nlohmann::json loadJsonFromFile(const std::string& fileName);
int generateRandomNumber(int maxNumber);
void initializeRandomSeed();
std::string generateRandomName();
void dialogueText(std::vector<std::pair<std::string, std::string>> dialogues);
void runNPCDialogue(GameState& gameState, const std::string& npcName, const json& dialogueData);
std::string replaceAll(std::string text, const std::string& from, const std::string& to);

std::string generateId();

#endif