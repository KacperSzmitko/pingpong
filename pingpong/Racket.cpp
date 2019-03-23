#include "pch.h"
#include "Racket.h"

Racket::Racket(float sizeX, float sizeY, float posX, float posY) : DrawnObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY))) {
	
	this->dObject->setPosition(posX, posY);
}

void Racket::update() {

}

Racket::~Racket() {}
