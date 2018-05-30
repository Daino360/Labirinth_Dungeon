//
// Created by Stefano on 24/11/2017.
//

#ifndef PLATFORMDUNGEON_STORE_H
#define PLATFORMDUNGEON_STORE_H


class Store {
public:
    int sell();
    int takeWeapon();//Quando prende l'arma nuova dal muro

private:
    int weapon;
    int armor;

};


#endif //PLATFORMDUNGEON_STORE_H
