#ifndef GAME_H
#define GAME_H

#include "Game/levels.h"

class Game
{
public:
    Game();
    Levels& Level();
    void StartLevel();
    bool MovePlayer(Direction dir);
    bool PlayerAbleToMove(int y, int x);
private:
    Levels level_;
};

#endif // GAME_H
