//
// Created by Stefano on 15/11/2017.
//

#ifndef PLATFORMDUNGEON_WEAPON_H
#define PLATFORMDUNGEON_WEAPON_H

#include "EnumFile.h"

class Weapon {
public:
    explicit Weapon(int tWeapon, int mWeapon) {
        int danno=1;
    }//st-stick, b-bow, sw-sword hanno tutte danno = 1

    int damage;

    int damageForMaterial (){
        if (materialWeapon == wood){
            damage=1;
        }
        else if (materialWeapon == iron){
            damage=3;
        }
        else if (materialWeapon == steel){
            damage=5;
        }
        else if (materialWeapon ==valyria){
            damage=10;
        }
    }

    int attack();

private:
    int typeWeapon;
    int materialWeapon;
};


#endif //PLATFORMDUNGEON_WEAPON_H
