//
// Created by Stefano on 15/11/2017.
//

#include "Hero.h"
#include "FactoryH.h"
#include "EnumFile.h"

using namespace std;

void Hero::move(int x, int y) { //movimento dell' eroe
    // TODO complete
}

using namespace std;

Hero *Hero::GetHero() {

    char chooseName[11];
    std::cout << "Choose name of your Hero!\n";
    std::cin >> chooseName;
    chooseName[10] = 0;
    printf("Your hero's name is %s\n", chooseName);

    Hero *pHero = NULL;
    int chooseTypeHero;

    std::cout << "Choose type of your Hero, between: select 0 for archer , select 1 for warrior , select 2 for wizard\n";
    std::cin >> chooseTypeHero;

    //enumTypeHero tHero = (enumTypeHero) chooseTypeHero;

    if (chooseTypeHero == 0) {
        pHero = FactoryH::Get()->CreateHero(chooseTypeHero);
        cout << "Your Hero is a Archer\n";
    } else if (chooseTypeHero == 1) {
        pHero = FactoryH::Get()->CreateHero(chooseTypeHero);
        cout << "Your Hero is a Warrior\n";
    } else if (chooseTypeHero == 2) {
        pHero = FactoryH::Get()->CreateHero(chooseTypeHero);
        cout << "Your Hero is a Wizard\n";
    } else {
        std::cout << "hai sbagliato a scegliere!\n";
        return 0;
    }
    return pHero;
}

Hero *FactoryH::CreateHero(int &chooseTypeHero){

    FactoryMapH::iterator it = m_FactoryMapH.find(chooseTypeHero);
    if( it != m_FactoryMapH.end() )
        return it->second();
    return NULL;
}

/*
Hero *Hero::GetHero() {

    Hero *pHero = NULL;
    std::string heroName;
    int chooseTypeHero;

    std::cout << "Choose type of your Hero, between: select 0 for archer , select 1 for warrior , select 2 for wizard\n";
    std::cin >> chooseTypeHero;

    enumTypeHero tHero = (enumTypeHero) chooseTypeHero;

    if (chooseTypeHero == 0) {
        heroName = "Archer";
        pHero = Factory::Get()->CreateHero(chooseTypeHero);
    } else if (chooseTypeHero == 1) {
        heroName = "Warrior";
        pHero = Factory::Get()->CreateHero(chooseTypeHero);
    } else if (chooseTypeHero == 2) {
        heroName = "Wizard";
        pHero = Factory::Get()->CreateHero(chooseTypeHero);
    } else {
        std::cout << "hai sbagliato a scegliere!\n";
        return 0;
    }
    cout << "Your Hero is a \n" << heroName;
    return pHero;
}


Hero *Factory::CreateHero(int &chooseTypeHero) {

    FactoryMapH::iterator it = m_FactoryMapH.find(chooseTypeHero);//hero name è l' enum type hero ovvero il tipo di eroe
    if (it != m_FactoryMapH.end())
        return it->second();
    return NULL;
}

/*char *Hero::getChooseName() {

    std::cout << "Choose name of your Hero!\n";
    printf("Your hero's name is %s\n", chooseName);
    chooseName[10] = 0;
    std::cin >> chooseName;
}*/
