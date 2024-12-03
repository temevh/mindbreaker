#include <iostream>


#include "Npc.h"
#include "../Character/Character.h"
#include "../utils/UtilFunctions.h"

void npcInteraction(Character& npc){
    std::string npcName = npc.getCharName();
    std::string talkOption = "Talk";
    std::string analyzeOption = "Analyze";

    const char* options[] = {talkOption.c_str(), analyzeOption.c_str()};

    //std::cout << "You interact with " << npc.getCharName() << std::endl;
    std::string selectedOption = selectionMenu("What do you want to do?", const_cast<char**>(options), 2);
    std::cout << "You chose to " << selectedOption << "." << std::endl;

    if (selectedOption == "Talk") {
        talk(npc);
    }
}   

void talk(Character& npc){
    std::cout<< "You talk with ???" << npc.getCharName() << std::endl;


}
