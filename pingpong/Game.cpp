#include "pch.h"
#include "Game.h"

std::vector<sf::Drawable*> Game::drawVector;

Game::Game() {
}

void Game::createWindow(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle) {
	this->windowObj = new sf::RenderWindow(sf::VideoMode(xSize, ySize), windowTitle, sf::Style::Close);
	this->windowObj->setFramerateLimit(refreshRate);
	this->windowObj->setVerticalSyncEnabled(verticalSync);
}

void Game::addDrawableObjectToDrawVector(sf::Drawable* obj) {
	drawVector.push_back(obj);
}

void Game::deleteDrawableObjectFromDrawVector(sf::Drawable* obj) {
	for (std::vector<sf::Drawable*>::iterator i = drawVector.begin(); i != drawVector.end(); i++) {
		if (*i == obj) {
			drawVector.erase(i);
			break;
		}
	}
}

void Game::manageWindowEvents() {
	sf::Event _event;
	while (windowObj->pollEvent(_event)) {
		if (_event.type == sf::Event::Closed) {
			windowObj->close();
		}
	}
}

void Game::drawDrawableObjects() {
	for (sf::Drawable* o : drawVector) {
		windowObj->draw(*o);
	}
}

void Game::display() {
	windowObj->display();
}

void Game::run() {
	while (windowObj->isOpen()) {
		manageWindowEvents();
		drawDrawableObjects();
		display();
	}
}

Game::~Game() {
	delete windowObj;
}
