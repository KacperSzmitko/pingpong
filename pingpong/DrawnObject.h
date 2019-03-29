#pragma once

#include "Game.h"

//Klasy szablonowe musz� by� w ca�o�ci zdefnionowan� w nag��wku, dlatego nie ma DrawnObject.cpp
//Jako typename mo�na u�y�: sf::CircleShape, sf::ConvexShape, sf::RectangleShape, sf::Shape, sf::Sprite, sf::Text, sf::VertexArray, sf::VertexBuffer
template <typename T> class DrawnObject { 
protected:
	T* dObject;

public:
	DrawnObject(T* obj) : dObject(obj) {
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

