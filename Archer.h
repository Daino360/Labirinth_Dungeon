//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_ARCHER_H
#define PLATFORMDUNGEON_ARCHER_H

#include "GameCharacter.h"
#include "Hero.h"

class Archer : virtual public Hero {
public:
    Archer();
    virtual void move(int x, int y); //override;
    //virtual int fight(GameCharacter& enemy) override;

private:
    int bow;
};


#endif //PLATFORMDUNGEON_ARCHER_H
