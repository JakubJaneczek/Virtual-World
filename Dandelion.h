#pragma once
#include "Plant.h"
class Dandelion :
    public Plant
{
    void Action() override;
public:
    Dandelion();
    Dandelion(World* mWorld, const COORDINATES mPosition);
    Dandelion(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Dandelion();
};

