#pragma once
#include "Plant.h"
class Belladonna :
    public Plant
{
    void Collision(Organism* organismToCollide);
public:
    Belladonna();
    Belladonna(World* mWorld, const COORDINATES mPosition);
    Belladonna(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Belladonna();
};

