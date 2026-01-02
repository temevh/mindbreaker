#ifndef CHAPTER_ONE_EVENTS_H
#define CHAPTER_ONE_EVENTS_H
#include "nlohmann/json.hpp"

#include <string>

#include "../Player/Player.h"
#include "../Interactions/Interactions.h"
#include "../GameState/GameState.h"

using json = nlohmann::json;

std::string checkPocket();
void twoDoors(GameState& gameState);
int numbersMinigame(GameState& gameState);
void firstEncounter(Player& player, nlohmann::json dialogueData);

#endif