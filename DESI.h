#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <list>
#include "conio.h"

#define ANTYLOPE_POWER 4
#define ANTYLOPE_INITIATIVE 4
#define	BELLADONNA_POWER 99
#define	BELLADONNA_INITIATIVE 0
#define	CYBERSHEEP_POWER 11
#define	CYBERSHEEP_INITIATIVE 4
#define	DANDELION_POWER 0
#define	DANDELION_INITIATIVE 0
#define	FOX_POWER 3
#define	FOX_INITIATIVE 7
#define	GRASS_POWER 0	
#define	GRASS_INITIATIVE 0
#define	GUARANA_POWER 0
#define	GUARANA_INITIATIVE 0
#define	HUMAN_POWER 5
#define	HUMAN_INITIATIVE 4
#define	PINEBORSCHT_POWER 10
#define	PINEBORSCHT_INITIATIVE 0
#define	SHEEP_POWER 4
#define	SHEEP_INITIATIVE 4
#define	TURTLE_POWER 2
#define	TURTLE_INITIATIVE 1
#define	WOLF_POWER 9	
#define	WOLF_INITIATIVE 5

#define	ANTYLOPE 'A'
#define	BELLADONNA '!'
#define	CYBERSHEEP 'C'
#define	DANDELION '@'
#define	FOX 'F'
#define	GRASS '.'
#define	GUARANA '#'
#define HUMAN 'H'
#define	PINEBORSCHT '?'
#define	SHEEP 'S'
#define	TURTLE 'T'
#define WOLF 'W'

#define NUMBER_OF_ROUNDS 100

#define	NUMBER_OF_ANTYLOPES 2	
#define	NUMBER_OF_BELLADONNAS 2
#define	NUMBER_OF_CYBERSHEEPS 1
#define	NUMBER_OF_DANDELIONS 2
#define	NUMBER_OF_FOXES 2
#define	NUMBER_OF_GRASS 2
#define	NUMBER_OF_GUARANAS 2
#define	NUMBER_OF_HUMANS 1
#define	NUMBER_OF_PINEBORSCHT 2
#define	NUMBER_OF_SHEEPS 2
#define	NUMBER_OF_TURTLES 2
#define NUMBER_OF_WOLFES 2


enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct COORDINATES {
	int x;
	int y;
};