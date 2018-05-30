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
    characterSprite.scale(0.5f, 0.5f); // reduce dimensions of Character (right dimensions: 0.1f)
    characterSprite.setPosition(32,32); // initial position of Character
    //characterSprite.setOrigin(10, 19);
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
            break;
        case 1:
            x1=40;
            y1=40;
            x2=75;
            y2=75;
            break;
        case 2:
            x1=10;
            y1=13;
            x2=85;
            y2=85;
            break;
        case 3:
            x1=45;
            y1=0;
            x2=65;
            y2=65;
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
