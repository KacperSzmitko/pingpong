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
}


BackgroundSelectMenu::~BackgroundSelectMenu() {
	delete _1;
	delete _2;
	delete _3;
}
