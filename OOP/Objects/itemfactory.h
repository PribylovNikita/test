#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Objects/abstractitem.h"
#include "Objects/artifact.h"
#include "Objects/key.h"
#include "Objects/life.h"

class ItemFactory
{
public:
    virtual ~ItemFactory() = default;
    virtual AbstractItemP CreateItem() const = 0;
};

class ArtifactFactory : public ItemFactory
{
public:
    AbstractItemP CreateItem() const override;
};

class LifeFactory : public ItemFactory
{
public:
    AbstractItemP CreateItem() const override;
};

class KeyFactory : public ItemFactory
{
public:
    AbstractItemP CreateItem() const override;
};

#endif // ITEMFACTORY_H
