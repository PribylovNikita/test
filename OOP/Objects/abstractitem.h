#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <memory>
#include <typeinfo>
#include "player.h"

class Player;

using AbstractItemP = std::shared_ptr<class AbstractItem>;

class AbstractItem
{
public:
    AbstractItem() = default;
    virtual ~AbstractItem() = default;
    virtual void Interact(Player& player) = 0;
    virtual const std::type_info& WhatIsIt() const = 0;
};

#endif // ABSTRACTITEM_H
