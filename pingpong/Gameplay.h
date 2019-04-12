#pragma once

#include "PhysicalObject.h"
#include "Racket.h"
#include "Ball.h"
#include "Table.h"

class Gameplay {

	Physics *physics;
	Racket *player1;
	//Racket player2;
	Ball *ball;
	Table *table;

	std::vector<PhysicalObject*> collisionObjects;


public:
	Gameplay();

	void collisionCheck();

	~Gameplay();
};

