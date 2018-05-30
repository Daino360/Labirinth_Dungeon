//
// Created by daino on 16/01/18.
//

#include "FactoryH.h"

using namespace std;


/* Hero factory constructor.
Private, called by the singleton accessor on first call.
Register the types of enemies here.
*/
FactoryH::FactoryH()
{
    RegisterH(archer, &Archer::Create);
    RegisterH(warrior, &Warrior::Create);
    RegisterH(wizard, &Wizard::Create);
    /*RegisterH(archer, &Archer::Create);
    RegisterH(warrior, &Warrior::Create);
    RegisterH(wizard, &Wizard::Create);*/

}

void FactoryH::RegisterH(const int &chooseTypeHero, CreateHeroFn pfnCreate)
{
    m_FactoryMapH[chooseTypeHero] = pfnCreate;
}
/*
void Factory::RegisterH(const int &chooseTypeHero, CreateHeroFn pfnCreate)
{
    m_FactoryMapH[chooseTypeHero] = pfnCreate;
}
 */