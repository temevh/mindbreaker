#include <iostream>


#include "Npc.h"
#include "../Character/Character.h"

void npcInteraction(Character& npc){
    std::cout << "You interact with " << npc.getCharName() << std::endl;
}   