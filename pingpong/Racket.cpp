#include "pch.h"
#include "Racket.h"

Racket::Racket(float sizeX, float sizeY, int posX, int posY, float mass, Physics * physics) : UpdateObject(), DrawnObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY))), PhysicalObject(mass, physics), lastPos(posX, posY), newPos(posX, posY) {
	this->dObject->setPosition(intVectorToFloatVector(newPos));
}

sf::Vector2f Racket::intVectorToFloatVector(const sf::Vector2i &vec) {
	return sf::Vector2f((float)vec.x, (float)vec.y);
}

void Racket::update() {
	newPos = sf::Mouse::getPosition();
	dObject->setPosition(intVectorToFloatVector(newPos));
	lastPos = newPos;
}

Racket::~Racket() {}
