#include <stdio.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>

#include "../utils/UtilFunctions.h"
#include "Chapter_one_events.h"

using json = nlohmann::json;

void chapterOneMain() {
    std::string fileName = "chapter_one_text.json";

    nlohmann::json dialogueData = loadJsonFromFile(fileName);

    writeText(dialogueData["intro"]);
    writeText(dialogueData["backstory_1"]);
    writeText(dialogueData["backstory_2"]);
    writeText(dialogueData["backstory_3"]);
    
    checkPocket();


}