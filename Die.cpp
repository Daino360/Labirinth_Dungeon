//
// Created by daino on 10/01/18.
//

#include "Die.h"
#include <ctime> // for time
#include <cstdlib> // for rand and srand

int Die::numRolls = 0;

Die::Die(int f) : faces(f) {
    srand( time(0) );
}

void Die::initRandom() {
    if ((numRolls % 1000) == 0)
        srand( time(0) );
}

int Die::roll(int r) {
    int result=0;
    for (int i=0; i<r; i++)
        result += rand() % faces;
    numRolls++;
    return result;
}
