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

void GameCharacter::setUpSprite(std::string textureFileName){
    if (!tx.loadFromFile(textureFileName)){
        std::cout << "Texture Error" << std::endl;
    }
    characterSprite.setTexture(tx);
    characterSprite.scale(2.0f, 2.0f); // reduce dimensions of Character (right dimensions: 0.1f)
    characterSprite.setPosition(790, 10); // initial position of Character*/

}

void GameCharacter::setUpSpriteEnemy(std::string textureFileName, int idEnemy){
    //for (numEnemy=0;numEnemy<10;numEnemy++){
        int x1,y1,x2,y2;
    switch (idEnemy){  //53, 0, 40, 50
        case 0:
            x1=53;
            y1=3;
            x2=65;
            y2=65;
            characterSprite.scale(1.0f, 1.0f); // reduce dimensions of Character (right dimensions: 0.1f)
            break;
        case 1:
            x1=72;
            y1=3;
            x2=20;
            y2=38;
            characterSprite.scale(2.0f, 2.0f); // reduce dimensions of Character (right dimensions: 0.1f)
            break;
        case 2:
            x1=53;
            y1=0;
            x2=40;
            y2=50;
            characterSprite.scale(2.0f, 2.0f); // reduce dimensions of Character (right dimensions: 0.1f)
            break;
        case 3:
            x1=53;
            y1=0;
            x2=40;
            y2=50;
            characterSprite.scale(2.0f, 2.0f); // reduce dimensions of Character (right dimensions: 0.1f)

            break;

    }
        if (!tx.loadFromFile(textureFileName, IntRect(x1, y1, x2, y2))){
            std::cout << "Texture Error" << std::endl;
        }
        characterSprite.setTexture(tx);
        //characterSprite.scale(2.0f, 2.0f); // reduce dimensions of Character (right dimensions: 0.1f)
        characterSprite.setPosition(79, 100); // initial position of Character*/
    //}

}
