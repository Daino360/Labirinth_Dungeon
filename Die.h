//
// Created by daino on 10/01/18.
//

#ifndef PLATFORMDUNGEON_DIE_H
#define PLATFORMDUNGEON_DIE_H


class Die {
public:
    explicit Die(int f=4);
    int roll(int r);

    static void initRandom();

private:
    int faces;
    static int numRolls;
};


#endif //PLATFORMDUNGEON_DIE_H
