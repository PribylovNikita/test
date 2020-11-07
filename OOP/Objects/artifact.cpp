#include "artifact.h"

void Artifact::Interact(Player& player)
{
    player.TakeArtifact();
}

const std::type_info& Artifact::WhatIsIt() const
{
    return typeid(*this);
}
