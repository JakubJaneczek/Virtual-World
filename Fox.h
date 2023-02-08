#pragma once
#include "Animal.h"
class Fox :
    public Animal
{
public:
    Fox();
    Fox(World* mWorld, const COORDINATES mPosition);
    Fox(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    void Action() override;
    ~Fox();
};

