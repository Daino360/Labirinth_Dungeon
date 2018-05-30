//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_MOVEMENTSTRATEGY_H
#define PLATFORMDUNGEON_MOVEMENTSTRATEGY_H

#include "Strategy.h"
#include "Enemy.h"

class MovementStrategy : public Strategy {
public:
    int patrollingMovement();
    int toHeroMovement();
    Enemy *getEnemy() const {
        return enemy;
    }

    void setEnemy(Enemy *enemy) {
        MovementStrategy::enemy = enemy;
    }
private:
    Enemy* enemy;

};

#endif //PLATFORMDUNGEON_MOVEMENTSTRATEGY_H
