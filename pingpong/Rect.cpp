#include "pch.h"
#include "Rect.h"
#include "Game.h"
#include "Physics.h"

Rect::Rect(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY) :
	DrawnObject(new sf::RectangleShape({pixelSizeX, pixelSizeY})),
	PhysicalObject (material, pixelPosX, pixelPosY) {
	this->realLength = Physics::calcRealValue(pixelSizeY);
	this->realWidth = Physics::calcRealValue(pixelSizeX);
	this->dObject->setOrigin({ pixelSizeX / 2.0f, pixelSizeY / 2.0f });
	this->angle = angle;
	this->dObject->setRotation(angle);
	this->dObject->setPosition(Physics::swapY({ pixelPosX, pixelPosY }));
	this->localSP = { pixelSizeX / 2.0f, 0.0f };
	this->localEP = { pixelSizeX / 2.0f, pixelSizeY };
	if (pixelSizeX <= pixelSizeY) this->pixelRadius = pixelSizeX / 2.0f;
	else this->pixelRadius = pixelSizeY / 2.0f;
}

Rect::~Rect() {
	
}
