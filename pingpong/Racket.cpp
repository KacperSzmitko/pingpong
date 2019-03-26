#include "pch.h"
#include "Racket.h"

Racket::Racket(float sizeX, float sizeY, float posX, float posY, float mass, std::shared_ptr<Physics> physics) : UpdateObject(), DrawnObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY)), posX, posY), PhysicalObject(mass, physics) {
	this->dObject->setPosition(pos);
}

void Racket::update() {

	//Dla testów
	CalcElapsedTime();
	pos.x += 50.0f * elapsedTime.asSeconds();
	pos.y += 50.0f * elapsedTime.asSeconds();
	dObject->setPosition(pos);
	
}

Racket::~Racket() {}
