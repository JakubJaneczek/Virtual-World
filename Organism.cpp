#include "Organism.h"

Organism::Organism(){}

Organism::Organism(World* mWorld, const COORDINATES mPosition)
{
    this->worldReference = mWorld;
    this->position = mPosition;
}

Organism::Organism(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
{
    this->worldReference = mWorld;
    this->position = mPosition;
    this->age = mAge;
    this->initiative = mInitiative;
    this->power = mPower;
}

void Organism::Action()
{
}

const void Organism::Print()
{
}

void Organism::Collision(Organism* organismToCollide)
{
}

bool Organism::IsPlaceAvailable(const COORDINATES mPosition)
{
	if (mPosition.y >= 0 && mPosition.y < worldReference->GetSizeY() - 1 && mPosition.x >= 0 && mPosition.x < worldReference->GetSizeX() - 1)
	{
		if (worldReference->world[mPosition.y][mPosition.x] == nullptr)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

void Organism::ChooseDirectionOfMove(DIRECTION& mDir)
{
	int mTemp;
	if (position.x == 0)
	{
		if (position.y == 0) // LEWA GÓRA
		{
			mTemp = rand() % 2;
			switch (mTemp)
			{
			case 0:
				mDir = DOWN;
				break;
			case 1:
				mDir = RIGHT;
				break;
			}
		}
		else if (position.y == worldReference->GetSizeY() - 1) //LEWY DÓ£
		{
			mTemp = rand() % 2;
			switch (mTemp)
			{
			case 0:
				mDir = UP;
				break;
			case 1:
				mDir = RIGHT;
				break;
			}
		}
		else	//LEWO
		{
			mTemp = rand() % 3;
			switch (mTemp)
			{
			case 0:
				mDir = DOWN;
				break;
			case 1:
				mDir = RIGHT;
				break;
			case 2:
				mDir = UP;
				break;
			}
		}
	}
	else if (position.x == worldReference->GetSizeX() - 1)
	{
		if (position.y == worldReference->GetSizeY() - 1) //PRAWY DÓ£
		{
			mTemp = rand() % 2;
			switch (mTemp)
			{
			case 0:
				mDir = UP;
				break;
			case 1:
				mDir = LEFT;
				break;
			}
		}
		else if (position.y == 0) //PRAWO GÓRA
		{
			mTemp = rand() % 2;
			switch (mTemp)
			{
			case 0:
				mDir = DOWN;
				break;
			case 1:
				mDir = LEFT;
				break;
			}
		}
		else	//PRAWO
		{
			mTemp = rand() % 3;
			switch (mTemp)
			{
			case 0:
				mDir = UP;
				break;
			case 1:
				mDir = LEFT;
				break;
			case 2:
				mDir = DOWN;
				break;
			}
		}
	}
	else if (position.y == worldReference->GetSizeY() - 1)	//DÓ£
	{
		mTemp = rand() % 3;
		switch (mTemp)
		{
		case 0:
			mDir = UP;
			break;
		case 1:
			mDir = RIGHT;
			break;
		case 2:
			mDir = LEFT;
			break;
		}
	}
	else if (position.y == 0) //GÓRA
	{
		mTemp = rand() % 3;
		switch (mTemp)
		{
		case 0:
			mDir = LEFT;
			break;
		case 1:
			mDir = RIGHT;
			break;
		case 2:
			mDir = DOWN;
			break;
		}
	}
	else // ŒRODEK
	{
		mDir = DIRECTION(rand() % 4);
	}
}

const void Organism::SetBreedCd(int number)
{
    breedCooldown -= number;
}

const int Organism::GetBreedCd()
{
    return breedCooldown;
}

const COORDINATES Organism::GetPosition()
{
    return this->position;
}

const int Organism::GetAge()
{
    return this->age;
}

const int Organism::GetInitiative()
{
    return this->initiative;
}

const int Organism::GetPower()
{
    return this->power;
}

const char Organism::GetSign()
{
    return this->sign;
}

const void Organism::SetAlive()
{
    alive = 0;
}

const int Organism::GetAlive()
{
    return alive;
}

const void Organism::SetPower(int number)
{
	power = power + number;
}

Organism::~Organism()
{
}
