#pragma once
#include "Animal.h"
#include "DESI.h"

class Wolf :
    public Animal
{
public:
    Wolf();
    Wolf(World* mWorld, const COORDINATES mPosition);
    Wolf(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Wolf();
};

