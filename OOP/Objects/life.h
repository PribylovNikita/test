#ifndef LIFE_H
#define LIFE_H

#include "Objects/abstractitem.h"

class Life : public AbstractItem
{
public:
    Life() = default;
    void Interact(Player& player) override;
    const std::type_info& WhatIsIt() const override;
};

#endif // LIFE_H
