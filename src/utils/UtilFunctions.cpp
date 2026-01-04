#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include<array> 
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include <vector>

#include "UtilFunctions.h"
#include "../GameState/GameState.h"

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

std::string selectionMenu(const std::string& prompt,
                  const std::vector<std::string>& options)
{
    int selected = 0;
    bool selecting = true;

    while (selecting) {
        clearScreen();
        std::cout << prompt << "\n\n";

        for (int i = 0; i < options.size(); ++i) {
            if (i == selected)
                std::cout << "> " << options[i] << "\n";
            else
                std::cout << "  " << options[i] << "\n";
        }

        char c = getch();
        if (c == '\033') {
            getch();
            switch (getch()) {
                case KEY_UP:
                    if (selected > 0) --selected;
                    break;
                case KEY_DOWN:
                    if (selected < options.size() - 1) ++selected;
                    break;
            }
        } else if (c == KEY_ENTER) {
            selecting = false;
        }
    }

    clearScreen();
    return options[selected];
}

void pressEnter(){
    std::cout << "\nPress ENTER to Continue \n";
    std::cin.ignore();
    clearScreen();
}

void writeText(std::string text){
    int sanity = gameState->getPlayer().getSanity();
    std::string s = text;
    int textSpeed = 30;



    if(sanity == 10){
        textSpeed = 30;
        for(const auto c: s){
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(textSpeed));
        }
    }else if (sanity < 10){
        textSpeed = (10 - sanity) * 10; 
        for(const auto c: s){
            if(generateRandomNumber(sanity) > 0){
                std::cout << c << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(textSpeed));
            }else{
                std::cout << " " << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(textSpeed));
            }
        }
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

std::string generateId(){
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(8);

    for (int i = 0; i < 8; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

std::string generateRandomName(){
    const char* firstNames[9] = {"Xavier", "Hunter", "Leo", "Sam", "Winston", "Rowan", "XE-15B", "Cerces", "Apollo"};
    std::string name = firstNames[generateRandomNumber(5)];
    return name;
}

void dialogueText(std::vector<std::pair<std::string, std::string>> dialogues) {
    clearScreen();
    for (const auto& pair : dialogues) {
        if (pair.second == "player") {
            writeText(pair.first);
        } else if (pair.second == "npc") {
            std::cout << std::setw(60) << " " << std::flush;
            writeText(pair.first);
        }
    }
}

void runNPCDialogue(GameState& gameState,
                    const std::string& npcId,
                    const json& dialogueData)
{
    NPCState& npc = gameState.getNPCState(npcId);
    gameState.meetNPC(npcId);

    while (true){
        const std::string& nodeKey = npc.dialogueNode;

        if (!dialogueData.contains(nodeKey)) {
            std::cerr << "Dialogue node not found: " << nodeKey << std::endl;
            return;
        }
        const json& node = dialogueData.at(nodeKey);

        std::cout << npc.name << ": "; 
        // Display text
        writeText(node["text"].get<std::string>());
        
        //  No choices → end interaction
        if (!node.contains("choices") || node["choices"].empty()) {
            return;
        }
        
        // Collect options
        std::vector<std::string> options;
        for (const auto& choice : node["choices"]) {
            options.push_back(choice["text"]);
        }
        
        //Player selection
        std::string result = selectionMenu("Choose your response", options);

        int selected = 0;
        for (size_t i = 0; i < options.size(); i++){
            if (options[i] == result){
                selected = i;
                break;
            }
        }

        const json& choice = node["choices"][selected];

        //Relationship change
        if (choice.contains("relationship")){
            npc.relationship += choice["relationship"].get<int>();
        }

        if (choice.contains("ask_name") && choice["ask_name"].get<bool>()){
            npc.name = npc.realName;
        }
        npc.dialogueNode = choice["next"].get<std::string>();

        gameState.recordChoice(npcId, npc.dialogueNode);
    }
    return;
}