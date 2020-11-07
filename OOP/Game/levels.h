#ifndef LEVELS_H
#define LEVELS_H

#include "Grid/grid.h"
#include "Objects/itemfactory.h"
#include "Objects/player.h"

class Levels
{
public:
    Levels();
    PlayerP& GetPlayer();
    bool CreateDefaultLevel1();
private:
    PlayerP player_;
};

#endif // LEVELS_H
