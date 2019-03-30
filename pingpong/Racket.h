#pragma once

#include "DrawnObject.h"
#include "UpdateObject.h"
#include "PhysicalObject.h"

#define RACKET_DEFAULT_MASS 0.160f
#define RACKET_DEFAULT_PIXEL_SIZE_X 5.0f
#define RACKET_DEFAULT_PIXEL_SIZE_Y 35.0f
#define RACKET_DEFAULT_MAX_VELOCITY 50.0f

class Racket : public DrawnObject<sf::RectangleShape>, public UpdateObject, public PhysicalObject {
private:
	bool firstFrame;
	const sf::RenderWindow &windowObj;

public:
	Racket(Physics *physics, float sizeX, float sizeY, float mass, float posX, float posY);
	Racket(Physics *physics, float posX, float posY);

	void update();

	~Racket();
};

