#ifndef UTILFUNCTIONS_H
#define UTILFUNCTIONS_H

#include <string>
#include <nlohmann/json.hpp>

std::string selectionMenu(std::string prompt, char* options[], int numChoices);
void clearScreen();
void pressEnter();
void writeText(std::string text);
nlohmann::json loadJsonFromFile(const std::string& fileName);

#endif