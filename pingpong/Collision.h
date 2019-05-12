#pragma once

#include "Racket.h"
#include "Ball.h"
#include "Wall.h"
#include "ObjectsVector.h"

class Collision {
private:
	static ObjectsVector<Wall*> walls;
	static ObjectsVector<Racket*> rackets;
	static ObjectsVector<Ball*> balls;
	bool p1=true, p2=false; //Gracze, mowi ktory gracz ma w danym momencie prawo do odbicia pilki
	unsigned short ballRectCheck(Ball *ball, Rect *rect);
	void ballWallCol(Ball *ball, Wall *wall);
	void ballRacketCol(Ball *ball, Racket *racket);

public:
	
	static ObjectsVector<Wall*> &getWallCollisionVector();
	static ObjectsVector<Racket*> &getRacketCollisionVector();
	static ObjectsVector<Ball*> &getBallCollisionVector();

	void checkCollisions();

	
	
	
	~Collision();

	
};

