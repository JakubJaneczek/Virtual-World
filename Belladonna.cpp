#include "Belladonna.h"

void Belladonna::Collision(Organism* organismToCollide)
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

Belladonna::Belladonna()
{
}

Belladonna::Belladonna(World* mWorld, const COORDINATES mPosition)
    : Plant(mWorld, mPosition)
{
    this->power = BELLADONNA_POWER;
    this->initiative = BELLADONNA_INITIATIVE;
    this->age = 1;
    this->sign = BELLADONNA;
}

Belladonna::Belladonna(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Plant(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = BELLADONNA;
}

const void Belladonna::Print()
{
    std::cout << BELLADONNA;
}

Belladonna::~Belladonna()
{
}
