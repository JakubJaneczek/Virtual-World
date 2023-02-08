#pragma once
#include "Plant.h"
class Pineborscht :
    public Plant
{
    void Collision(Organism* organismToCollide);
    void Action() override;
    void Burn();
public:
    Pineborscht();
    Pineborscht(World* mWorld, const COORDINATES mPosition);
    Pineborscht(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Pineborscht();
};

