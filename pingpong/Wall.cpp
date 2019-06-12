#include "pch.h"
#include "Wall.h"
#include "Game.h"

Wall::Wall(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY,int which_wall) :
	Rect(pixelSizeX, pixelSizeY, angle, material, pixelPosX, pixelPosY) {
	Collision::getWallCollisionVector()._add(this);
	this->which_wall = which_wall;
	dObject->setFillColor(sf::Color::Transparent);
};


Wall::~Wall() {
	Collision::getWallCollisionVector()._delete(this);
}
