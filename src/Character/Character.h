#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    public:
        //Constructor
        Character(const std::string &charName, const std::string &charClass, int charHealth, int charSanity);

        // Getters
        std::string getCharName() const;
        std::string getCharClass() const;
        int getCharHealth() const;
        int getCharSanity() const;

        //Setters
        void setCharName(const std::string& charName);
        void setCharClass(const std::string& charClass);
        void setCharHealth(const int& charHealth);
        void setCharSanity(const int& charSanity);


    private:
        std::string charName;
        std::string charClass;
        int charHealth;
        int charSanity;

};

#endif 