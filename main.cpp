#include <iostream>
#include "Hero.h"
#include "Enemy.h"
#include "Factory.h"
#include "Die.h"
#include "EnumFile.h"
#include <fstream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main(int argc, char **argv) {

// print the content of a text file.
    std::ifstream ifs;
    ifs.open("Mappetta.txt", std::ifstream::in); //apre la Mappetta.txt dove c'è il set della Mappa
    char v = ifs.get();

    std::list<int> list = std::list<int>(); //lista in cui verranno inseriti tutti gli 0,1,2 del set mappa

    while (ifs.good()) {
        //std::cout << v;
        v = ifs.get();
        if(v=='0' || v=='1' || v=='2')
        {
            list.push_back((int)v);
        }
    }
    ifs.close();

// 48=0 , 49=1 , 50=2
    int level[list.size()]; //array finale che serve per creare effettivamente la mappa
    int myarray[list.size()]; //array di transizione che prende 48 come 0, 49 come 1, 50 come 2.
// define the level with an array of tile indices
    for(int i=0;i<list.size()*list.size();i++)
    {
            myarray[i] = list.front();
            if (myarray[i] == 48) {
                level[i] = 0;
            } else if (myarray[i] == 49) {
                level[i] = 1;
            } else if (myarray[i] == 50) {
                level[i] = 2;
            } else {
                std::cout << "Texture Error" << std::endl;
            }
        list.pop_front();
    }
    //int tile = (int)level;
// Keep track of the frametime
    sf::Clock frametime;
// create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Labirinth Dungeon", sf::Style::Fullscreen); //sf::Style::Fullscreen da agg e mette lo schermo intero
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // call it once, after creating the window

// create the tilemap from the level definition
    TileMap map;
    if (!map.load("Tile2.jpeg", sf::Vector2u(32, 32), level, 58, 33))
        std::cout << "Texture Error" << std::endl;

//servono per lo spostamento del Gallo
    enum Direction {Down,Left,Right,Up};
    sf::Vector2i source(1,Down);

// create a Texture a forma di Gallo
    sf::Texture gallo;
    if (!gallo.loadFromFile("asset/gallo.png"))
        std::cout << "Texture Error" << std::endl;
    sf::Sprite gallos;
    gallos.setTexture(gallo); // fa diventare una texture uno sprite
    gallos.scale(0.1f, 0.1f); // riduce le dimensioni del Gallo (dimensioni giuste 0.1f)
    gallos.setPosition(790, 10); // posizione iniziale del Gallo
    //gallos.setTextureRect(sf::IntRect(50, 50, 150, 150)); taglia l'immagine

//i//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Big wall1 (crea i rettangoli che non potranno essere superati)
    sf::RectangleShape wall1(sf::Vector2f(760.f, 30.f));
    wall1.setPosition(0, 0); //(x,y) alto sx
    sf::RectangleShape wall2(sf::Vector2f(8000.f, 30.f));
    wall2.setPosition(870, 0); //alto dx
    sf::RectangleShape wall3(sf::Vector2f(25.f, 8000.f));
    wall3.setPosition(0, 0); //lungo sx
    sf::RectangleShape wall4(sf::Vector2f(25.f, 8000.f));
    wall4.setPosition(1830, 0); //lungo dx
    sf::RectangleShape wall5(sf::Vector2f(80000.f, 25.f));
    wall5.setPosition(0, 1030); //basso
    sf::RectangleShape wall6(sf::Vector2f(55.f, 200.f));
    wall6.setPosition(1380, 0); //centrale prima fila
    sf::RectangleShape wall7(sf::Vector2f(377.f, 25.f));
    wall7.setPosition(0, 196); //primo prima fila
    sf::RectangleShape wall8(sf::Vector2f(1235.f, 25.f));
    wall8.setPosition(485, 196); //secondo prima fila
    sf::RectangleShape wall9(sf::Vector2f(955.f, 25.f));
    wall9.setPosition(0, 356); //primo secondo fila
    sf::RectangleShape wall10(sf::Vector2f(340.f, 25.f));
    wall10.setPosition(1061, 356); //secondo secondo fila
    sf::RectangleShape wall11(sf::Vector2f(8000.f, 25.f));
    wall11.setPosition(1508, 356); //terzo secondo fila
    sf::RectangleShape wall12(sf::Vector2f(55.f, 180.f));
    wall12.setPosition(1190, 356); //centrale terza fila
    sf::RectangleShape wall13(sf::Vector2f(595.f, 25.f));
    wall13.setPosition(135, 516); //primo terza fila
    sf::RectangleShape wall14(sf::Vector2f(882.f, 25.f));
    wall14.setPosition(837, 516); //secondo terza fila
    sf::RectangleShape wall15(sf::Vector2f(406.f, 25.f));
    wall15.setPosition(0, 676); //primo quarta fila
    sf::RectangleShape wall16(sf::Vector2f(787.f, 25.f));
    wall16.setPosition(517, 676); //secondo quarta fila
    sf::RectangleShape wall17(sf::Vector2f(800.f, 25.f));
    wall17.setPosition(1412, 676); //terzo quarta fila
    sf::RectangleShape wall18(sf::Vector2f(55.f, 180.f));
    wall18.setPosition(772, 676); //centrale quinta fila
    sf::RectangleShape wall19(sf::Vector2f(155.f, 25.f));
    wall19.setPosition(0, 836); //primo quinta fila
    sf::RectangleShape wall20(sf::Vector2f(1235.f, 25.f));
    wall20.setPosition(262, 836); //secondo quinta fila
    sf::RectangleShape wall21(sf::Vector2f(800.f, 25.f));
    wall21.setPosition(1605, 836); //terzo quinta fila

    bool touching = false; // Check if we're touching any wall1/box
//f//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// run the main loop (GAME LOOP)
    while (window.isOpen())
    {
        // Get delta time for frame-rate depended movement
        //float dt = frametime.restart().asSeconds();

        //handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            source.y = Up;
                            gallos.move(0, -5);
                            break;
                        case sf::Keyboard::Down:
                            source.y = Down;
                            gallos.move(0, 5);
                            break;
                        case sf::Keyboard::Right:
                            source.x = Right;
                            gallos.move(5, 0);
                            //gallos.setRotation(90); //ruota l'immagine del gallo di 90 gradi
                            break;
                        case sf::Keyboard::Left:
                            source.x = Left;
                            gallos.move(-5, 0);
                            //gallos.setRotation(0); //ruota l'immagine del gallo di 0 gradi
                            break;
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

//i//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Check collision & position adjustment (non fa attraversare il muro)
        if(wall1.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall1 alto sx
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if (event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va nel senso opposto
        }
        else if(wall2.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall2 alto dx
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if (event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va nel senso opposto
        }
        else if(wall3.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall3 lungo sx
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va nel senso opposto
        }
        else if(wall4.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall4 lungo dx
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va nel senso opposto
        }
        else if(wall5.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall5 basso
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole andare in giù va nel senso opposto
        }
        else if(wall6.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall6 centrale prima fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
        }
        else if(wall7.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall7 primo prima fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
        }
        else if(wall8.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall8 secondo prima fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall9.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall9 primo seconda fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall10.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall10 secondo seconda fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall11.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall11 terzo seconda fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall12.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall12 centrale terza fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall13.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall13 primo terza fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall14.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall14 secondo terza fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall15.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall15 primo quarta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall16.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall16 secondo quarta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall17.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall17 secondo quarta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall18.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall18 centrale quinta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall19.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall19 primo quinta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall20.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall20 secondo quinta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else if(wall21.getGlobalBounds().intersects(gallos.getGlobalBounds())) // wall21 terzo quinta fila
        {
            touching = true;
            if(event.key.code==sf::Keyboard::Up) gallos.move(0,5); //se vuole andare in su va nel senso opposto
            else if(event.key.code==sf::Keyboard::Down) gallos.move(0,-5); //se vuole giù va in su
            else if(event.key.code==sf::Keyboard::Left) gallos.move(5,0); //se vuole andare a sx va a dx
            else if(event.key.code==sf::Keyboard::Right) gallos.move(-5,0); //se vuole andare a dx va a sx
        }
        else
        touching = false; // We're not colliding
//f//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //draw the map
        window.clear();
        window.draw(map);
        window.draw(gallos); //Draw Gallo Sprite
        window.display();
    }

    Hero *Giovanni = Hero::GetHero();//created by factoryH

    //crere un ciclo che crea nemici fincè non muore l'eroe

    Enemy *Stefano = Enemy::GetEnemy(); //created by factory

    cout << "\n" << "Your Hero fights against Enemy";
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
            std::cout <<" Enemy hit: " << damoHero << std::endl;
        if (Stefano->getHp() > 0)
            std::cout << "Healty Point of Enemy"<<": "<< Stefano->getHp() << std::endl;
        else {
            std::cout << "Healty Point of Enemy"<<": "<< 0 << std::endl;
        }
        if (Stefano->getHp() <= 0) {
            std::cout << "\n"<<"Enemy is dead" << std::endl;
            return 0;
        }

        if (damoEnemy && done == 0)
            std::cout << "Hero hit: " << damoEnemy << std::endl;
        if (Giovanni->getHp() > 0 && done == 0)
            std::cout << "Healty Point of Your Hero " << Giovanni->getHp()<< std::endl;
        else if (done == 0) {
            std::cout << "Healty Point of Your Hero " << 0 << std::endl;
            std::cout << "\nYour Hero is dead" << std::endl;
            return 0;
        }
    }
    return 0;
}
