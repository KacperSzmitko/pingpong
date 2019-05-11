#pragma once

#include "Collision.h"
#include "Rect.h"
#include "Racket.h"
#include "Ball.h"
#include "ObjectsVector.h"

class Gameplay {

	friend class Collision;

private:

	Physics physics;
	Wall *wallL,*wallR,*wallD;
	Racket *player1;
	//Racket player2;
	Ball *ball;

	Rect *table;
	Wall *wall;


public:
	Gameplay();

	static Collision collision;

	void checkCollisions();

	void pause();
	void unpause();

	~Gameplay();

	void objectsTest();
};

