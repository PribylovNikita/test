#include "Objects/key.h"

void Key::Interact(Player& player)
{
    player.TakeKey();
}

const std::type_info& Key::WhatIsIt() const
{
    return typeid(*this);
}
