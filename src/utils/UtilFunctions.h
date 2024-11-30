#ifndef UTILFUNCTIONS_H
#define UTILFUNCTIONS_H

#include <string>

std::string selectionMenu(std::string prompt, char* options[], int numChoices);
void clearScreen();
void pressEnter();
void writeText(std::string text);

#endif