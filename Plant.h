#pragma once
#include "Organism.h"
class Plant :
    public Organism
{
protected:
    Plant();
    Plant(World* mWorld, const COORDINATES mPosition);
    Plant(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    void Action() override;
    void Split(Organism* organismToSplit);
    void Collision(Organism* organismToCollide) override;
    ~Plant();

public:
    const void Print() override;
};

