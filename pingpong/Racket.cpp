#include "pch.h"
#include "Racket.h"
#include "Game.h"

Racket::Racket(float posX, float posY) : 
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, RACKET_FRICTION, RACKET_ELASTICITY, posX, posY),
	windowObj(Game::getWindowObj()) {
	this->firstFrame = true;
}

void Racket::rotation() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) angle -= 0.625f;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) angle += 0.625f;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) angle = 0.0f;
	
	if (angle >= 180.0f) angle -= 180.0f;
	if (angle <= -180.0f) angle += 180.0f;

	dObject->setRotation(angle);
}

void Racket::update() {
	calcElapsedTime();

	oldRealPos = realPos;
	realPos = Physics::swapY(Physics::calcRealVector(windowObj.mapPixelToCoords(sf::Mouse::getPosition(windowObj))));

	if (firstFrame) {
		firstFrame = false;
	} else {
		velocityVector = calcVelocityVector(oldRealPos, realPos, elapsedTime);
		velocity = calcVelocityFromVelocityVector(velocityVector);
		if (velocity != 0.0f) {
			unitVector = calcUnitVector(velocityVector, velocity);
		}
		if (velocity > RACKET_DEFAULT_MAX_VELOCITY) {
			velocity = RACKET_DEFAULT_MAX_VELOCITY;
		}
		kineticEnergy = calcKineticEnergy(mass, velocity);
	}

	dObject->setPosition(Physics::swapY(Physics::calcPixelVector(realPos)));
	rotation();
	
	

}

Racket::~Racket() {

}

void Racket::test() {
	std::cout << angle << std::endl;
}
