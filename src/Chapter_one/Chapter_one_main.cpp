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

    /*
    writeText(dialogueData["intro"]);
    for (int i = 1; i<3; i++){
        std::string line = "backstory_" + std::to_string(i);
        writeText(dialogueData[line]);
    }

    checkPocket(player);
    writeText(dialogueData["getUp"]);
    writeText(dialogueData["twoDoors"]);
    twoDoors(player);
    writeText(dialogueData["doorOpened"]);
    */
    int result = numbersMinigame(player);
    if (result == 1){
        writeText(dialogueData["numbersCorrect"]);
        std:: cout << player.getCharSanity() << std::endl;
    }else if (result == 0){
        writeText(dialogueData["numbersIncorrect"]);
        std:: cout << player.getCharSanity() << std::endl;
    }
}