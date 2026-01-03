#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
protected:
    std::string charName;
    std::string id;
    std::string charClass;
    int charHealth;

    public:
        //Constructor
        Character(const std::string &charName, const std::string &id, const std::string &charClass, int charHealth);

        // Getters
        std::string getCharName() const;
        std::string getCharClass() const;
        int getCharHealth() const;


        //Setters
        void setCharName(const std::string& charName);
        void setCharClass(const std::string& charClass);
        void setCharHealth(const int& charHealth);

};

#endif 