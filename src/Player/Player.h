#ifndef PLAYER_H
#define PLAYER_H

#include "../Character/Character.h"

class Player : public Character {
    private:
        int sanity;

    public:
        Player(const std::string& charName, const std::string& charClass, int charHealth, int sanity);

        int getSanity() const;

        void setSanity(const int& sanity);
};


#endif