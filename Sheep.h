#pragma once
#include "Animal.h"
class Sheep :
    public Animal
{
private:
    void Breed(Organism*);
public:
    Sheep();
    Sheep(World* mWorld, const COORDINATES mPosition);
    Sheep(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Sheep();
};

