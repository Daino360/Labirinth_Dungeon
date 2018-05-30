//
// Created by daino on 13/12/17.
//

#ifndef PLATFORMDUNGEON_ENUMFILE_H
#define PLATFORMDUNGEON_ENUMFILE_H

enum enumMaterial:int{
    wood,
    iron,
    steel,
    valyria

};

enum enumTypeWeapon : int {
    bow,
    sword,
    stick
};

enum enumTypeHero : int {
    archer,
    warrior,
    wizard
};

enum enumTypeEnemy : int {//10,11,12,13 per evitare collisione con enumerazione eroi.
    goblin = 10,
    ghoul = 11,
    orc = 12,
    troll = 13
};

#endif //PLATFORMDUNGEON_ENUMFILE_H
