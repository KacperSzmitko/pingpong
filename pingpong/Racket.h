#pragma once

#include "Rect.h"
#include "MovingObject.h"

#define RACKET_DEFAULT_MASS 0.160f
#define RACKET_DEFAULT_PIXEL_SIZE_X 5.0f
#define RACKET_DEFAULT_PIXEL_SIZE_Y 35.0f
#define RACKET_DEFAULT_MAX_VELOCITY 50.0f

class Racket : public MovingObject, public Rect {

	friend class Collision;

private:
	bool firstFrame;
	const sf::RenderWindow &windowObj;

public:
	Racket(float posX, float posY);

	void rotation();
	void update();

	~Racket();

	void test();
};

