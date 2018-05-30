//
// Created by Stefano on 22/11/2017.
//

#include "Enemy.h"
#include "Die.h"

using namespace std;

GameCharacter *Enemy::GetEnemy() {

    GameCharacter *pEnemy = NULL;
    int enemyName;
    //for (int as=1;as<10;as++){
        //Casualità nemico
        Die::initRandom();
        Die die(4);
        int result = die.roll(1);
        if (result == 0) {
            enemyName = goblin;
            pEnemy = Enemy::Create(goblin, result);
            cout << "Your Enemy is a Goblin\n";
        } else if (result == 1) {
            enemyName = ghoul;
            pEnemy = Enemy::Create(ghoul, result);
            cout << "Your Enemy is a Ghoul\n";
        } else if (result == 2) {
            enemyName = orc;
            pEnemy = Enemy::Create(orc, result);
            cout << "Your Enemy is a Orc\n";
        } else if (result == 3) {
            enemyName = troll;
            pEnemy = Enemy::Create(troll, result);
            cout << "Your Enemy is a Troll\n";
        }
    //}
    return pEnemy;
}



Enemy* Enemy::Create(enumTypeEnemy type, int idEnemy)
{
    switch (type)
    {
        case goblin:
        {
            Enemy * h = new Enemy(goblin,10,80,30,5);
            h->setUpSpriteEnemy("goblinsword.png", idEnemy);
            return h;
            break;
        }
        case ghoul:
        {
            Enemy * h = new Enemy(ghoul,10,80,30,5);
            h->setUpSpriteEnemy("ghoul3.png", idEnemy);
            return h;
            break;
        }
        case orc:
        {
            Enemy * h = new Enemy(orc,10,80,30,5);
            h->setUpSpriteEnemy("orc2.png", idEnemy);
            return h;
            break;
        }
        case troll:
        {
            Enemy * h = new Enemy(troll,10,80,30,5);
            h->setUpSpriteEnemy("troll2.png", idEnemy);
            return h;
            break;
        }
    }
}

