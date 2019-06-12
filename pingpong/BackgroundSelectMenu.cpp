#include "pch.h"
#include "BackgroundSelectMenu.h"
#include "Game.h"

BackgroundSelectMenu::BackgroundSelectMenu(int mode) {
	this->_1 = new MenuBar(320, 180, 80, 200, "", [this, mode]() {
		Game::startGameplay(mode, 1);
		delete this;
	});
	this->_2 = new MenuBar(320, 180, 480, 200, "", [this, mode]() {
		Game::startGameplay(mode, 2);
		delete this;
	});
	this->_3 = new MenuBar(320, 180, 880, 200, "", [this, mode]() {
		Game::startGameplay(mode, 3);
		delete this;
	});

	this->wybierzText.setString(L"Wybierz t³o");
	this->wybierzText.setFont(Game::font);
	this->wybierzText.setCharacterSize(30);
	this->wybierzText.setOrigin(this->wybierzText.getLocalBounds().left + this->wybierzText.getLocalBounds().width / 2.0f, this->wybierzText.getLocalBounds().top + this->wybierzText.getLocalBounds().height / 2.0f);
	this->wybierzText.setPosition(640.0f, -620.0f);
	this->wybierzText.setFillColor(sf::Color::White);

	this->_1->setBackground(Game::sb1);
	this->_2->setBackground(Game::sb2);
	this->_3->setBackground(Game::sb3);

	Game::getDrawVector()._add(&this->wybierzText);
}


BackgroundSelectMenu::~BackgroundSelectMenu() {
	delete _1;
	delete _2;
	delete _3;
	Game::getDrawVector()._delete(&this->wybierzText);
}
