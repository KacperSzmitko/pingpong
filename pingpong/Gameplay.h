#pragma once

#include "Collision.h"
#include "Rect.h"
#include "Racket.h"
#include "Ball.h"
#include "ObjectsVector.h"
#include "SimObject.h"

class Gameplay {

	friend class Collision;

private:

	static ObjectsVector<SimObject*> simVector;

	Physics physics;
	Racket *player1;
	//Racket player2;
	Ball *ball;
	Rect *table;
	Wall *wall;


public:
	Gameplay();

	static Collision collision;

	static ObjectsVector<SimObject*>& getSimVector();
	void simulateObjects();
	void simulate();

	void pause();
	void unpause();

	~Gameplay();

	void objectsTest();
};

