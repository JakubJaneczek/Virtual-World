#pragma once
#include "DESI.h"
#include "Organism.h"
#include "World.h"


class World
{
	friend class Organism;
	friend class Animal;
protected:
	int sizeX, sizeY;
	int turnNumber = 1;
	int gameStatus = 1;
	std::string info;
	int numberOfOrganisms = 0;
	std::list<Organism*> organisms;
public:
	Organism*** world;
	World();
	World(const int mSizeX, const int mSizeY);
	const void PrintWorld();
	void AddOrganism(Organism* mOrganism, const COORDINATES mPosition);
	void InitiateNewGame();

	void ExecuteRound();
	COORDINATES ChooseRandom();
	const void PrintInfo();
	const void Info(std::string log);
	int GetSizeX();
	int GetSizeY();

	void Menu();
	void Save();
	void Load();

	~World();
};

