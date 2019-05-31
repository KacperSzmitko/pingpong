#pragma once

#include "Racket.h"
#include "Table.h"

class Player : public SimObject {
private:
	int mode;
	Racket* racket;
	Table* table;
	int points;

public:
	Player(int mode, Racket* racket, Table* table);

	void move();
	
	void setPoints(int points);
	int getPoints();

	void simulation();

	~Player();
};

