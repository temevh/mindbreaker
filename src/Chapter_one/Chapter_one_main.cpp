#include <stdio.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>
#include <string> 

#include "../utils/UtilFunctions.h"
#include "Chapter_one_events.h"

using json = nlohmann::json;

void chapterOneMain() {
    std::string fileName = "chapter_one_text.json";

    nlohmann::json dialogueData = loadJsonFromFile(fileName);

    /*
    writeText(dialogueData["intro"]);
    for (int i = 1; i<3; i++){
        std::string line = "backstory_" + std::to_string(i);
        writeText(dialogueData[line]);
    }



    checkPocket();
    writeText(dialogueData["getUp"]);
    writeText(dialogueData["twoDoors"]);
    twoDoors();
    writeText(dialogueData["doorOpened"]);
    */
    numbersMinigame();

}