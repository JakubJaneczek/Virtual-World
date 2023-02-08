#pragma once
#include "Organism.h"
class Animal :
    public Organism
{
protected:
    void Breed(Organism* organismToCollide, World* worldReference);
    Animal();
    Animal(World* mWorld, const COORDINATES mPosition);
    Animal(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower);
    
    Organism* NextPositon(const DIRECTION mDir, const int distance);
    void Action() override;
    void Move(DIRECTION mDir);
    void Collision(Organism* organismToCollide) override; 
public:
    const void Print() override;

    ~Animal();
};

