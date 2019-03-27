#include "pch.h"
#include "Racket.h"

Racket::Racket(float sizeX, float sizeY, int posX, int posY, float mass, Physics * physics) : 
	UpdateObject(), 
	DrawnObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY))), 
	PhysicalObject(mass, sf::Vector2f(0, 0), physics),
	lastPos(posX, posY), 
	newPos(posX, posY) {

	this->dObject->setPosition(intVectorToFloatVector(newPos));
}

sf::Vector2f Racket::intVectorToFloatVector(sf::Vector2i &vec) {
	return sf::Vector2f((float)vec.x, (float)vec.y);
}

void Racket::update() {
	calcElapsedTime();
	newPos = sf::Mouse::getPosition();
	speedVector = calcSpeedVector(intVectorToFloatVector(lastPos), intVectorToFloatVector(newPos), elapsedTime);
	speed = calcSpeedFromSpeedVector(speedVector);
	dObject->setPosition(intVectorToFloatVector(newPos));
	lastPos = newPos;

	//Testy
	std::cout << speed << " m/s" << std::endl; 
}

Racket::~Racket() {}
