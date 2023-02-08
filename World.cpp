#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Antylope.h"
#include "Fox.h"
#include "Turtle.h"
#include "Grass.h"
#include "Guarana.h"
#include "Dandelion.h"
#include "Pineborscht.h"
#include "Belladonna.h"
#include "Human.h"

World::World()
{
}

World::World(const int mSizeX, const int mSizeY)
{
	this->sizeX = mSizeX;
	this->sizeY = mSizeY;
	world = new Organism**[mSizeY];
	for (int i = 0; i < mSizeY; i++)
	{
		world[i] = new Organism* [mSizeX];
	}
	for (int i = 0; i < mSizeY; i++)
	{
		for (int j = 0; j < mSizeX; j++)
		{
			world[i][j] = nullptr;
		}
	}
}

const void World::PrintWorld()
{
	std::cout << " ";
	for (int j = 0; j < sizeX; j++)
	{
		std::cout << j % 10 << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < sizeY; i++)
	{
		std::cout << i % 10;
		for (int j = 0; j < sizeX; j++)
		{

			if (world[i][j] == nullptr)
			{
				std::cout << "  ";
			}
			else
			{
				world[i][j]->Print();
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

void World::AddOrganism(Organism* mOrganism, const COORDINATES mPosition)
{
	world[mPosition.y][mPosition.x] = mOrganism;
	
	if (organisms.size() == 0)
	{
		organisms.push_front(mOrganism);
	}
	else
	{
		for (auto tempOrganism : organisms)
		{
			if (mOrganism->GetInitiative() > tempOrganism->GetInitiative())
			{
				auto position = find(organisms.begin(), organisms.end(), tempOrganism);
				organisms.insert(position, mOrganism);
				return;
			}
			else
				continue;
		}
		organisms.push_back(mOrganism);
	}
}

void World::InitiateNewGame()
{
	COORDINATES temp = {};
	for (int i = 0; i < NUMBER_OF_HUMANS; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Human(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_ANTYLOPES; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Antylope(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_BELLADONNAS; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Belladonna(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_DANDELIONS; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Dandelion(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_FOXES; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Fox(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_GRASS; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Grass(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_GUARANAS; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Guarana(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_PINEBORSCHT; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Pineborscht(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_SHEEPS; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Sheep(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_TURTLES; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Turtle(this, temp), temp);
	}
	for (int i = 0; i < NUMBER_OF_WOLFES; i++)
	{
		temp = ChooseRandom();
		AddOrganism(new Wolf(this, temp), temp);
	}
}

void World::ExecuteRound()
{
	for (Organism* organism : organisms)
	{
		if (organism->GetAlive() == 1)
		{
			if (_getch() == 'r')
			{
				Save();
			}
			else
			{
				system("cls");
				PrintWorld();
				organism->Action();
				PrintInfo();
				info = "";
			}
		}
	}
	std::list<Organism*> toRemove;
	for (Organism* organism : organisms)
	{
		
		if (dynamic_cast<Wolf*>(organism))
		{
			if (!dynamic_cast<Wolf*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Sheep*>(organism))
		{
			if (!dynamic_cast<Sheep*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Antylope*>(organism))
		{
			if (!dynamic_cast<Antylope*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Fox*>(organism))
		{
			if (!dynamic_cast<Fox*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Turtle*>(organism))
		{
			if (!dynamic_cast<Turtle*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Belladonna*>(organism))
		{
			if (!dynamic_cast<Belladonna*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Pineborscht*>(organism))
		{
			if (!dynamic_cast<Pineborscht*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Guarana*>(organism))
		{
			if (!dynamic_cast<Guarana*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Belladonna*>(organism))
		{
			if (!dynamic_cast<Turtle*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
		else if (dynamic_cast<Grass*>(organism))
		{
			if (!dynamic_cast<Grass*>(world[organism->position.y][organism->position.x]))
			{
				toRemove.push_back(organism);
			}
		}
	}

	for (Organism* organism : toRemove)
	{
		organisms.remove(organism);
	}
	while (toRemove.size() != 0)
	{
		toRemove.pop_back();
	}
	for (Organism* temp : organisms)
	{
		if (temp->GetBreedCd() > 0)
		{
			temp->SetBreedCd(-1);
		}
		temp->age++;
	}
}

COORDINATES World::ChooseRandom()
{
	COORDINATES mPosition;
	for (;;)
	{
		mPosition.x = rand() % sizeX;
		mPosition.y = rand() % sizeY;
		if (world[mPosition.y][mPosition.x] == nullptr)
		{
			return mPosition;
			break;
		}
	}
}

const void World::Info(std::string log)
{
	this->info += log;
	this->info += '\n';
}

const void World::PrintInfo()
{
	std::cout << info;
	info = "";
}

int World::GetSizeY()
{
	return sizeY;
}

void World::Menu()
{
	int choice;
	std::cout << "Choose what you want to do: \n 1 -> Start new game \n 2 -> Load game from file \n 3 -> Exit \n";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int mapSizeX, mapSizeY;
		std::cout << "Insert map size (x, y)" << std::endl;
		std::cin >> mapSizeX >> mapSizeY;
		std::cout << std::endl;
		World world(mapSizeX, mapSizeY);
		world.InitiateNewGame();
		for (int i = 0; i < NUMBER_OF_ROUNDS; i++)
		{
			world.ExecuteRound();
		}
		break;
	}
	case 2:
		Load();
		for (int i = 0; i < NUMBER_OF_ROUNDS; i++)
		{
			ExecuteRound();
		}
		break;
	case 3:
		exit(0);
	}

}

void World::Save()
{
	std::fstream file;
	system("cls");
	std::cout << "File name: ";
	std::string name; 
	std::cin >> name;

	file.open(name, std::fstream::out);
	if (file.good())
	{
		std::cout << "File OK" << std::endl;
		file << sizeX << " " << sizeY << " " << organisms.size() << std::endl;
		for (Organism* temp : organisms) {
			file << temp->GetSign() << " ";
			file << temp->GetAge() << " ";
			file << temp->GetInitiative() << " ";
			file << temp->GetPosition().x << " " << temp->GetPosition().y << " ";
			file << temp->GetPower() << " ";
			if (dynamic_cast<Human*>(temp)) {
				Human* temp_h = dynamic_cast<Human*> (temp);
				file << temp_h->GetCooldown() << " ";
				file << temp_h->GetTurnsLeft() << " ";
			}
			file << std::endl;
		}
		file.close();
		std::cout << "Map saved to " << name << std::endl;
		std::cout << "Click any button to return." << std::endl;
		system("cls");
		this->PrintWorld();
	}
	else
	{
		std::cout << "File NOT ok" << std::endl;
		return;
	}
}

void World::Load()
{
	std::fstream file;
	system("cls");
	std::cout << "File name: ";
	std::string name;
	std::cin >> name;

	file.open(name, std::fstream::in);
	if (!file.good()) {
		std::cout << "File doesn't exist!" << std::endl;
		std::cout << "Click any button to return to game" << std::endl;
		system("cls");
		Menu();
	}
	else
	{
		int numberOfOrganisms;
		char sign;
		int mSizeY, mSizeX;
		int age, initiative, power, turnsLeft, turnsCooldown;
		COORDINATES position;
		file >> mSizeX >> mSizeY >> numberOfOrganisms;
		this->sizeX = mSizeX;
		this->sizeY = mSizeY;
		world = new Organism**[mSizeY];
		for (int i = 0; i < mSizeY; i++)
		{
			world[i] = new Organism*[mSizeX];
		}
		for (int i = 0; i < mSizeY; i++)
		{
			for (int j = 0; j < mSizeX; j++)
			{
				world[i][j] = nullptr;
			}
		}
		for (int i = 0; i < numberOfOrganisms; i++)
		{
			file >> sign >> age >> initiative >> position.x >> position.y >> power;
			switch (sign) 
			{
				case HUMAN:
				{
					file >>turnsCooldown >> turnsLeft;
					Human* newH = new Human(this, { position.x,position.y }, age, initiative, power, turnsLeft, turnsCooldown);
					AddOrganism(newH, newH->GetPosition());
					break;
				}
				case SHEEP:
				{
					Sheep* newS = new Sheep(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newS, newS->GetPosition());
					break;
				}
				case WOLF:
				{
					Wolf* newW = new Wolf(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newW, newW->GetPosition());
					break;
				}
				case FOX:
				{
					Fox* newF = new Fox(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newF, newF->GetPosition());
				break;
				}
				case TURTLE:
				{
					Turtle* newT = new Turtle(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newT, newT->GetPosition());
					break;
				}
				case ANTYLOPE:
				{
					Antylope* newA = new Antylope(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newA, newA->GetPosition());
					break;
				}
				case GRASS:
				{
					Grass* newG = new Grass(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newG, newG->GetPosition());
					break;
				}
				case DANDELION:
				{
					Dandelion* newD = new Dandelion(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newD, newD->GetPosition());
					break;
				}
				case GUARANA:
				{
					AddOrganism(new Guarana(this, { position.x,position.y }, age, initiative, power), { position.x,position.y });
					break;
				}
				case BELLADONNA:
				{
					AddOrganism(new Belladonna(this, { position.x,position.y }, age, initiative, power), { position.x,position.y });
					break;
				}
				case PINEBORSCHT:
				{
					Pineborscht* newPB = new Pineborscht(this, { position.x,position.y }, age, initiative, power);
					AddOrganism(newPB, newPB->GetPosition());
					break;
				}
			}
		}
		file.close();
		std::cout << "Map read from " << name << std::endl;
		std::cout << "Click any button to return." << std::endl;
		if (_getch() == 224);
		system("cls");
		this->PrintWorld();
	}
}

int World::GetSizeX()
{
	return sizeX;
}

World::~World()
{
}