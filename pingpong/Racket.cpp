#include "pch.h"
#include "Racket.h"
#include "Physics.h"

Racket::Racket(float sizeX, float sizeY, float posX, float posY, float mass,Physics* physics) : 
UpdateObject(),
DrawnObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY))),
PhysicalObject(mass,physics){
	
	this->dObject->setPosition(posX, posY);
}

void Racket::update() {

	dObject->move(sf::Vector2f(1, 1));
	
}

Racket::~Racket() {}
