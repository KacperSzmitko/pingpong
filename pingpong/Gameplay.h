#pragma once

#include "Collision.h"
#include "Rect.h"
#include "Racket.h"
#include "Ball.h"
#include "ObjectsVector.h"
#include "SimObject.h"
#include "Table.h"
#include "Player.h"
#include "Score.h"

class Gameplay : public UpdateObject {

	friend class Collision;

private:

	int mode;
	Wall *wallL,*wallR,*wallD;
	static ObjectsVector<SimObject*> simVector;
	Racket *racket1, *racket2;
	Ball *ball;
	Table *table1,*table2,*net;
	Player *player1;
	Player *player2;
	Score score;

public:
	Gameplay(int mode);
	static sf::Vector2f default_ballLPos, default_ballRPos, default_racketLPos, default_racketRPos;
	static int player1Score, player2Score;
	static Collision collision;

	static ObjectsVector<SimObject*>& getSimVector();
	void simulateObjects();
	void simulate();
	void update();

	void pause();
	void unpause();

	~Gameplay();

	void objectsTest();
};

