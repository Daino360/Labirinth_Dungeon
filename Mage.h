//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_MAGE_H
#define PLATFORMDUNGEON_MAGE_H

#include "GameCharacter.h"
#include "Hero.h"

class Mage : virtual public Hero {
public:
    Mage();
    virtual void move(int x, int y); //override;
    //virtual int fight(GameCharacter& enemy) override;

private:
    int stick;
};


#endif //PLATFORMDUNGEON_MAGE_H
