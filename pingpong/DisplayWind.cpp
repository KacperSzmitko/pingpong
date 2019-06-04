#include "pch.h"
#include "DisplayWind.h"
#include "Game.h"


DisplayWind::DisplayWind() {
	windText.setFont(Game::font);
	windText.setString("Wiatr:");
	windText.setCharacterSize(25);
	windText.setPosition(20.0f, -700.0f);
	windValue.setFont(Game::font);
	windValue.setCharacterSize(25);
	valueStream << std::fixed << std::setprecision(3) << Physics::wind;
	windValue.setString(valueStream.str());
	windValue.setPosition(100.0f, -700.0f);

	Game::getDrawVector()._add(&this->windText);
	Game::getDrawVector()._add(&this->windValue);
}

void DisplayWind::update() {
	valueStream.str(std::string());
	valueStream << std::fixed << std::setprecision(3) << Physics::wind;
}


DisplayWind::~DisplayWind() {
	Game::getDrawVector()._delete(&this->windText);
	Game::getDrawVector()._delete(&this->windValue);
}
