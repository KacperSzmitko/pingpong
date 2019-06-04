#pragma once

#include "UpdateObject.h"

class DisplayWind : public UpdateObject {
private:
	sf::Text windText;
	sf::Text windValue;
	std::stringstream valueStream;

public:
	DisplayWind();
	void update();
	~DisplayWind();
};

