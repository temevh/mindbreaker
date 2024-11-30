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

    int sanity = 7;

    
    writeText(dialogueData["intro"], sanity);
    for (int i = 1; i<3; i++){
        std::string line = "backstory_" + std::to_string(i);
        writeText(dialogueData[line], sanity);
    }

    checkPocket();
    writeText(dialogueData["getUp"], sanity);
    writeText(dialogueData["twoDoors"], sanity);
    twoDoors();
    writeText(dialogueData["doorOpened"], sanity);
    
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