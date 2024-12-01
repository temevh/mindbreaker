#include <stdio.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include <string> 

#include "../utils/UtilFunctions.h"
#include "Chapter_one_events.h"

#include "../Player/Player.h"

using json = nlohmann::json;

void chapterOneMain(Player& player) {
    std::string fileName = "chapter_one_text.json";

    nlohmann::json dialogueData = loadJsonFromFile(fileName);
    
    
    writeText(dialogueData["intro"], 10);
    for (int i = 1; i<4; i++){
        std::string line = "backstory_" + std::to_string(i);
        writeText(dialogueData[line], player.getSanity());
    }

    checkPocket();
    writeText(dialogueData["getUp"], player.getSanity());
    writeText(dialogueData["twoDoors"], player.getSanity());
    twoDoors();
    writeText(dialogueData["doorTouched"], player.getSanity());
    
    
    int result = numbersMinigame(player);
    //int result = 0;
    if (result == 1){
        writeText(dialogueData["numbersCorrect"], player.getSanity());
    }else if (result == 0){
        writeText(dialogueData["numbersIncorrect"], player.getSanity());
    }
    writeText(dialogueData["doorOpened"], player.getSanity());
    
}