#include "Plant.h"
#include "Belladonna.h"
#include "Dandelion.h"
#include "Grass.h"
#include "Guarana.h"
#include "Pineborscht.h"

Plant::Plant(){}

Plant::Plant(World* mWorld, const COORDINATES mPosition)
	:Organism(mWorld, mPosition) {}

Plant::Plant(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower)
	:Organism(mWorld, mPosition, mAge, mInitiative, mPower) {}

const void Plant::Print(){}

void Plant::Action()
{
	int chance = rand() % 10;
	if (chance < 1)
	{
		Split(this);
	}
}

void Plant::Split(Organism* organismToSplit)
{
	int right = 0, left = 0, up = 0, down = 0;
	COORDINATES temp = organismToSplit->GetPosition();
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

	} while ((temp.x == organismToSplit->GetPosition().x && temp.y == organismToSplit->GetPosition().y) && (right == 0 || left == 0 || up == 0 || down == 0));
	if (dynamic_cast<Grass*>(this))
	{
		worldReference->AddOrganism(new Grass(worldReference, temp), temp);
	}
	else if (dynamic_cast<Dandelion*>(this))
	{
		worldReference->AddOrganism(new Dandelion(worldReference, temp), temp);
	}
	else if (dynamic_cast<Guarana*>(this))
	{
		worldReference->AddOrganism(new Guarana(worldReference, temp), temp);
	}
	else if (dynamic_cast<Pineborscht*>(this))
	{
		worldReference->AddOrganism(new Pineborscht(worldReference, temp), temp);
	}
	else if (dynamic_cast<Belladonna*>(this))
	{
		worldReference->AddOrganism(new Belladonna(worldReference, temp), temp);
	}
	up = 0; down = 0; left = 0; right = 0;
	std::string log = "";
	log += this->GetSign();
	log += " from field (";
	log += std::to_string(organismToSplit->GetPosition().x);
	log += ", ";
	log += std::to_string(organismToSplit->GetPosition().y);
	log += ") creates new plant. ";
	worldReference->Info(log);
}

void Plant::Collision(Organism* organismToCollide)
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
	log += ").";
	worldReference->Info(log);
	worldReference->world[this->position.y][this->position.x] = nullptr;
	this->SetAlive();
}

Plant::~Plant()
{
}
