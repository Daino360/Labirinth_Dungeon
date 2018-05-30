//
// Created by daino on 10/01/18.
//

#ifndef PLATFORMDUNGEON_FACTORY_H
#define PLATFORMDUNGEON_FACTORY_H

#include "Enemy.h"
#include <string>
#include <map>
#include <iostream>


using namespace std;

class Factory {
public:
    ~Factory() { m_FactoryMap.clear(); }

    static Factory *Get()
    {
        static Factory instance;
        return  &instance;
    }

    void Register(const int &enemyName, CreateEnemyFn pfnCreate);
    Enemy *CreateEnemy(int &enemyName);

    /*void RegisterH(const int &chooseTypeHero, CreateHeroFn pfnCreate);
    Hero *CreateHero(int &chooseTypeHero);*/

    Factory();
    Factory(const Factory &) {}
    Factory &operator=(const Factory &) {return *this;}
private:

    typedef map<int, CreateEnemyFn>	FactoryMap;
    FactoryMap		m_FactoryMap;

    /*typedef map<int, CreateHeroFn>	FactoryMapH;
    FactoryMapH		m_FactoryMapH;*/
};


#endif //PLATFORMDUNGEON_FACTORY_H
