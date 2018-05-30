//
// Created by daino on 16/01/18.
//

#ifndef PLATFORMDUNGEON_FACTORYH_H
#define PLATFORMDUNGEON_FACTORYH_H

#include "Hero.h"
#include <string>
#include <map>
#include <iostream>


using namespace std;

class FactoryH {
public:
    ~FactoryH() { m_FactoryMapH.clear(); }

    static FactoryH *Get()
    {
        static FactoryH instance;
        return  &instance;
    }

    void RegisterH(const int &chooseTypeHero, CreateHeroFn pfnCreate);
    Hero *CreateHero(int &chooseTypeHero);

    /*void RegisterH(const int &chooseTypeHero, CreateHeroFn pfnCreate);
    Hero *CreateHero(int &chooseTypeHero);*/

    FactoryH();
    FactoryH(const FactoryH &) {}
    FactoryH &operator=(const FactoryH &) {return *this;}
private:

    typedef map<int, CreateHeroFn>	FactoryMapH;
    FactoryMapH		m_FactoryMapH;

    /*typedef map<int, CreateHeroFn>	FactoryMapH;
    FactoryMapH		m_FactoryMapH;*/
};



#endif //PLATFORMDUNGEON_FACTORYH_H
