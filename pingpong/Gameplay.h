#pragma once

#include "Racket.h"
#include "Ball.h"

class Gameplay {

	Physics physics;
	Racket *player1;
	//Racket player2;
	Ball *ball;

	std::vector<PhysicalObject*> collisionVector;

public:
	Gameplay();
	~Gameplay();

	void objectsTest();
};

