#include "Antylope.h"
#include "World.h"
#define EMPTY(X, Y) worldReference->world[position.y + Y][position.x + X]
#define ORGANISM(Y, X) worldReference->world[position.y + Y][position.x + X]
Antylope::Antylope()
{
}

Antylope::Antylope(World* mWorld, const COORDINATES mPosition)
    :Animal(mWorld, mPosition)
{
    this->power = ANTYLOPE_POWER;
    this->initiative = ANTYLOPE_INITIATIVE;
    this->age = 1;
    this->sign = ANTYLOPE;
}

Antylope::Antylope(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Animal(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = ANTYLOPE;
}

const void Antylope::Print()
{
    std::cout << ANTYLOPE;
}

void Antylope::Action()
{
	COORDINATES temp = this->GetPosition();
	if (this->GetAge() > 1)
	{
		do
		{
			DIRECTION mDir;
			ChooseDirectionOfMove(mDir);
			if (mDir == UP && position.y > 1 || \
				mDir == DOWN && position.y < worldReference->GetSizeY() - 2 || \
				mDir == RIGHT && position.x < worldReference->GetSizeX() - 2 || \
				mDir == LEFT && position.x > 1)
			{
				if (NextPositon(mDir, 2) == nullptr)
				{
					Move(mDir);
				}
				else if(NextPositon(mDir, 2) != nullptr)
				{
					this->Collision(NextPositon(mDir, 2));
			
					if (NextPositon(mDir, 2) == nullptr && runner == 0)
					{
						Move(mDir);
					}
				}
			}
		} while (temp.x == this->GetPosition().x && temp.y == this->GetPosition().y);
	}
	runner = 0;
}

void Antylope::Move(DIRECTION mDir)
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
		if (position.y > 1)
		{
			ORGANISM(-2, 0) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.y--;
			this->position.y--;
			break;
		}
	case DOWN:
		if (position.y < worldReference->GetSizeY() - 2)
		{
			ORGANISM(2, 0) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.y++;
			this->position.y++;
			break;
		}
	case RIGHT:
		if (position.x < worldReference->GetSizeX() - 2)
		{
			ORGANISM(0, 2) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.x++;
			this->position.x++;
			break;
		}
	case LEFT:
		if (position.x > 1)
		{
			ORGANISM(0, -2) = ORGANISM(0, 0);
			ORGANISM(0, 0) = nullptr;
			this->position.x--;
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

void Antylope::Collision(Organism* organismToCollide)
{
	DIRECTION mDir;
	int chance = rand() % 1;
			
	if (chance == 0 )
	{
		std::string log = "";
		log += this->GetSign();
		log += " runs to safety from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ")";
		worldReference->Info(log);
		if (EMPTY(1, 0) == nullptr && position.x < worldReference->GetSizeX()-1)
		{
			Move(RIGHT);
		}
		else if (EMPTY(-1, 0) == nullptr && position.x > 0)
		{
			Move(LEFT);
		}
		else if (EMPTY(0, 1) == nullptr && position.y < worldReference->GetSizeY()-1)
		{
			Move(DOWN);
		}
		else if (EMPTY(0, -1) == nullptr && position.y > 0)
		{
			Move(UP);
		}
		runner = 1;
	}
	else
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
}

Antylope::~Antylope()
{
}
