#include "pch.h"
#include "Racket.h"

Racket::Racket(Physics *physics, float sizeX, float sizeY, float mass, float posX, float posY) :
	UpdateObject(), 
	DrawnObject(new sf::RectangleShape({ sizeX, sizeY })),
	PhysicalObject(physics, mass, posX, posY) {

	this->firstFrame = true;
}

Racket::Racket(Physics *physics, float posX, float posY) :
	UpdateObject(),
	DrawnObject(new sf::RectangleShape({ RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y })),
	PhysicalObject(physics, posX, posY, RACKET_DEFAULT_MASS) {

	this->firstFrame = true;
}


void Racket::update() {
	calcElapsedTime();

	newRealPos = calcRealVector(sf::Mouse::getPosition(Game::getWindowObj()));

	if (firstFrame) {
		firstFrame = false;
	} else {
		velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
		velocity = calcVelocityFromVelocityVector(velocityVector);
		if (velocity > RACKET_DEFAULT_MAX_VELOCITY) {
			velocity = RACKET_DEFAULT_MAX_VELOCITY;
		}
		kineticEnergy = calcKineticEnergy(mass, velocity);
	}

	dObject->setPosition(calcPixelVector(newRealPos));
	lastRealPos = newRealPos;

	

	//Testy
	std::cout << velocity << " m/s " << kineticEnergy << " J" << std::endl;
}

Racket::~Racket() {}
