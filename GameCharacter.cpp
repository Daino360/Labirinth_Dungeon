//
// Created by Stefano on 25/10/2017.
//

#include "GameCharacter.h"

//attributi di eroi e nemici
GameCharacter::GameCharacter(int h, int d, int a, int df) {
    hp = h;
    dexterity = d;
    attack = a;
    defense=df;
}
//Movimento di eroi e nemici
void GameCharacter::move(int x, int y) {
    posX += x;
    if (posX <= 0)
        posX = 0;
    posY += y;
    if (posY <= 0)
        posY = 0;
}
//Combattimento
int GameCharacter::fight(GameCharacter &enemy) {
    int damage = 1;//ogni attacco fa danno 1
    if (weapon != nullptr)
        damage = weapon->attack();
    enemy.hp -= damage; //il nemico perde vita
    return damage;
}