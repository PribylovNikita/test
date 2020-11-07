#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "Objects/abstractitem.h"

class Artifact : public AbstractItem
{
public:
    Artifact() = default;
    void Interact(Player& player) override;
    const std::type_info& WhatIsIt() const override;
};

#endif // ARTIFACT_H
