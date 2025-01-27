#ifndef CHAPTER_ONE_EVENTS_H
#define CHAPTER_ONE_EVENTS_H
#include "nlohmann/json.hpp"

#include <string>

#include "../Player/Player.h"
#include "../Interactions/Interactions.h"

using json = nlohmann::json;

std::string checkPocket();
void twoDoors();
int numbersMinigame(Player& player);
void firstEncounter(Player& player, nlohmann::json dialogueData);

#endif