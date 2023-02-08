#include "Grass.h"

Grass::Grass(){}

Grass::Grass(World* mWorld, const COORDINATES mPosition)
    : Plant(mWorld, mPosition)
{
    this->power = GRASS_POWER;
    this->initiative = GRASS_INITIATIVE;
    this->age = 1;
    this->sign = GRASS;
}

Grass::Grass(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Plant(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = GRASS;
}

const void Grass::Print()
{
    std::cout << GRASS;
}

Grass::~Grass(){}
