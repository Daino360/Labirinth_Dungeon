#include <iostream>
#include "Hero.h"
#include "Enemy.h"

int main() {
    Hero* Giovanni = new Hero("Giovanni",enumTypeHero::wizard,100,60,60,60);
    Enemy* Stefano = new Enemy(enumTypeEnemy::troll,1,2,20,20);

   int damo = Giovanni->fight(*Stefano);
    if (damo)
        std::cout << "Troll hit: " << damo << std::endl;
    if (Stefano->getHp() <= 0)
        std::cout << "troll is dead" << std::endl;
    return 0;

}