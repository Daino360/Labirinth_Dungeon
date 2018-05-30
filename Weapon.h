//
// Created by Stefano on 15/11/2017.
//

#ifndef PLATFORMDUNGEON_WEAPON_H
#define PLATFORMDUNGEON_WEAPON_H


class Weapon {
public:
    explicit Weapon(bool st= false, bool b= false, bool sw= false) : stick(st), bow(b), sword(sw) {}//st-stick, b-bow, sw-sword
    int attack();
    int damage();

    void setStick(int st) {
        stick=st;
    }
    int getStick() {
        return stick;
    }
    void setBow(int b) {
        bow=b;
    }
    int getBow() {
        return bow;
    }
    void setSword(int sw) {
        sword=sw;
    }
    int getSword() {
        return sword;
    }

private:
    bool stick;
    bool bow;
    bool sword;

};


#endif //PLATFORMDUNGEON_WEAPON_H
