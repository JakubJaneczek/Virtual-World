#pragma once
#include "Animal.h"
class Turtle :
    public Animal
{
public:
    Turtle();
    Turtle(World* mWorld, const COORDINATES mPosition);
    Turtle(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    void Collision(Organism* organismToCollide) override;
    void Action() override;
    ~Turtle();
};

