#pragma once

#include "DrawnObject.h"
#include "UpdateObject.h"

class MenuBar : public DrawnObject<sf::RectangleShape>, public UpdateObject {
private:
	sf::Text text;
	sf::Color backgroundColor;
	std::function<void()> functionOnClick;

public:
	MenuBar(float xSize, float ySize, float xPos, float yPos, sf::String text, std::function<void()> functionOnClick);
	void update();
	~MenuBar();
};

