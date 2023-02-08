#include "Sheep.h"


Sheep::Sheep()
{
}

Sheep::Sheep(World* mWorld, const COORDINATES mPosition)
    :Animal(mWorld, mPosition)
{
    this->power = SHEEP_POWER;
    this->initiative = SHEEP_INITIATIVE;
    this->age = 1;
    this->sign = SHEEP;
}

Sheep::Sheep(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Animal(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = SHEEP;
}

void Sheep::Breed(Organism*)
{
}

const void Sheep::Print()
{
    std::cout << SHEEP;
}

Sheep::~Sheep()
{
}
