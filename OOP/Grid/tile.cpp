#include "tile.h"


Tile::Tile():
    type_(TileType::Pass), /*content_(TileContent::None),*/ item_(nullptr) {}

TileType Tile::Type() const
{
    return type_;
}


void Tile::SetType(const TileType type)
{
    type_ = type;
}


/*TileContent Tile::Content() const
{
    return content_;
}


void Tile::SetContent(const TileContent content)
{
    content_ = content;
}*/

AbstractItemP& Tile::Item()
{
    return item_;
}

void Tile::SetItem(const AbstractItemP& item)
{
    item_ = item;
}
