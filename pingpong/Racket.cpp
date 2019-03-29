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
	DrawnObject(new sf::RectangleShape({ DEFAULT_RACKET_SIZE_X, DEFAULT_RACKET_SIZE_Y })),
	PhysicalObject(physics, posX, posY, DEFAULT_RACKET_MASS) {

	this->firstFrame = true;
}


void Racket::update() {
	calcElapsedTime();

	newRealPos = calcRealPos(sf::Mouse::getPosition(Game::getWindowObj()));

	if (firstFrame) {
		firstFrame = false;
	} else {
		velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
		velocity = calcVelocityFromVelocityVector(velocityVector);
		if (velocity > DEFAULT_MAX_RACKET_VELOCITY) {
			velocity = DEFAULT_MAX_RACKET_VELOCITY;
		}
		kineticEnergy = calcKineticEnergy(mass, velocity);
	}

	dObject->setPosition(calcPixelPos(newRealPos));
	lastRealPos = newRealPos;

	

	//Testy
	std::cout << velocity << " m/s " << kineticEnergy << " J" << std::endl;
}

Racket::~Racket() {}
