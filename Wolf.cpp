#include "Wolf.h"

Wolf::Wolf() {}

Wolf::Wolf(World* mWorld, const COORDINATES mPosition)
	:Animal(mWorld, mPosition) 
{
	this->power = WOLF_POWER;
	this->initiative = WOLF_INITIATIVE;
	this->age = 1;
	this->sign = WOLF;
}

Wolf::Wolf(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
	:Animal(mWorld, mPosition, mAge, mInitiative, mPower)
{
	this->sign = WOLF;
}

const void Wolf::Print()
{
	std::cout << WOLF;
}

Wolf::~Wolf()
{
}
