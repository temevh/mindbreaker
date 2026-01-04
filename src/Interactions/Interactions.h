#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../GameState/GameState.h"
#include "../utils/UtilFunctions.h"
#include <nlohmann/json.hpp>

using nlohmann::json;

int interactWithNpc(Character& npc, Character& player, GameState& gameState, const json& dialogueData);

#endif
