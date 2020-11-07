#include "Game/levels.h"

Levels::Levels() {}

PlayerP& Levels::GetPlayer()
{
    return player_;
}

bool Levels::CreateDefaultLevel1()
{
    Grid* grid = Grid::GetInstance();
    if (grid->Width() != gridWidth || grid->Height() != gridHeight) {
        return false;
    }

    ArtifactFactory artifactFactory;
    KeyFactory keyFactory;
    LifeFactory lifeFactory;

    int level[gridWidth][gridHeight] = {{2, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                                        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                                        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                                        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                                        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                                        {1, 1, 1, 1, 1, 1, 1, 4, 1, 1},
                                        {1, 1, 1, 1, 1, 1, 1, 0, 1, 3}};

    for (int y = 0; y < grid->Height(); y++) {
        for (int x = 0; x < grid->Width(); x++) {
            grid->Array(y,x).SetType(static_cast<TileType>(level[y][x]));
        }
    }

    player_ = std::make_shared<Player>(0,0);

    AbstractItemP tmp;
    tmp = artifactFactory.CreateItem();
    grid->Array(7,3).SetItem(tmp);

    tmp = keyFactory.CreateItem();
    grid->Array(7,6).SetItem(tmp);

    tmp = lifeFactory.CreateItem();
    grid->Array(8,9).SetItem(tmp);
    return true;
}
