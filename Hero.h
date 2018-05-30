//
// Created by Stefano on 15/11/2017.
//

#ifndef PLATFORMDUNGEON_HERO_H
#define PLATFORMDUNGEON_HERO_H

#include "GameCharacter.h"
#include "Equipment.h"
#include "Weapon.h"
#include <string>
#include "EnumFile.h"

class Hero : public GameCharacter {
public:
    explicit Hero(std::string nameHero, enumTypeHero tHero, int health, int dex, int atk, int def) : GameCharacter(health, dex, atk, def), name(nameHero), typeHero(tHero) {
        typeHero = tHero;

    }

    void move(int x, int y) override;//Mettiamo L override perchè stiamo usando un metodo di Gamecharacter
    int takeEquipment();

    Weapon* tw;// sta per typeWeapon

    Equipment *getEquipment() const {
        return equipment;
    }

    void setEquipment(Equipment *equipment) {
        Hero::equipment = equipment;
    }

    Weapon *getWeapon() const {
        return weapon;
    }

    void setWeapon(Weapon *weapon) {
        Hero::weapon = weapon;
    }


    void weaponAttribution() { //serve per dare l'arma base in base al tipo di eroe
        if (typeHero == archer) {
            tw = new Weapon(bow, wood);
        } else if (typeHero == warrior) {
            tw = new Weapon(sword, wood);
        } else if (typeHero == wizard) {
            tw = new Weapon(stick, wood);
        }
    }

private: // va messo private se si elimina warrior mage ecc...
    std::string name;
    enumTypeHero typeHero;
    Equipment* equipment; //Puntatore che serve per composizione
    Weapon* weapon; //Puntatore che serve per composizione
};



#endif //PLATFORMDUNGEON_HERO_H
