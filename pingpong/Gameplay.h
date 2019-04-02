#pragma once

#include "Racket.h"
#include "Ball.h"
#include "Table.h"
#include "Colision.h"

class Gameplay {

	Physics *physics;
	Racket *player1;
	//Racket player2;
	Ball *ball;
	Table *table;


public:
	Gameplay();
	~Gameplay();
};

