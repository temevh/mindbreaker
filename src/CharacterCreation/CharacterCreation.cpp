#include <iostream>

#include "../Player/Player.h"
#include "../utils/UtilFunctions.h"

#define KEY_UP 65    
#define KEY_DOWN 66  
#define KEY_ENTER 10   

std::string selectName() {
    clearScreen();
    std::string charName;
    std::cout << "What is your name? ";
    std::getline(std::cin, charName);
    return charName;
}

Player createPlayer() {
    std::string charName;
    std::string charClass;
    int charHealth = 100;
    int charSanity = 10;

    /*
    
    char* classes[4] = {
        "Tech priest", "Cyber soldier", "Net assassin", "Space Marine"
    };
    std::string prompt = "Select your class";
    
    charName = selectName();
    clearScreen();
    charClass = selectionMenu(prompt, classes, 4);
    clearScreen();
    */
    
    charName = "Teemu";
    charClass = "Tech priest";
    
    Player player(charName, charClass, charHealth, charSanity);

    /*
    std::cout << "Ah " << charName << " is a great name "; 
    std::cout << "for a fierce " << charClass << " like you." << std::endl;
    std::cout << "For now you are healthy with " << player.getCharHealth() << " HP and ";
    std::cout << "your mind is also in good shape with " << player.getSanity() << " sanity" << std::endl;
    pressEnter();
    */
    

    return player;
}

Character createNPC() {
    return Character("Nameless", "Tech priest", 100);
}
