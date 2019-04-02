#include "pch.h"
#include "Table.h"

Table::Table(float height, float width) : DrawnObject(new sf::RectangleShape({ height,width }))
{
	this->height = height;
	this->width = width;
	dObject->setFillColor(sf::Color::Blue);
	dObject->setPosition({ 360,-180 });
	
}
Table::~Table() {};