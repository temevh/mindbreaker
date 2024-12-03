#ifndef UTILFUNCTIONS_H
#define UTILFUNCTIONS_H

#include <string>
#include <nlohmann/json.hpp>

std::string selectionMenu(std::string prompt, char* options[], int numChoices);
void clearScreen();
void pressEnter();
void writeText(std::string text, int sanity);
nlohmann::json loadJsonFromFile(const std::string& fileName);
int generateRandomNumber(int maxNumber);
void initializeRandomSeed();
std::string generateRandomName();
void dialogueText(std::vector<std::pair<std::string, std::string>>);

#endif