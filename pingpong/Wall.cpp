#include "pch.h"
#include "Wall.h"
#include "Game.h"

Wall::Wall(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY) :
	Rect(pixelSizeX, pixelSizeY, angle, material, pixelPosX, pixelPosY) {
	Collision::getWallCollisionVector()._add(this);
};


Wall::~Wall() {
	Collision::getWallCollisionVector()._delete(this);
}
