#ifndef TILE_H
#define TILE_H

#include "Objects/abstractitem.h"

enum class TileType : int {Wall, Pass, Start, Exit, Door};
//enum class TileContent : int {None, Item, Player, Enemy};

class Tile
{
public:
    Tile();

    TileType Type() const;
    void SetType(const TileType type);
    //TileContent Content() const;
    //void SetContent(const TileContent content);
    AbstractItemP& Item();
    void SetItem(const AbstractItemP& item);

private:
    TileType type_;
    //TileContent content_;
    AbstractItemP item_;
};

#endif // TILE_H
