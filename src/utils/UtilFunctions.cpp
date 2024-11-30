#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include<array> 
#include <fstream>
#include <cstdlib>

#include "UtilFunctions.h"

#define KEY_UP 65    
#define KEY_DOWN 66  
#define KEY_ENTER 10   

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

std::string selectionMenu(std::string prompt, char* options[], int numChoices) {
    int selected = 0;
    bool selecting = true;

    while (selecting) {
        clearScreen();
        std::cout << prompt << std::endl;
        for (int i = 0; i < numChoices; ++i) {
            if (i == selected) {
                std::cout << "> " << options[i] << std::endl;
            } else {
                std::cout << "  " << options[i] << std::endl;
            }
        }

        char c = getch();
        if (c == '\033') { // if the first value is esc
            getch(); // skip the [
            switch (getch()) { // the real value
                case KEY_UP:
                    if (selected > 0) {
                        --selected;
                    }
                    break;
                case KEY_DOWN:
                    if (selected < numChoices - 1) {
                        ++selected;
                    }
                    break;
            }
        } else if (c == KEY_ENTER) {
            selecting = false;
        }
    }

    //std::cout << "Selected: " << options[selected] << std::endl;
    return options[selected];
}

void pressEnter(){
    std::cout << "\nPress ENTER to Continue \n";
    std::cin.ignore();
    clearScreen();
}

void writeText(std::string text){
    clearScreen();
    std::string s = text;
    for(const auto c: s){
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    std::cout << std::endl;
    pressEnter();
}

nlohmann::json loadJsonFromFile(const std::string& fileName){
    std::ifstream file(fileName);
    nlohmann::json jsonData;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return jsonData; // return an empty JSON if the file can't be opened
    }

    try {
        file >> jsonData; // Parse the JSON file
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
    }

    return jsonData;
}

void initializeRandomSeed() {
    srand(static_cast<unsigned int>(time(0)));
}

int generateRandomNumber(int maxNumber){
    int num = rand() % maxNumber;
    return num;
}