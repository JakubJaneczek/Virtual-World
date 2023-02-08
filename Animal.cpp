#include "World.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Antylope.h"
#include "Fox.h"
#include "Turtle.h"
#define ORGANISM(Y, X) worldReference->world[position.y + Y][position.x + X]

Animal::Animal() {}

Animal::Animal(World* mWorld, const COORDINATES mPosition)
	:Organism(mWorld, mPosition) {}

Animal::Animal(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
	:Organism(mWorld, mPosition, mAge, mInitiative, mPower){}

const void Animal::Print(){}

Organism* Animal::NextPositon(const DIRECTION mDir, const int distance)
{
	switch (mDir)
	{
	case UP:
		return ORGANISM(-distance, 0);
		break;
	case DOWN:
		return ORGANISM(+distance, 0);
		break;
	case RIGHT:
		return ORGANISM(0, +distance);
		break;
	case LEFT:
		return ORGANISM(0, -distance);
		break;
	}
}

void Animal::Action()
{
	if (this->GetAge() > 0)
	{
		DIRECTION mDir;
		ChooseDirectionOfMove(mDir);

		if (NextPositon(mDir, 1) == nullptr)
		{
			Move(mDir);
		}
		else
		{
			NextPositon(mDir, 1)->Collision(this);
			if (NextPositon(mDir, 1) == nullptr)
			{
				Move(mDir);
			}
		}
	}
}

void Animal::Move(DIRECTION mDir)
{
	std::string log = "";
	log += this->GetSign();
	log += " moves from field (";
	log += std::to_string(this->GetPosition().x);
	log += ", ";
	log += std::to_string(this->GetPosition().y);
	log += ") to field ";
	switch (mDir)
	{
	case UP:
		if (position.y != 0)
		{
			ORGANISM(-1, 0) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.y--;
			break;
		}
	case DOWN:
		if (position.y != worldReference->GetSizeY() - 1)
		{
			ORGANISM(1, 0) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.y++;
			break;
		}
	case RIGHT:
		if (position.x != worldReference->GetSizeX() - 1)
		{
			ORGANISM(0, 1) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.x++;
			break;
		}
	case LEFT:
		if (position.x != 0)
		{
			ORGANISM(0, -1) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.x--;
			break;
		}
	}
	log += "(";
	log += std::to_string(this->GetPosition().x);
	log += ", ";
	log += std::to_string(this->GetPosition().y);
	log += ").";
	worldReference->Info(log);
}

void Animal::Collision(Organism* organismToCollide)
{
	if (organismToCollide->GetSign() == this->GetSign())
	{
		Breed(organismToCollide, worldReference);
	}
	else if (organismToCollide->GetPower() < this->GetPower())
	{
		std::string log = "";
		log += organismToCollide->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") attacks stronger ";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ") and dies.";
		worldReference->Info(log);
		worldReference->world[organismToCollide->GetPosition().y][organismToCollide->GetPosition().x] = nullptr;
		organismToCollide->SetAlive();
	}
	else
	{
		std::string log = "";
		log += organismToCollide->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") attacks weaker ";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ") and kills his opponent.";
		worldReference->Info(log);
		worldReference->world[this->position.y][this->position.x] = nullptr;
		this->SetAlive();
	}
}

void Animal::Breed(Organism* organismToCollide, World* worldReference)
{
	if (organismToCollide->GetAge() > 2 && this->GetAge() > 2 && organismToCollide->GetBreedCd() == 0 && this->GetBreedCd() == 0)
	{
		int right = 0, left = 0, up = 0, down = 0;
		COORDINATES temp = organismToCollide->GetPosition();
		do
		{
			DIRECTION mDir = DIRECTION(rand() % 4);
			switch (mDir)
			{
			case RIGHT:
				if (IsPlaceAvailable({ temp.x + 1, temp.y }))
				{
					temp.x++;
				}
				else
					right++;
				break;
			case LEFT:
				if (IsPlaceAvailable({ temp.x - 1, temp.y }))
				{
					temp.x--;
				}
				else
					left++;
				break;
			case UP:
				if (IsPlaceAvailable({ temp.x, temp.y - 1 }))
				{
					temp.y--;
				}
				else
					up++;
				break;
			case DOWN:
				if (IsPlaceAvailable({ temp.x, temp.y + 1 }))
				{
					temp.y++;
				}
				else
					down++;
				break;
			}

		} while ((temp.x == organismToCollide->GetPosition().x && temp.y == organismToCollide->GetPosition().y) || (right == 0 || left == 0 || up == 0 || down == 0));
		if (dynamic_cast<Wolf*>(this))
		{
			worldReference->AddOrganism(new Wolf(worldReference, temp), temp);
		}
		else if (dynamic_cast<Sheep*>(this))
		{
			worldReference->AddOrganism(new Sheep(worldReference, temp), temp);
		}
		else if (dynamic_cast<Fox*>(this))
		{
			worldReference->AddOrganism(new Fox(worldReference, temp), temp);
		}
		else if (dynamic_cast<Antylope*>(this))
		{
			worldReference->AddOrganism(new Antylope(worldReference, temp), temp);
		}
		else if (dynamic_cast<Turtle*>(this))
		{
			worldReference->AddOrganism(new Turtle(worldReference, temp), temp);
		}
		std::string log = "";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") breeds with ";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ") creating new animal at field (";
		log += std::to_string(temp.x);
		log += ", ";
		log += std::to_string(temp.y);
		log += ").";
		worldReference->Info(log);
		this->SetBreedCd(-2);
		organismToCollide->SetBreedCd(-2);
		up = 0; down = 0; left = 0; right = 0;
	}
}

Animal::~Animal()
{

}

