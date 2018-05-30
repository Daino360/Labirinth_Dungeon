//
// Created by Stefano on 24/11/2017.
//

#include "TileMap.h"
#include "Hero.h"
#include "Die.h"
#include <fstream>
#include <list>
#include <iostream>

int TileMap::renderMap(sf::Sprite characterS, sf::Sprite characterSE, sf::Texture characterTx){

    // print the content of a text file.
    std::ifstream ifs;
    ifs.open("Mappetta.txt", std::ifstream::in); //open Mappetta.txt where is Map set
    char v = ifs.get();
    std::list<int> list = std::list<int>(); //list where will be insered all 0,1,2 of Mappetta.txt

    while (ifs.good()) {
        //std::cout << v;
        v = ifs.get();
        if(v=='0' || v=='1' || v=='2')
        {
            list.push_back((int)v);
        }
    }
    ifs.close();

    int tile;
    int level[list.size()]; //final array to create the Map
    int myarray[list.size()]; //Transiction array that change: 48 = 0, 49 = 1, 50 = 2 from ASCII tabels
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

// create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Labirinth Dungeon"); //sf::Style::Fullscreen for fullscreen
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setFramerateLimit(60); // call it once, after creating the window

// Keep track of the frametime
    sf::Clock clock;
    bool updateFrame=true;
    float frameCounter = 0, switchFrame = 100, frameSpeed = 500;

// create the tilemap from the level definition con colori casuali
    TileMap map;
    Die::initRandom();
    Die die(5);
    int result = die.roll(1);
    if (result == 0) {
        if (!map.load("Tileset/Tileset1.png", sf::Vector2u(32, 32), level, 58, 33)){
            std::cout << "Texture Error" << std::endl;}
    } else if (result == 1) {
        if (!map.load("Tileset/Tileset2.jpg", sf::Vector2u(32, 32), level, 58, 33)){
            std::cout << "Texture Error" << std::endl;}
    } else if (result == 2) {
        if (!map.load("Tileset/Tileset3.jpg", sf::Vector2u(32, 32), level, 58, 33)){
            std::cout << "Texture Error" << std::endl;}
    } else if (result == 3) {
        if (!map.load("Tileset/Tileset4.jpg", sf::Vector2u(32, 32), level, 58, 33)){
            std::cout << "Texture Error" << std::endl;}
    } else if (result == 4) {
        if (!map.load("Tileset/Tileset5.jpg", sf::Vector2u(32, 32), level, 58, 33)){
            std::cout << "Texture Error" << std::endl;}
    }
    //if (!map.load("Tileset/Tileset1.png", sf::Vector2u(32, 32), level, 58, 33))
    //    std::cout << "Texture Error" << std::endl;

    //Characters Movements
    enum Direction {Down,Left,Right,Up};
    sf::Vector2i source(1, Down);

    characterS.setTextureRect(sf::IntRect(72, 3, 20, 38));

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
                            characterS.setTextureRect(sf::IntRect(135, 3, 20, 38));
                            //characterS.setTextureRect(sf::IntRect(135, 40, 20, 38));
                            a = ((characterS.getPosition().x/32));
                            b = ((characterS.getPosition().y/32));
                            newX = a;
                            newY = b-1;
                            tile = level[newX + newY*58];
                            if (tile==0)
                                characterS.move(0, 0);
                            else
                                characterS.move(0, -6);
                            break;
                        case sf::Keyboard::Down:
                            source.y = Down;
                            characterS.setTextureRect(sf::IntRect(72, 3, 20, 38));
                            a = ((characterS.getPosition().x/32)); //da rimettere round
                            b = ((characterS.getPosition().y/32));
                            newX = a;
                            newY = b+2;
                            tile = level[newX + newY*58];
                            if (tile==0)
                                characterS.move(0, 0);
                            else
                                characterS.move(0, 6);
                            break;
                        case sf::Keyboard::Right:
                            source.x = Right;
                            characterS.setTextureRect(sf::IntRect(10, 2, 20, 38));
                            characterS.setOrigin({ characterS.getLocalBounds().width, 0 });
                            characterS.setScale({ -2, 2 });
                            a = ((characterS.getPosition().x/32));
                            b = ((characterS.getPosition().y/32));
                            newX = a+1;
                            newY = b;
                            tile = level[newX + newY*58];
                            if (tile==0)
                                characterS.move(0, 0);
                            else
                                characterS.move(6, 0);
                            break;
                        case sf::Keyboard::Left:
                            source.x = Left;
                            characterS.setTextureRect(sf::IntRect(10, 2, 20, 38));
                            characterS.setOrigin({ 0, 0 });
                            characterS.setScale({ 2, 2 });
                            a = ((characterS.getPosition().x/32));
                            b = ((characterS.getPosition().y/32));
                            newX = a-1;
                            newY = b;
                            tile = level[newX + newY*58];
                            if (tile==0)
                                characterS.move(0, 0);
                            else
                                characterS.move(-6, 0);
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
/*
            frameCounter =  (updateFrame) ? frameCounter + frameSpeed * clock.restart().asSeconds() : 0;
            if(frameCounter>=switchFrame)
            {
                frameCounter = 0;

                source.x++;
                if (source.x >= characterTx.getSize().x)
                    source.x = 0;

                source.y++;
                if (source.y >= characterTx.getSize().x)
                    source.y = 0;
            }
            if(sf::Keyboard::Up){
                characterS.setTextureRect(sf::IntRect(source.x * 135, source.y * 3, 20, 38));
            }
            if(sf::Keyboard::Down){
                characterS.setTextureRect(sf::IntRect(source.x * 72, source.y * 3, 20, 38));
            }
            if(sf::Keyboard::Right){
                characterS.setTextureRect(sf::IntRect(source.x * 1, source.y * 3, 20, 38));
            }
            if(sf::Keyboard::Left){
                characterS.setTextureRect(sf::IntRect(source.x * 10, source.y * 3, 20, 38));
            }*/

        }

// draw the map
        window.clear();
        window.draw(map);
        window.draw(characterS);// create a Texture of Character
        window.draw(characterSE);// create a Texture of Character Enemy
        window.display();

    }
};