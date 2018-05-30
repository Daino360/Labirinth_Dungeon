//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_ENEMY_H
#define PLATFORMDUNGEON_ENEMY_H

#include "GameCharacter.h"

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Enemy : public GameCharacter { // Enemy eredita da GameCharacter
public:
    //Enemy(){};
    Enemy(enumTypeEnemy tEnemy, int h, int d, int a, int df) : GameCharacter(h, d, a, df){ //Abbiamo tolto i costruttore di efault e messo la dipendenza dagli attributi di GameCharacter
        typeEnemy = tEnemy;

    }

    virtual void Free() = 0;
    static Enemy *GetEnemy();

private:
    enumTypeEnemy typeEnemy;

};
// Create function pointer
typedef Enemy* ( *CreateEnemyFn)(void);

// Enemy implementations
class Goblin : public Enemy {
public:
    Goblin(enumTypeEnemy tEnemy, int h, int d, int a, int df) : Enemy(tEnemy,h,d,a,df){}
    void Free() { delete this; }
    static Enemy * Create() { return new Goblin(goblin,10,80,30,5); }
};

class Ghoul : public Enemy {
public:
    Ghoul(enumTypeEnemy tEnemy, int h, int d, int a, int df) : Enemy(tEnemy,h,d,a,df){}
    void Free() { delete this; }
    static Enemy * Create() { return new Ghoul(ghoul,25,50,40,15); }
};

class Orc : public Enemy{ // Yeah it isn't really an animal... but you get the idea
public:
    Orc(enumTypeEnemy tEnemy, int h, int d, int a, int df) : Enemy(tEnemy,h,d,a,df){}
    void Free() { delete this; }
    static Enemy * Create() { return new Orc(orc,50,20,60,70); }
};

class Troll : public Enemy {
public:
    Troll(enumTypeEnemy tEnemy, int h, int d, int a, int df) : Enemy(tEnemy,h,d,a,df){}
    void Free() { delete this; }
    static Enemy * Create() { return new Troll(troll,100,20,100,100); }
};



#endif //PLATFORMDUNGEON_ENEMY_H
