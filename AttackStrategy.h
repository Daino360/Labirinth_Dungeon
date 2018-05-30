//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_ATTACKSTRATEGY_H
#define PLATFORMDUNGEON_ATTACKSTRATEGY_H

#include "Strategy.h"
#include "Enemy.h"

class AttackStrategy : public Strategy {
public:
    int slowAttack(); //slow per Orc e Troll
    int rapidAttack();//rapid per Goblin e Ghoul
    Enemy *getEnemy() const {
        return enemy;
    }

    void setEnemy(Enemy *enemy) {
        AttackStrategy::enemy = enemy;
    }
private:
    Enemy* enemy;

};

#endif //PLATFORMDUNGEON_ATTACKSTRATEGY_H
