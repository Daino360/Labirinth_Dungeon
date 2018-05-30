//
// Created by Stefano on 15/11/2017.
//

#ifndef PLATFORMDUNGEON_HERO_H
#define PLATFORMDUNGEON_HERO_H

#include "GameCharacter.h"
#include "Equipment.h"
#include <string>

class Hero : public GameCharacter {
public:
    explicit Hero(std::string n,int th, int e) : name(n), typeHero(th), element(e) {};
    Hero();
    int takeEquipment();
    int buy();
    Equipment *getEquipment() const {
        return equipment;
    }

    void setEquipment(Equipment *equipment) {
        Hero::equipment = equipment;
    }

protected:
    std::string name;
    int typeHero;
    int element;
    Equipment* equipment;
};


#endif //PLATFORMDUNGEON_HERO_H
