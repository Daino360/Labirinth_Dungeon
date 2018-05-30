//
// Created by Stefano on 22/11/2017.
//

#include "Enemy.h"
#include "Factory.h"
#include "Die.h"

using namespace std;

Enemy *Enemy::GetEnemy() {

    Enemy *pEnemy = NULL;
    int enemyName;

    //Casualità nemico
    Die::initRandom();
    Die die(4);
    int result = die.roll(1);

    if (result == 0) {
        enemyName = goblin;
        pEnemy = Factory::Get()->CreateEnemy(enemyName);
        cout << "Your Enemy is a Goblin\n";
    } else if (result == 1) {
        enemyName = ghoul;
        pEnemy = Factory::Get()->CreateEnemy(enemyName);
        cout << "Your Enemy is a Ghoul\n";
    } else if (result == 2) {
        enemyName = orc;
        pEnemy = Factory::Get()->CreateEnemy(enemyName);
        cout << "Your Enemy is a Orc\n";
    } else if (result == 3) {
        enemyName = troll;
        pEnemy = Factory::Get()->CreateEnemy(enemyName);
        cout << "Your Enemy is a Troll\n";
    }
    return pEnemy;
}

Enemy *Factory::CreateEnemy(int &enemyName){

    FactoryMap::iterator it = m_FactoryMap.find(enemyName);
    if( it != m_FactoryMap.end() )
        return it->second();
    return NULL;
}
