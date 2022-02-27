#pragma once

#include "Tile.h"

#include <SDL.h>

class Player {
private:
    int xCoord = 17;
    int yCoord = 11;
    int middleXCoord = 17;
    int middleYCoord = 11;

    int health = 0;
    int attackDamage = 0;
    int armorRating = 0;

public:
    
    int getXCoord();
    void setXCoord(int x);
    int getYCoord();
    void setYCoord(int y);

    int subYCoord(Tile* tileArr[23][35]);
    int addYCoord(Tile* tileArr[23][35]);
    int subXCoord(Tile* tileArr[23][35]);
    int addXCoord(Tile* tileArr[23][35]);
};


