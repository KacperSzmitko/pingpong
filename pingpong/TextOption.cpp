#include "pch.h"
#include "TextOption.h"
#include "Game.h"

TextOption::Arrow::Arrow(float xPos, float yPos, bool up) : 
	DrawnObject(new sf::RectangleShape({ 20.0f, 20.0f })) {
	dObject->setPosition( xPos,  yPos );
	if (up) arrowTexture.loadFromFile("arrow_up.png");
	else arrowTexture.loadFromFile("arrow_down.png");
	dObject->setTexture(&arrowTexture);
}


TextOption::TextOption(float xPos, float yPos, sf::String optionName, float *physicsValueToChange, float change, float max, bool canBeNegative) {
	this->optionName.setString(optionName);
	this->optionName.setCharacterSize(20);
	this->optionName.setFont(Game::font);
	this->optionName.setPosition(Physics::swapY({ xPos, 720.0f - yPos }));
	this->physicsValueToChange = physicsValueToChange;
	this->optionValue.setCharacterSize(20);
	this->optionValue.setFont(Game::font);
	this->optionValue.setPosition(Physics::swapY({ xPos + this->optionName.getLocalBounds().width, 720.0f - yPos }));
	this->change = change;
	this->max = max;
	this->canBeNegative = canBeNegative;
	this->upArrow = new Arrow(this->optionName.getPosition().x, this->optionName.getPosition().y - 20.0f, true);
	this->downArrow = new Arrow(this->optionName.getPosition().x, this->optionName.getPosition().y + 26.0f, false);

	valueStream << std::fixed << std::setprecision(3) << *physicsValueToChange;
	this->optionValue.setString(valueStream.str());

	Game::getDrawVector()._add(&this->optionName);
	Game::getDrawVector()._add(&this->optionValue);
}

void TextOption::update() {
	if (Game::mousePress) {
		float newChange = change;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) newChange *= 10;
		sf::Vector2f mousePos = { (float)sf::Mouse::getPosition(Game::getWindowObj()).x, 720.0f - (float)sf::Mouse::getPosition(Game::getWindowObj()).y };
		sf::Vector2f upArrowPos = Physics::swapY(upArrow->dObject->getPosition());
		sf::Vector2f upArrowSize = { upArrow->dObject->getLocalBounds().width, upArrow->dObject->getLocalBounds().height };
		if ((mousePos.x >= upArrowPos.x && mousePos.x <= upArrowPos.x + upArrowSize.x) && (mousePos.y <= upArrowPos.y && mousePos.y >= upArrowPos.y - upArrowSize.y)) {
			
			if (*physicsValueToChange + newChange > max) *physicsValueToChange = max;
			else *physicsValueToChange += newChange;
	
		}
		sf::Vector2f downArrowPos = Physics::swapY(downArrow->dObject->getPosition());
		sf::Vector2f downArrowSize = { downArrow->dObject->getLocalBounds().width, downArrow->dObject->getLocalBounds().height };
		if ((mousePos.x >= downArrowPos.x && mousePos.x <= downArrowPos.x + downArrowSize.x) && (mousePos.y <= downArrowPos.y && mousePos.y >= downArrowPos.y - downArrowSize.y)) {

			if (!canBeNegative && *physicsValueToChange - newChange < 0.0f) *physicsValueToChange = 0.0f;
			else if (*physicsValueToChange - newChange < -max) *physicsValueToChange = -max;
			else *physicsValueToChange -= newChange;
		
		}
	}
	valueStream.str(std::string());
	valueStream << std::fixed << std::setprecision(3) << *physicsValueToChange;
	this->optionValue.setString(valueStream.str());
	return;
}


TextOption::~TextOption() {
	Game::getDrawVector()._delete(&this->optionName);
	Game::getDrawVector()._delete(&this->optionValue);
	delete upArrow;
	delete downArrow;
}
