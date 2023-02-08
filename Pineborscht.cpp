#include "Pineborscht.h"
#include "Animal.h"

#define ORGANISM(Y, X) worldReference->world[position.y + Y][position.x + X]
#define ISANIMAL(Y, X) if(dynamic_cast<Animal*>(ORGANISM(Y, X)))\
{\
temp="";\
temp+=ORGANISM(Y, X)->GetSign();\
temp+=" gets burned by ?";\
worldReference->Info(temp);\
ORGANISM(Y, X) = nullptr;\
}

void Pineborscht::Collision(Organism* organismToCollide)
{
	std::string log = "";
	log += organismToCollide->GetSign();
	log += " from field (";
	log += std::to_string(organismToCollide->GetPosition().x);
	log += ", ";
	log += std::to_string(organismToCollide->GetPosition().y);
	log += ") eats ";
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

void Pineborscht::Action()
{
	int chance = rand() % 10;
	if (chance < 1)
	{
		Split(this);
	}
	Burn();
}

void Pineborscht::Burn()
{
	std::string temp;
	if (position.x == 0) {
		if (position.y == 0) {//top left
			ISANIMAL(1, 0);
			ISANIMAL(1, 1);
			ISANIMAL(0, 1);
		}
		else if (position.y == worldReference->GetSizeY() - 1) {//bot left
			ISANIMAL(-1, 0);
			ISANIMAL(-1, 1);
			ISANIMAL(0, 1);
		}
		else {//left edge
			ISANIMAL(-1, 0);
			ISANIMAL(-1, 1);
			ISANIMAL(0, 1);
			ISANIMAL(1, 0);
			ISANIMAL(1, 1);
		}
	}
	else if (position.x == worldReference->GetSizeX() - 1) {
		if (position.y == 0) {//top right
			ISANIMAL(1, 0);
			ISANIMAL(1, -1);
			ISANIMAL(0, -1);
		}
		else if (position.y == worldReference->GetSizeY() - 1) {//bot right
			ISANIMAL(-1, 0);
			ISANIMAL(-1, -1);
			ISANIMAL(0, -1);
		}
		else {//right edge
			ISANIMAL(-1, 0);
			ISANIMAL(-1, -1);
			ISANIMAL(0, -1);
			ISANIMAL(1, 0);
			ISANIMAL(1, -1);
		}
	}
	else if (position.y == 0) {//top without corners
		ISANIMAL(1, 0);
		ISANIMAL(1, 1);
		ISANIMAL(1, -1);
		ISANIMAL(0, 1);
		ISANIMAL(0, -1);
	}
	else if (position.y == worldReference->GetSizeY() - 1) {//bot without corners
		ISANIMAL(-1, 0);
		ISANIMAL(-1, 1);
		ISANIMAL(-1, -1);
		ISANIMAL(0, 1);
		ISANIMAL(0, -1);
	}
	else {
		ISANIMAL(-1, 0);
		ISANIMAL(-1, 1);
		ISANIMAL(-1, -1);
		ISANIMAL(0, 1);
		ISANIMAL(0, -1);
		ISANIMAL(1, 0);
		ISANIMAL(1, 1);
		ISANIMAL(1, -1);
	}
}

Pineborscht::Pineborscht(){}

Pineborscht::Pineborscht(World* mWorld, const COORDINATES mPosition)
    : Plant(mWorld, mPosition)
{
    this->power = PINEBORSCHT_POWER;
    this->initiative = PINEBORSCHT_INITIATIVE;
    this->age = 1;
    this->sign = PINEBORSCHT;
}

Pineborscht::Pineborscht(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Plant(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = PINEBORSCHT;
}

const void Pineborscht::Print()
{
    std::cout << PINEBORSCHT;
}

Pineborscht::~Pineborscht(){}
