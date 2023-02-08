#include "Turtle.h"

Turtle::Turtle()
{
}

Turtle::Turtle(World* mWorld, const COORDINATES mPosition)
	:Animal(mWorld, mPosition)
{
	this->power = TURTLE_POWER;
	this->initiative = TURTLE_INITIATIVE;
	this->age = 1;
	this->sign = TURTLE;
}

Turtle::Turtle(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
	:Animal(mWorld, mPosition, mAge, mInitiative, mPower)
{
	this->sign = TURTLE;
}

const void Turtle::Print()
{
	std::cout << TURTLE;
}

void Turtle::Collision(Organism* organismToCollide)
{
	if (organismToCollide->GetSign() == this->GetSign())
	{
		Breed(organismToCollide, worldReference);
	}
	else if (organismToCollide->GetPower() < 5)
	{
		std::string log = "";
		log += organismToCollide->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") was stopped by ";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ").";
		worldReference->Info(log);
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

void Turtle::Action()
{
	if (this->GetAge() > 1)
	{
		int chance = rand() % 4;
		if (chance < 3)
		{
			std::string log = "";
			log += "T decides to not move";
			worldReference->Info(log);
		}
		else
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
}

Turtle::~Turtle()
{
}
