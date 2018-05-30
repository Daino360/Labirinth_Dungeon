//
// Created by daino on 10/01/18.
//

#include "Factory.h"

using namespace std;


/* Enemy factory constructor.
Private, called by the singleton accessor on first call.
Register the types of enemies here.
*/
Factory::Factory()
{
    Register(goblin, &Goblin::Create);
    Register(ghoul, &Ghoul::Create);
    Register(orc, &Orc::Create);
    Register(troll, &Troll::Create);

}

void Factory::Register(const int &enemyName, CreateEnemyFn pfnCreate)
{
    m_FactoryMap[enemyName] = pfnCreate;
}
