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
//Combattimento dall'eroe al nemico
int GameCharacter::fight(GameCharacter &enemy) {
    int damage = 1;//ogni attacco fa danno 1
    damage=damage+attack;
    if (weapon != nullptr)
        damage = weapon->attack();
    enemy.hp -= damage; //il nemico perde vita
    return damage;
}
int GameCharacter::fightHero(GameCharacter &hero) {
    int damageEnemy;//ogni attacco fa danno 1
    damageEnemy=attack;
    hero.hp-=damageEnemy;//il eroe perde vita
    return damageEnemy;
}
