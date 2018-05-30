//
// Created by Stefano on 25/10/2017.
//

#include "GameCharacter.h"
GameCharacter::GameCharacter(int h, int d, int a, int df) {
    hp = h;
    dexterity = d;
    attack = a;
    defense=df;
}
void GameCharacter::move(int x, int y) {
    posX += x;
    if (posX <= 0)
        posX = 0;
    posY += y;
    if (posY <= 0)
        posY = 0;
}

int GameCharacter::fight(GameCharacter &enemy) {
    int damage = 1;
    if (weapon != nullptr)
        damage = weapon->attack();
    enemy.hp -= damage;
    return damage;
}


