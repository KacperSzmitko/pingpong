#include "pch.h"
#include "Game.h"

std::vector<UpdateObject*> Game::updateVector;
std::vector<sf::Drawable*> Game::drawVector;
sf::Clock Game::clock;
sf::Clock Game::frameClock;

Game::Game() {

}

void Game::createWindow(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle) {
	this->windowObj = std::make_unique<sf::RenderWindow>(sf::VideoMode(xSize, ySize), windowTitle, sf::Style::Close);
	this->windowObj->setFramerateLimit(refreshRate);
	this->windowObj->setVerticalSyncEnabled(verticalSync);
	this->_event = std::make_unique<sf::Event>();
}

void Game::addUpdateObjectToUpdateVector(UpdateObject* obj) {
	updateVector.push_back(obj);
}

void Game::deleteUpdateObjectFromUpdateVector(UpdateObject* obj) {
	for (std::vector<UpdateObject*>::iterator i = updateVector.begin(); i != updateVector.end(); i++) {
		if (*i == obj) {
			updateVector.erase(i);
			break;
		}
	}
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
	for (UpdateObject* obj : updateVector) {
		obj->update();
	}
}

void Game::drawObjects() {
	for (sf::Drawable* o : drawVector) {
		windowObj->draw(*o);
	}
}

void Game::run() {
	while (windowObj->isOpen()) {
		windowObj->clear();
		manageWindowEvents();
		updateObjects();
		drawObjects();
		windowObj->display();



		test(); //Dla testowania
		
		frameClock.restart();
	}
}

void Game::test() {
	std::cout << 1.0f / frameClock.getElapsedTime().asSeconds() << " | " << clock.getElapsedTime().asMilliseconds() << std::endl;
}

Game::~Game() {

}
