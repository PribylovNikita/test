#include "Objects/life.h"

void Life::Interact(Player& player)
{
    player.Heal();
}

const std::type_info& Life::WhatIsIt() const
{
    return typeid(*this);
}
