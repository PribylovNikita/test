#include "Objects/itemfactory.h"

AbstractItemP ArtifactFactory::CreateItem() const
{
    return std::make_shared<Artifact>();
}

AbstractItemP LifeFactory::CreateItem() const
{
    return std::make_shared<Life>();
}

AbstractItemP KeyFactory::CreateItem() const
{
    return std::make_shared<Key>();
}
