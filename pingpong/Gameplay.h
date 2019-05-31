#pragma once

#include "Collision.h"
#include "Rect.h"
#include "Racket.h"
#include "Ball.h"
#include "ObjectsVector.h"
#include "SimObject.h"
#include "Table.h"

class Gameplay {

	friend class Collision;

private:

	Physics physics;
	Wall *wallL,*wallR,*wallD;
	static ObjectsVector<SimObject*> simVector;

	
	Racket *player1,*player2;
	//Racket player2;
	Ball *ball;
	Table *table1,*table2;
	


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

