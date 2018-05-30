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
#include <map>
#include <iostream>

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
        if (typeHero == enumTypeHero::archer) {
            tw = new Weapon((int)enumTypeWeapon::bow, (int)enumMaterial::wood);//int con il cast perchè abbiamo aggiunto class a enum file
        } else if (typeHero == enumTypeHero::warrior) {
            tw = new Weapon((int)enumTypeWeapon::sword, (int)enumMaterial::wood);//int con il cast perchè abbiamo aggiunto class a enum file
        } else if (typeHero == enumTypeHero::wizard) {
            tw = new Weapon((int)enumTypeWeapon::stick,(int)enumMaterial::wood);//int con il cast perchè abbiamo aggiunto class a enum file
        }
    }

    int gameAttack(){
        return putAttack();
    }

    virtual void Free() = 0;
    static Hero *GetHero();

    //virtual void Free() = 0;
    //static char chooseName[11];
    //static char *getChooseName();
    /*{
        std::cout << "Choose name of your Hero!\n";
        printf("Your hero's name is %s\n", chooseName);
        //chooseName[10] = 0;
        std::cin >> chooseName;
        return chooseName;
    }*/


    /*static Hero *GetHero();
    char chooseName[11];*/




private: // va messo private se si elimina warrior mage ecc...
    std::string name;
    enumTypeHero typeHero;
    Equipment* equipment; //Puntatore che serve per composizione
    Weapon* weapon; //Puntatore che serve per composizione

};

// Create function pointer
typedef Hero* ( *CreateHeroFn)(void);

// Hero implementations
class Archer : public Hero {
public:
    Archer(std::string nameHero, enumTypeHero tHero, int h, int d, int a, int df) : Hero(nameHero, tHero,h,d,a,df){}
    void Free() { delete this; }
    static Hero * Create() { return new Archer("Legolas",archer,100,200,150,50); }
};

class Warrior : public Hero {
public:
    Warrior(std::string nameHero, enumTypeHero tHero, int h, int d, int a, int df) : Hero(nameHero, tHero,h,d,a,df){}
    void Free() { delete this; }
    static Hero * Create() { return new Warrior("Aragon",warrior,150,50,100,200); }
};

class Wizard : public Hero {
public:
    Wizard(std::string nameHero, enumTypeHero tHero, int h, int d, int a, int df) : Hero(nameHero, tHero,h,d,a,df){}
    void Free() { delete this; }
    static Hero * Create() { return new Wizard("Gandalf",wizard,100,150,200,50); }
};


/*
// Create function pointer
typedef Hero* ( *CreateHeroFn)(void);

// Hero implementations
class Archer : public Hero{
public:
    Archer(char nameHero, enumTypeHero tHero, int health, int dex, int atk, int def) : Hero(nameHero, tHero, health, dex, atk, def){}
    void Free() { delete this; }
    //char *getChooseName() {return chooseName;}

    Hero * Create() { return new Archer(chooseName,archer,800,60,200,60); }
};

class Warrior : public Hero{
public:
    Warrior(char nameHero, enumTypeHero tHero, int health, int dex, int atk, int def) : Hero(nameHero, tHero, health, dex, atk, def){}
    void Free() { delete this; }
    //char *getChooseName() {return chooseName;}
    Hero * Create() { return new Warrior((char)chooseName,warrior,300,60,300,60); }
};

class Wizard : public Hero{
public:
    Wizard(char nameHero, enumTypeHero tHero, int health, int dex, int atk, int def) : Hero(nameHero, tHero, health, dex, atk, def){}
    void Free() { delete this; }
    //char *getChooseName() {return chooseName;}
    Hero * Create() { return new Wizard((char)chooseName,wizard,10,80,30,5); }
};*/




#endif //PLATFORMDUNGEON_HERO_H
