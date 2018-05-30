//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_ENEMY_H
#define PLATFORMDUNGEON_ENEMY_H

#include "GameCharacter.h"

class Enemy : public GameCharacter { // Enemy eredita da GameCharacter
public:
    Enemy(enumTypeEnemy tEnemy, int h, int d, int a, int df) : GameCharacter(h, d, a, df){ //Abbiamo tolto i costruttore di efault e messo la dipendenza dagli attributi di GameCharacter
        typeEnemy = tEnemy;
    }
private:
    enumTypeEnemy typeEnemy;

};


#endif //PLATFORMDUNGEON_ENEMY_H
