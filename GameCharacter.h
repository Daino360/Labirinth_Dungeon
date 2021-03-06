//
// Created by Stefano on 25/10/2017.
//

#ifndef PLATFORMDUNGEON_GAMECHARACTER_H
#define PLATFORMDUNGEON_GAMECHARACTER_H

#include "Strategy.h"
#include "TileMap.h"
#include "Weapon.h"
#include <iostream>



using namespace std;
namespace sf{}
using namespace sf;
class GameCharacter {
public://DEVO FARE DEI COSTRUTTORI DI DEFAULT QUI NELL HEADER PER POTER SPECIFICARE OGNI ARMA AD OGNI PERSONAGGIO

    GameCharacter(int h, int d, int a, int df);
    ~GameCharacter(){};

    //h-hp, d-dexterity, a-attack, df-defense
    virtual void move(int x, int y);
    int fight(GameCharacter& enemy);
    int fightHero(GameCharacter& hero);

    //Getter and Setter attributes
    int getHp() const {
        return hp;
    }

    void setHp(int hp) {
        GameCharacter::hp = hp;
    }

    int getDexterity() const {
        return dexterity;
    }

    void setDexterity(int dexterity) {
        GameCharacter::dexterity = dexterity;
    }

    int getAttack() const {
        return attack;
    }

    void setAttack(int attack) {
        GameCharacter::attack = attack;
    }

    int getDefense() const {
        return defense;
    }

    void setDefense(int defense) {
        GameCharacter::defense = defense;
    }

    int getPosX() const {
        return posX;
    }

    void setPosX(int posX) {
        GameCharacter::posX = posX;
    }

    int getPosY() const {
        return posY;
    }

    void setPosY(int posY) {
        GameCharacter::posY = posY;
    }

    Strategy *getStrategy() const {
        return strategy;
    }

    void setStrategy(Strategy *strategy) {
        GameCharacter::strategy = strategy;
    }
    Weapon *getWeapon() const {
        return weapon;
    }

    void setWeapon(Weapon *weapon) {
        GameCharacter::weapon = weapon;
    }

    int putAttack() {
        return attack;
    }

    void setUpSprite(std::string textureFileName);
    void setUpSpriteEnemy(std::string textureFileName, int);

    sf::Sprite getCharacterSprite(){
        return characterSprite;
    }

    sf::Texture getCharacterTexture(){
        return tx;
    }


protected:
    int hp;
    int dexterity;
    int attack;
    int defense;
    int posX, posY;
    sf::Sprite characterSprite;
    sf::Texture tx;
    //int numEnemy;

    Strategy* strategy;//Puntatore che serve per composizione
    Weapon* weapon; //Puntatore che serve per composizione


};


#endif //PLATFORMDUNGEON_GAMECHARACTER_H
