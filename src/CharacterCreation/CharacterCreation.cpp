#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "CharacterCreation.h"

#include "../Character/Character.h"
#include "../utils/UtilFunctions.h"

#define KEY_UP 65    
#define KEY_DOWN 66  
#define KEY_ENTER 10   

std::string selectName () {
    std::string charName;
    std::cout << "What is your name? ";
    std::getline(std::cin, charName);
    return charName;
}

Character createCharacter()
{
    Character character("", "", 100, 100);
    
    std::string charName = selectName();
    clearScreen();
    std::string charClass = selectClass();
    clearScreen();

    character.setCharName(charName);
    character.setCharClass(charClass);

    std::cout << "Ah " << charName << " is a great name "; 
    std::cout << "for a fierce " << charClass << " like you." << std::endl;
    std::cout << "For now you are healthy with " << character.getCharHealth() << " HP and ";
    std::cout << "you mind is also in good shape with " << character.getCharSanity() << " sanity" << std::endl;

    return character;
}
