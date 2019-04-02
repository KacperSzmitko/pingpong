#pragma once
#include "DrawnObject.h"
#include "PhysicalObject.h"
#include "UpdateObject.h"

class Table: public DrawnObject<sf::RectangleShape>
{
private:
	float height=10, width=152;

public:
	Table(float height,float width);
	~Table();
};