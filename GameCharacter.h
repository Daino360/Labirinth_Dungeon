//
// Created by Stefano on 25/10/2017.
//

#ifndef PLATFORMDUNGEON_GAMECHARACTER_H
#define PLATFORMDUNGEON_GAMECHARACTER_H

#include "Strategy.h"
#include "Map.h"
#include "Weapon.h"


class GameCharacter {
public://DEVO FARE DEI COSTRUTTORI DI DEFAULT QUI NELL HEADER PER POTER SPECIFICARE OGNI ARMA AD OGNI PERSONAGGIO

    GameCharacter(int h, int d, int a, int df);
    ~GameCharacter(){};

    //h-hp, d-dexterity, a-attack, df-defense
    virtual void move(int x, int y);
    int fight(GameCharacter& enemy);
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


protected:
    int hp;
    int dexterity;
    int attack;
    int defense;
    int posX, posY;

    Strategy* strategy;//Puntatore che serve per composizione
    Weapon* weapon; //Puntatore che serve per composizione
    //Map* map;

};


#endif //PLATFORMDUNGEON_GAMECHARACTER_H
