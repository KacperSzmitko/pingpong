#include "pch.h"
#include "Table.h"
#include "Game.h"


Table::Table(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY, int player):
	Rect(pixelSizeX, pixelSizeY, angle,  material, pixelPosX, pixelPosY)
{
	this->player = player;
	Collision::getTableCollisionVector()._add(this);
	
}

Table::~Table()
{
	Collision::getTableCollisionVector()._delete(this);
}