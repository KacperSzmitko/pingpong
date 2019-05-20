#pragma once
#include "Rect.h"

class Wall : public Rect {

	friend class Collision;

private:


public:
	Wall(float pixelSizeX, float pixelSizeY, float angle, Physics::Material material, float pixelPosX, float pixelPosY);
	~Wall();
};

