//
// Created by Stefano on 15/11/2017.
//

#include "Hero.h"

using namespace std;

void Hero::move(int x, int y) { //movimento dell' eroe
    // TODO complete
}

using namespace std;

GameCharacter *Hero::GetHero() {

    char chooseName[11];
    cout << "Choose name of your Hero!\n";
    cin >> chooseName;
    chooseName[10] = 0;
    printf("Your hero's name is %s\n", chooseName);

    GameCharacter *pHero = NULL;
    int chooseTypeHero;

    cout << "Choose type of your Hero, between: select 0 for archer , select 1 for warrior , select 2 for wizard\n";
    cin >> chooseTypeHero;

    //enumTypeHero tHero = (enumTypeHero) chooseTypeHero;

    if (chooseTypeHero == 0) {
        pHero = Hero::Create(archer);
        cout << "Your Hero is a Archer\n";
    } else if (chooseTypeHero == 1) {
        pHero = Hero::Create(warrior);
        cout << "Your Hero is a Warrior\n";
    } else if (chooseTypeHero == 2) {
        pHero = Hero::Create(wizard);
        cout << "Your Hero is a Wizard\n";
    } else {
        cout << "hai sbagliato a scegliere!\n";
        return 0;
    }
    return pHero;
}

Hero* Hero::Create(enumTypeHero type)
{
    switch (type)
    {
        case archer:
        {
            Hero * h = new Hero("Legolas",archer,100,200,150,50);
            h->setUpSprite("archer2.png");
            return h;
            break;
        }
        case warrior:
        {
            Hero * h = new Hero("Aragon", warrior, 150, 50, 100, 200);
            h->setUpSprite("warrior2.png");
            return h;
            break;
        }
        case wizard:
        {
            Hero * h = new Hero("Gandalf", wizard, 90, 150, 200, 50);
            h->setUpSprite("wizard2.png");
            return h;
            break;
        }
    }
}