#pragma once
#include "Animal.h"
class World;

class Antylope :
    public Animal
{
    int runner;
public:
    Antylope();
    Antylope(World* mWorld, const COORDINATES mPosition);
    Antylope(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    const void Print() override;
    void Move(DIRECTION mDir);
    void Action() override;
    void Collision(Organism* organixmToCollide) override;
    ~Antylope();
};




