#include "Guarana.h"

Guarana::Guarana(){}

Guarana::Guarana(World* mWorld, const COORDINATES mPosition)
    : Plant(mWorld, mPosition)
{
    this->power = GUARANA_POWER;
    this->initiative = GUARANA_INITIATIVE;
    this->age = 1;
    this->sign = GUARANA;
}

Guarana::Guarana(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
    : Plant(mWorld, mPosition, mAge, mInitiative, mPower)
{
    this->sign = GUARANA;
}

const void Guarana::Print()
{
    std::cout << GUARANA;
}

void Guarana::Collision(Organism* organismToCollide)
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
	organismToCollide->SetPower(3);
	log += ") and gains 3 power. Now it's power is: ";
	log += std::to_string(organismToCollide->GetPower());
	worldReference->Info(log);
	worldReference->world[this->position.y][this->position.x] = nullptr;
	this->SetAlive();
}

Guarana::~Guarana()
{
}
