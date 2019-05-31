#include "pch.h"
#include "Racket.h"
#include "Game.h"

Racket::Racket(float posX, float posY) : 
	MovingObject(RACKET_DEFAULT_MASS), 
	Rect(RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y, 0.0f, Physics::Materials::racket, posX, posY),
	windowObj(Game::getWindowObj()) {
	Collision::getRacketCollisionVector()._add(this);
}

void Racket::rotation() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) angle -= 247.5f * elapsedTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) angle += 247.5f * elapsedTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) angle = 0.0f;
	
	if (angle >= 180.0f) angle -= 180.0f;
	if (angle <= -180.0f) angle += 180.0f;

	dObject->setRotation(angle);
}

void Racket::update() {
	getSimTime();
	getElapsedTime();

	velocityVector = quickVelocityVector / (float)Game::getSimPerFrame();
	quickVelocityVector = { 0.0f, 0.0f };

	velocity = calcVelocityFromVelocityVector(velocityVector);
	if (velocity != 0.0f) {
		unitVector = calcUnitVector(velocityVector, velocity);
	}
	kineticEnergy = calcKineticEnergy(mass, velocity);
	
	rotation();
}

void Racket::simulation() {
	
	if ((realPos.x - oldRealPos.x) > (RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.x = oldRealPos.x + (RACKET_DEFAULT_MAX_VELOCITY * simTime);
	if ((realPos.x - oldRealPos.x) < (-RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.x = oldRealPos.x - (RACKET_DEFAULT_MAX_VELOCITY * simTime);
	if ((realPos.y - oldRealPos.y) > (RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.y = oldRealPos.y + (RACKET_DEFAULT_MAX_VELOCITY * simTime);
	if ((realPos.y - oldRealPos.y) < (-RACKET_DEFAULT_MAX_VELOCITY * simTime)) realPos.y = oldRealPos.y - (RACKET_DEFAULT_MAX_VELOCITY * simTime);
	quickVelocityVector += calcVelocityVector(oldRealPos, realPos, simTime);
	dObject->setPosition(Physics::swapY(Physics::calcPixelVector(realPos)));
	oldRealPos = realPos;
	
}

Racket::~Racket() {
	Collision::getRacketCollisionVector()._delete(this);
}

void Racket::test() {
	
}
