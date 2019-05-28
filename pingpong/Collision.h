#pragma once

#include "Racket.h"
#include "Ball.h"
#include "Wall.h"
#include "Table.h"
#include "ObjectsVector.h"


class Collision {
private:
	static ObjectsVector<Wall*> walls;
	static ObjectsVector<Racket*> rackets;
	static ObjectsVector<Ball*> balls;
	static ObjectsVector<Table*> tables;
	
	sf::Vector2f BallVelocityAfterColision;
	unsigned short ballRectCheck(Ball *ball, Rect *rect);
	void ballWallCol(Ball *ball, Wall *wall);
	void ballRacketCol(Ball *ball, Racket *racket);
	void ballTableCol(Ball *ball, Table *table);
	void calcballRacketCol(Ball *ball, Racket *racket);
	void calcballTableCol(Ball *ball, Table *table);

	void p1Point(Ball *ball);
	void p2Point(Ball *ball);

public:
	
	static ObjectsVector<Wall*> &getWallCollisionVector();
	static ObjectsVector<Racket*> &getRacketCollisionVector();
	static ObjectsVector<Ball*> &getBallCollisionVector();
	static ObjectsVector<Table*> &getTableCollisionVector();
	void checkCollisions();

	
	
	
	~Collision();

	
};

