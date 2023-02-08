#pragma once
#include "Animal.h"
class Human :
    public Animal
{
private:
    int turnsLeft = 0;
    int turnsCooldown = 0;
    bool AlzurShield = false;

public:
    Human();
    Human(World* mWorld, const COORDINATES mPosition);
    Human(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower, const int turnsLeft, const int turnsCooldown);
    const void Print() override;

    void SetCooldown();
    void DecreaseCooldown();
    void SetTurnsLeft();
    void DecreaseTurnsLeft();
    int GetCooldown();
    int GetTurnsLeft();

    void Action();
    void DirectionOfMove(DIRECTION mDir);
    void UseAbility();
    void DisableAbility();
    void Collision(Organism* organismToCollide);
};

