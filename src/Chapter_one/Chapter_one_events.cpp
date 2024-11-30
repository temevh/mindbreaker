#include <string>
#include <stdio.h>

#include "../utils/UtilFunctions.h"

std::string checkPocket() {
    std::string prompt = "Check your pockets?";
    char* options[2] = {"yes", "no"};

    std::string checked = selectionMenu(prompt, options, 2);
    if(checked == "no"){
        clearScreen();
        writeText("Whatever, its most likely empty anyways.");
    }else if(checked == "yes"){
        clearScreen();
        writeText("Its empty. Guess I was just imagining stuff.");
    }
    return checked;
}