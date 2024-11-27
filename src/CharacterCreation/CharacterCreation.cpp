#include "CharacterCreation.h"
#include <iostream>



std::string selectClass () {
    const char* classes[3] = {
        "Tech priest", "Cyber soldier", "Net assasin"
    };
    std::cout << "Select a fitting class for your adventure\n" << std::endl;
    for (int i = 0;i<3; i++){
        std::cout << classes[i] << "\n";
    }

    return "tech";

}

std::string selectName () {
    std::string charName;
    std::cout << "What is your name? ";
    std::getline(std::cin, charName);
    return charName;
}


Character createCharacter()
{
    std::string charName = selectName();
    std::string charClass = selectClass();

    std::cout << "Ah " << charName << " is a great name! It fits a fierce " << charClass << " like a charm" << std::endl;

    return Character(charName, charClass);
}
