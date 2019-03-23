#include "pch.h"
#include "Game.h"

std::vector<sf::Drawable*> Game::drawVector;
sf::Clock Game::clock;
sf::Clock Game::frameClock;

Game::Game() {

}

void Game::createWindow(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle) {
	this->windowObj = new sf::RenderWindow(sf::VideoMode(xSize, ySize), windowTitle, sf::Style::Close);
	this->windowObj->setFramerateLimit(refreshRate);
	this->windowObj->setVerticalSyncEnabled(verticalSync);
	this->_event = new sf::Event;
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
	while (windowObj->pollEvent(*_event)) {
		if (_event->type == sf::Event::Closed) {
			windowObj->close();
		}
	}
}

void Game::updateObjects() {

}

void Game::drawDrawableObjects() {
	for (sf::Drawable* o : drawVector) {
		windowObj->draw(*o);
	}
}

void Game::run() {
	while (windowObj->isOpen()) {
		windowObj->clear();
		manageWindowEvents();
		updateObjects();
		drawDrawableObjects();
		windowObj->display();



		test(); //Dla testowania
		
		frameClock.restart();
	}
}

void Game::test() {
	std::cout << 1.0f / frameClock.getElapsedTime().asSeconds() << " | " << clock.getElapsedTime().asMilliseconds() << std::endl;
}

Game::~Game() {
	delete _event;
	delete windowObj;
}
