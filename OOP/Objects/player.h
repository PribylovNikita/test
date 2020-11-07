#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "Objects/abstractitem.h"

const int playerStartingLives = 3;
const int playerMaxLives = 4;

enum class Direction {up, right, down, left};

class AbstractItem;

using PlayerP = std::shared_ptr<class Player>;

class Player
{
public:
    Player(int x, int y);

    void Move(Direction dir);

    int X() const;
    int Y() const;

    int Lives() const;
    bool Heal();
    void LoseLife();

    int Artifacts() const;
    void TakeArtifact();

    int Keys() const;
    void TakeKey();
    bool OpenDoor();

    void operator+=(AbstractItem& item);

private:
    int x_, y_;
    int lives_;
    int artifacts_;
    int keys_;
};

#endif // PLAYER_H
