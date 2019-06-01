#pragma once

#include "Collision.h"
#include "Rect.h"
#include "Racket.h"
#include "Ball.h"
#include "ObjectsVector.h"
#include "SimObject.h"
#include "Table.h"
#include "Player.h"

class Gameplay {

	friend class Collision;

private:

	int mode;
	Wall *wallL,*wallR,*wallD;
	static ObjectsVector<SimObject*> simVector;
	Racket *racket1, *racket2;
	Ball *ball;
	Table *table1,*table2;
	Player *player1;
	Player *player2;

public:
	Gameplay(int mode);

	static Collision collision;

	static ObjectsVector<SimObject*>& getSimVector();
	void simulateObjects();
	void simulate();

	void pause();
	void unpause();

	~Gameplay();

	void objectsTest();
};

