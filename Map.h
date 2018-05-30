//
// Created by Stefano on 24/11/2017.
//

#ifndef PLATFORMDUNGEON_MAP_H
#define PLATFORMDUNGEON_MAP_H


#include "Store.h"
#include "GameCharacter.h"

class Map {
public:
    Map(); // qui il costruttore lo lasciamo perchè Map non deriva da nessuna classe
    int changeMap();
    int getTile();
    int addCharacter();
    int removeCharacter();
    /*GameCharacter *getGameCharacter() const {
        return gameCharacter;
    }

    void setGameCharacter(GameCharacter *gameCharacter) {
        Map::gameCharacter = gameCharacter;
    }*/


private:
    int graphic;
    int tiles;
    int position;
    int width;
    int lenght;
    //GameCharacter* gameCharacter;// Puntatore per ASSOCIAZIONE --> Il nostro rapporto è 1 a molti quindi ci serve una lista di puntatori in gamecharacter

};


#endif //PLATFORMDUNGEON_MAP_H
