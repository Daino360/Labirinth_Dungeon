#include "Hero.h"
#include "Enemy.h"


int main(int argc, char **argv) {
    GameCharacter *Giovanni = Hero::GetHero();//created by factory
    GameCharacter *Stefano = Enemy::GetEnemy(); //created by factory
    TileMap *Fabrizio = new TileMap();
    Fabrizio->renderMap(Giovanni->getCharacterSprite(), Stefano->getCharacterSprite(), Giovanni->getCharacterTexture());
    return 0;
}