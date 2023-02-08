#pragma once
#include "DESI.h"
#include "World.h"

class Organism
{
	friend class World;
protected:
	int age = 0;
	int initiative;
	int power;
	int alive = 1;
	int breedCooldown = 0;
	COORDINATES position;
	char sign;
public:
	World *worldReference;

	Organism();
	Organism(World* mWorld, const COORDINATES mPosition); //Organizmy w nowym œwiecie
	Organism(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower); //Organizmy ze œwiata zapisanego

	virtual const void Print() = 0;
	virtual void Action();
	virtual void Collision(Organism* organismToCollide);

	bool IsPlaceAvailable(const COORDINATES mPosition);

	void ChooseDirectionOfMove(DIRECTION& mDir);

	const COORDINATES GetPosition();
	const int GetAge();
	const int GetInitiative();
	const int GetPower();
	const char GetSign();
	const void SetAlive();
	const int GetAlive();
	const void SetPower(int number);
	const void SetBreedCd(int number);
	const int GetBreedCd();

	~Organism();
};

