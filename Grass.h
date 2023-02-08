#pragma once
#include "Plant.h"
class Grass :
    public Plant
{
public:
    Grass();
    Grass(World* mWorld, const COORDINATES mPosition);
    Grass(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Grass();
};

