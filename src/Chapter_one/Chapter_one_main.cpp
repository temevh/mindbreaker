#include <stdio.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include <string>

#include "../utils/UtilFunctions.h"
#include "Chapter_one_events.h"

#include "../GameState/GameState.h"

using json = nlohmann::json;

void chapterOneMain(GameState &gameState)
{
    Player &player = gameState.getPlayer();
    std::string fileName = "chapter_one_text.json";

    nlohmann::json dialogueData = loadJsonFromFile(fileName);
    nlohmann::json firstEncounterDialogue = loadJsonFromFile("first_encounter.json");

    //writeText(dialogueData["intro"]);
    //for (int i = 1; i < 4; i++)
    //{
    //    std::string line = "backstory_" + std::to_string(i);
    //    writeText(dialogueData[line]);
    //}
//
    //checkPocket();
    //writeText(dialogueData["getUp"]);
    //writeText(dialogueData["twoDoors"]);
    //twoDoors(gameState);
    //gameState.printGameState();
    //writeText(dialogueData["doorTouched"]);

    //int result = numbersMinigame(gameState);
    //writeText(result ? dialogueData["numbersMinigame"]["correct"] : dialogueData["numbersMinigame"]["incorrect"]);
    //writeText(dialogueData["doorOpened"]);

    firstEncounter(player, gameState, firstEncounterDialogue);
}