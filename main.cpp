#include <iostream>
#include "Hero.h"
#include "Enemy.h"

int main(int argc, char **argv) {
    //RenderWindow window(VideoMode(320, 480), "Platform Dungeon!");

    char chooseName[11];
    std::cout << "Choose name of your Hero!\n";
    std::cin >> chooseName;
    chooseName[10] = 0;
    printf("Your hero's name is %s\n", chooseName);

    int chooseTypeHero;
    std::cout
            << "Choose type of your Hero, between: select 1 for archer , select 2 for warrior , select 3 for wizard\n";
    std::cin >> chooseTypeHero;

    enumTypeHero tHero = (enumTypeHero) chooseTypeHero;
    int health;
    int dex;
    int atk;
    int def;

    if (chooseTypeHero == 1) {
        health = 800;
        dex = 60;
        atk = 200;
        def = 60;
    } else if (chooseTypeHero == 2) {
        health = 300;
        dex = 60;
        atk = 300;
        def = 60;
    } else if (chooseTypeHero == 3) {
        health = 200;
        dex = 60;
        atk = 400;
        def = 60;
    } else {
        std::cout << "hai sbagliato a scegliere!\n";
        return 0;
    }

    Hero *Giovanni = new Hero(chooseName, tHero, health, dex, atk, def);
    Enemy *Stefano = new Enemy(enumTypeEnemy::troll, 350, 2, 200, 20); // type enemy - hp - dexterity - attack - defense

    printf("%s fights against Lord Fang", chooseName);

    int damoHero = 0;
    int damoEnemy = 0;

    int done = 0;
    int c = 0;

    for (int hit = 0; hit < Stefano->getHp() || hit < Giovanni->getHp(); hit++) {

        do {
            c = getchar();
            putchar(c);
        } while (c != ' ');

        damoHero = Giovanni->fight(*Stefano);
        damoEnemy = Stefano->fightHero(*Giovanni);

        if (damoHero)
            std::cout << "Lord Fang hit: " << damoHero << std::endl;
        if (Stefano->getHp() > 0)
            std::cout << "Healty Point of Lord Fang " << Stefano->getHp() << std::endl;
        else {
            std::cout << "Healty Point of Lord Fang " << 0 << std::endl;
            if (rand() > 9999999999) {
                printf("Monster hit before die\n");
                std::cout << "Hero hit: " << damoEnemy << std::endl;
                if (Giovanni->getHp() > 0)
                    std::cout << "Healty Point of Your Hero " << Giovanni->getHp() << std::endl;
                else {
                    std::cout << "Healty Point of Your Hero " << 0 << std::endl;
                    std::cout << "\nYour Hero is dead" << std::endl;
                    done = 1;
                }
            }
        }
        if (Stefano->getHp() <= 0) {
            std::cout << "\nLord Fang is dead" << std::endl;
            return 0;
        }

        if (damoEnemy && done == 0)
            std::cout << "Hero hit: " << damoEnemy << std::endl;
        if (Giovanni->getHp() > 0 && done == 0)
            std::cout << "Healty Point of Your Hero " << Giovanni->getHp() << std::endl;
        else if (done == 0) {
            std::cout << "Healty Point of Your Hero " << 0 << std::endl;
            std::cout << "\nYour Hero is dead" << std::endl;
        }
    }
    return 0;
}
