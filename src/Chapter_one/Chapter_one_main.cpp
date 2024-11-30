#include <stdio.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include <string> 

#include "../utils/UtilFunctions.h"
#include "Chapter_one_events.h"

#include "../Character/Character.h"

using json = nlohmann::json;

void chapterOneMain(Character& player) {
    std::string fileName = "chapter_one_text.json";

    nlohmann::json dialogueData = loadJsonFromFile(fileName);
    
    writeText(dialogueData["intro"], 10);
    for (int i = 1; i<3; i++){
        std::string line = "backstory_" + std::to_string(i);
        writeText(dialogueData[line], player.getCharSanity());
    }

    checkPocket();
    writeText(dialogueData["getUp"], player.getCharSanity());
    writeText(dialogueData["twoDoors"], player.getCharSanity());
    twoDoors();
    writeText(dialogueData["doorOpened"], player.getCharSanity());
    
    /*
    int result = numbersMinigame(player);
    if (result == 1){
        writeText(dialogueData["numbersCorrect"], 10);
    }else if (result == 0){
        std:: cout << player.getCharSanity() << std::endl;
        writeText(dialogueData["numbersIncorrect"], player.getCharSanity());
    }
    */
}