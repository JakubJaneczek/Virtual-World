#include "Fox.h"

Fox::Fox(){}

Fox::Fox(World* mWorld, const COORDINATES mPosition)
    :Animal(mWorld, mPosition)
{
	this->power = FOX_POWER;
	this->initiative = FOX_INITIATIVE;
	this->age = 1;
	this->sign = FOX;
}

Fox::Fox(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
	:Animal(mWorld, mPosition, mAge, mInitiative, mPower)
{
	this->sign = FOX;
}

const void Fox::Print()
{
	std::cout << FOX;
}

void Fox::Action()
{
	DIRECTION mDir;
	ChooseDirectionOfMove(mDir);

	if (NextPositon(mDir, 1) == nullptr)
	{
		Move(mDir);
	}
	else
	{
		if (NextPositon(mDir, 1)->GetPower() <= this->GetPower())
		{
			NextPositon(mDir, 1)->Collision(this);
			if (NextPositon(mDir, 1) == nullptr)
			{
				Move(mDir);
			}
		}
	}
}

Fox::~Fox()
{
}
