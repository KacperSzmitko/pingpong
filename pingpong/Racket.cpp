#include "pch.h"
#include "Racket.h"
#include "Game.h"

Racket::Racket(Physics *physics, float posX, float posY) :
	UpdateObject(),
	DrawnObject(new sf::RectangleShape({ RACKET_DEFAULT_PIXEL_SIZE_X, RACKET_DEFAULT_PIXEL_SIZE_Y })),
	PhysicalObject(physics, mass, RACKET_FRICTION, RACKET_ELASTICITY, posX, posY), windowObj(Game::getWindowObj()) {

	this->dObject->setOrigin({ RACKET_DEFAULT_PIXEL_SIZE_X / 2.0f, RACKET_DEFAULT_PIXEL_SIZE_Y / 2.0f });
	this->firstFrame = true;
}

void Racket::setPixelSize(const float &sizeX, const float &sizeY) {
	dObject->setSize({ sizeX, sizeY });
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

	lastRealPos = newRealPos;
	newRealPos = swapY(calcRealVector(windowObj.mapPixelToCoords(sf::Mouse::getPosition(windowObj))));

	if (firstFrame) {
		firstFrame = false;
	} else {
		velocityVector = calcVelocityVector(lastRealPos, newRealPos, elapsedTime);
		velocity = calcVelocityFromVelocityVector(velocityVector);
		if (velocity != 0.0f) {
			unitVector = calcUnitVector(velocityVector, velocity);
		}
		if (velocity > RACKET_DEFAULT_MAX_VELOCITY) {
			velocity = RACKET_DEFAULT_MAX_VELOCITY;
		}
		kineticEnergy = calcKineticEnergy(mass, velocity);
	}

	dObject->setPosition(swapY(calcPixelVector(newRealPos)));
	rotation();
	
	


	
}

Racket::~Racket() {

}

void Racket::test() {
	std::cout << angle << std::endl;
}
