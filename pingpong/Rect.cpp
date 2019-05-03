#include "pch.h"
#include "Rect.h"
#include "Game.h"
#include "Physics.h"

Rect::Rect(float pixelSizeX, float pixelSizeY, float angle, float friction, float elasticity, float pixelPosX, float pixelPosY) :
	DrawnObject(new sf::RectangleShape({pixelSizeX, pixelSizeY})),
	PhysicalObject(friction, elasticity, pixelPosX, pixelPosY) {
	this->realLength = Physics::calcRealValue(pixelSizeY);
	this->realWidth = Physics::calcRealValue(pixelSizeX);
	this->dObject->setOrigin({ pixelSizeX / 2.0f, pixelSizeY / 2.0f });
	this->angle = angle;
	this->dObject->setRotation(angle);
	this->dObject->setPosition(Physics::swapY({ pixelPosX, pixelPosY }));

	Game::gameplay->getRectCollisionVector()._add(this);
}



Rect::~Rect() {
	Game::gameplay->getRectCollisionVector()._delete(this);
}
