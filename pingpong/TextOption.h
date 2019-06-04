#pragma once

#include "UpdateObject.h"
#include "DrawnObject.h"

class TextOption : public UpdateObject {
private:
	sf::Text optionName;
	sf::Text optionValue;
	std::stringstream valueStream;
	
	
	float *physicsValueToChange;
	float change;
	float max;
	bool canBeNegative;

	class Arrow : public DrawnObject<sf::RectangleShape> {

		friend class TextOption;

	private:
		sf::Texture arrowTexture;

	public:
		Arrow(float posX, float posY, bool up);
	};

	Arrow *upArrow;
	Arrow *downArrow;

public:
	TextOption(float xPos, float yPos, sf::String optionName, float *physicsValueToChange, float change, float max, bool canBeNegative);
	void update();
	~TextOption();
};

