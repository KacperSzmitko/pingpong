#include "pch.h"
#include "Racket.h"
#include "Game.h"

Racket::Racket(float posX, float posY) : 
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY),
	windowObj(Game::getWindowObj()) {
	this->firstFrame = true;
	Collision::getRacketCollisionVector()._add(this);
}

void Racket::rotation() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) angle -= 225.0f * elapsedTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) angle += 225.0f * elapsedTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) angle = 0.0f;
	
	if (angle >= 180.0f) angle -= 180.0f;
	if (angle <= -180.0f) angle += 180.0f;

	dObject->setRotation(angle);
}

void Racket::update() {
	getElapsedTime();
	getSimTime();
	
	if (firstFrame) {
		firstFrame = false;
	} else {
		velocityVector = quickVelocityVector / (float)Game::getSimPerFrame();
		quickVelocityVector = { 0, 0 };
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

void Racket::simulation() {
	oldRealPos = realPos;
	realPos = Physics::swapY(Physics::calcRealVector(windowObj.mapPixelToCoords(sf::Mouse::getPosition(windowObj))));
	quickVelocityVector += calcVelocityVector(oldRealPos, realPos, simTime);
}

Racket::~Racket() {
	Collision::getRacketCollisionVector()._delete(this);
}

void Racket::test() {
	
}
