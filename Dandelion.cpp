#include "Dandelion.h"

Dandelion::Dandelion()
{
}

Dandelion::Dandelion(World* mWorld, const COORDINATES mPosition)
    : Plant(mWorld, mPosition)
{
    this->power = DANDELION_POWER;
    this->initiative = DANDELION_INITIATIVE;
    this->age = 1;
    this->sign = DANDELION;
}

Dandelion::Dandelion(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Plant(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = DANDELION;
}

const void Dandelion::Print()
{
    std::cout << DANDELION;
}
 
void Dandelion::Action()
{
    for (int i = 0; i < 3; i++)
    {
        int chance = rand() % 20;
        if (chance < 1)
        {
            Split(this);
        }
    }
}

Dandelion::~Dandelion()
{
}
