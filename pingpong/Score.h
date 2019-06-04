#pragma once

#include "UpdateObject.h"

class Score : public UpdateObject {
private:
	sf::Text player1ScoreValue;
	sf::Text player2ScoreValue;
	sf::Text middleThing;
public:
	Score();
	void update();
	~Score();
};

