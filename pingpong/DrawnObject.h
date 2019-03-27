#pragma once
#include "Game.h"

//Klasy szablonowe musz� by� w ca�o�ci zdefnionowan� w nag��wku, dlatego nie ma DrawnObject.cpp
//Jako typename mo�na u�y�: sf::CircleShape, sf::ConvexShape, sf::RectangleShape, sf::Shape, sf::Sprite, sf::Text, sf::VertexArray, sf::VertexBuffer
template <typename T> class DrawnObject { 
protected:
	T* dObject;
	sf::Vector2f pos;

public:
	DrawnObject(T* obj, float posX, float posY) : dObject(obj), pos(posX, posY) {
		sendDrawObject();
	}

	void sendDrawObject() {
		Game::addDrawableObjectToDrawVector(dObject);
	}
	void deleteDrawObject() {
		Game::deleteDrawableObjectFromDrawVector(dObject);
	}

	virtual ~DrawnObject() {
		deleteDrawObject();
		delete dObject;
	}
};

