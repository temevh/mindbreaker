#include <stdio.h>
#include <fstream>
#include "nlohmann/json.hpp"
#include <iostream>

#include "../utils/UtilFunctions.h"

using json = nlohmann::json;


void chapterOneMain() {
    std::string fileName = "chapter_one_text.json";

    nlohmann::json dialogueData = loadJsonFromFile(fileName);

    writeText(dialogueData["intro"]);
    pressEnter();
    writeText(dialogueData["backstoryOne"]);
    pressEnter();
    writeText(dialogueData["backstoryTwo"]);
    pressEnter();

}