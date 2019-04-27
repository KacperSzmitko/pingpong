#pragma once

#include "Racket.h"
#include "Ball.h"

class Gameplay {
private:

	Physics physics;
	Racket *player1;
	//Racket player2;
	Ball *ball;

public:
	Gameplay();

	void checkCollisions();

	~Gameplay();

	void objectsTest();
};

