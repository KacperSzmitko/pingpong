#pragma once

#include "Collision.h"
#include "Rect.h"
#include "Racket.h"
#include "Ball.h"
#include "ObjectsVector.h"

class Gameplay {
private:

	Physics physics;
	Collision collision;

	Racket *player1;
	//Racket player2;
	Ball *ball;

	Rect *table;

	static ObjectsVector<Rect*> rectCollisionVector;

public:
	Gameplay();

	ObjectsVector<Rect*>& getRectCollisionVector();

	void checkCollisions();

	void pause();
	void unpause();

	~Gameplay();

	void objectsTest();
};

