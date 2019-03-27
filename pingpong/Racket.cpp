#include "pch.h"
#include "Racket.h"

Racket::Racket(float sizeX, float sizeY, int posX, int posY, float mass, Physics *physics) : 
	UpdateObject(), 
	DrawnObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY))), 
	PhysicalObject(mass, sf::Vector2f(0, 0), physics),
	lastPixelPos(posX, posY), 
	newPixelPos(posX, posY) {

	this->dObject->setPosition(intVectorToFloatVector(newPixelPos));
}

sf::Vector2f Racket::intVectorToFloatVector(sf::Vector2i &vec) {
	return sf::Vector2f((float)vec.x, (float)vec.y);
}

void Racket::update() {
	calcElapsedTime();
	newPixelPos = sf::Mouse::getPosition();
	realSpeedVector = calcRealSpeedVector(intVectorToFloatVector(lastPixelPos), intVectorToFloatVector(newPixelPos), elapsedTime);
	realSpeed = calcRealSpeedFromRealSpeedVector(realSpeedVector);
	dObject->setPosition(intVectorToFloatVector(newPixelPos));
	lastPixelPos = newPixelPos;

	//Testy
	std::cout << realSpeed << " m/s" << std::endl;
}

Racket::~Racket() {}
