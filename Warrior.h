//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_WARRIOR_H
#define PLATFORMDUNGEON_WARRIOR_H


#include "GameCharacter.h"
#include "Hero.h"

class Warrior : virtual public Hero {
public:
   // Warrior(int sword=1, int element, int typeHero, std::string n);
    Warrior();
    virtual void move(int x, int y); //override;
    //virtual int fight(GameCharacter& enemy) override;



private:
    int sword;
};


#endif //PLATFORMDUNGEON_WARRIOR_H
