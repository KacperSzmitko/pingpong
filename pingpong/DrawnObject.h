#pragma once

//Jako typename mo¿na u¿yæ: sf::CircleShape, sf::ConvexShape, sf::RectangleShape, sf::Shape, sf::Sprite, sf::Text, sf::VertexArray, sf::VertexBuffer
template <typename T> class DrawnObject { 
protected:
	T* dObject;

public:
	DrawnObject(T* obj);

	void sendDrawObject();
	void deleteDrawObject();

	virtual ~DrawnObject();
};

