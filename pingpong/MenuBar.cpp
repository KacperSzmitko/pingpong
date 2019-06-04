#include "pch.h"
#include "MenuBar.h"
#include "Game.h"
#include "Physics.h"

MenuBar::MenuBar(float xSize, float ySize, float xPos, float yPos, sf::String text, std::function<void()> functionOnClick) :
	DrawnObject(new sf::RectangleShape({ xSize, ySize })), backgroundColor(153, 204, 255) {
	this->dObject->setPosition(Physics::swapY({ xPos, 720.0f - yPos }));
	this->dObject->setFillColor(backgroundColor);
	this->text.setFont(Game::font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color(0, 38, 77));
	this->text.setCharacterSize(30);
	this->text.setOrigin(this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2.0f, this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2.0f);
	this->text.setPosition(Physics::swapY({ xPos + (xSize / 2.0f), 720.0f - yPos - (ySize / 2.0f) }));
	this->functionOnClick = functionOnClick;
	Game::getDrawVector()._add(&this->text);
}

void MenuBar::update() {	
	if (Game::mousePress) {
		sf::Vector2f mousePos = { (float)sf::Mouse::getPosition(Game::getWindowObj()).x, 720.0f - (float)sf::Mouse::getPosition(Game::getWindowObj()).y };
		sf::Vector2f barPos = Physics::swapY(dObject->getPosition());
		sf::Vector2f barSize = { dObject->getLocalBounds().width, dObject->getLocalBounds().height };
		if ((mousePos.x >= barPos.x && mousePos.x <= barPos.x + barSize.x) && (mousePos.y <= barPos.y && mousePos.y >= barPos.y - barSize.y)) {
			functionOnClick();
		}
	}
}


MenuBar::~MenuBar() {

	Game::getDrawVector()._delete(&this->text);
}
