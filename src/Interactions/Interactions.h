#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../utils/UtilFunctions.h"


void talkPlayerNpc(Character& npc, Character& player);
int interactWithNpc (Character& npc, Character& player);
void talkWithNpc(Character& npc, Character& player);

#endif
