#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    public:
        //Constructor
        Character(const std::string& name);

        //Getters
        std::string getName() const;

        //Setters
        void setName(const std::string& name);


    private:
        std::string name;



};

#endif // CHARACTER_H