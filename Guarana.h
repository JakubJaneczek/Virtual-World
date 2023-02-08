#pragma once
#include "Plant.h"
class Guarana :
    public Plant
{
    void Collision(Organism* organismToCollide );
public:
    Guarana();
    Guarana(World* mWorld, const COORDINATES mPosition);
    Guarana(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    ~Guarana();
};

