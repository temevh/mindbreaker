#include <string>
#include <stdio.h>
#include <iostream>

#include "../utils/UtilFunctions.h"

std::string checkPocket() {
    std::string prompt = "Check your pocket?";
    char* options[2] = {"yes", "no"};

    std::string checked = selectionMenu(prompt, options, 2);
    if(checked == "no"){
        writeText("Whatever, its most likely empty anyways.");
    }else if(checked == "yes"){
        writeText("It's empty. Guess I was just imagining stuff.");
    }
    return checked;
}

void twoDoors(){
    std::string prompt = "Which door do you open?";
    char* options[2] = {"left door", "right door"};

    std::string checked = selectionMenu(prompt, options, 2);
    //Return which door was opened and use later?
    //Save users choices and use to add randomness?
}

int numbersMinigame(){
    clearScreen();
    int numbers[5];
    for (int i = 0; i < 5; ++i){
        numbers[i] = generateRandomNumber(10);
    }
    for (auto num : numbers){
        int spaces = generateRandomNumber(10);
        for (int i = 1; i < spaces; i++){
            std::cout << " ";
        }
        std::cout << num << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
