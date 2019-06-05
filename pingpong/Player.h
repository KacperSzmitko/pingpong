#pragma once

#include "Racket.h"
#include "Table.h"
#include "Ball.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Player : public SimObject {
	friend class Collision;
private:
	int mode;
	Racket* racket;
	Table* table;
	Ball* ball;
	int points;
	float licz;
	float pom;
	int playerNumber;
	static bool TPMousePlayer1, TPMousePlayer2;
	
public:
	Player(int mode, Racket* racket, Table* table, Ball* ball, int playerNumber);

	void move();
	void moveTowardsPoint(sf::Vector2f point,float speed1,float speed2);
	void setPoints(int points);
	int getPoints();

	void simulation();

	~Player();
};

