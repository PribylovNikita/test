#ifndef KEY_H
#define KEY_H

#include "Objects/abstractitem.h"

class Key : public AbstractItem
{
public:
    Key() = default;
    void Interact(Player& player) override;
    const std::type_info& WhatIsIt() const override;
};

#endif // KEY_H
