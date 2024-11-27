#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    public:
        //Constructor
        Character(const std::string& charName, const std::string& charClass);

        //Getters
        std::string getCharName() const;
        std::string getCharClass() const;

        //Setters
        void setCharName(const std::string& charName);
        void setCharClass(const std::string& charClass);


    private:
        std::string charName;
        std::string charClass;

};

#endif // CHARACTER_H