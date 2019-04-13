#include "pch.h"
#include "Game.h"

sf::RenderWindow Game::windowObj;
std::vector<PhysicalObject*> Game::collisionVector;
std::vector<UpdateObject*> Game::updateVector;
std::vector<sf::Drawable*> Game::drawVector;
sf::Clock Game::clock;
sf::Clock Game::frameClock;
Gameplay *Game::gameplay;

Game::Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle) : 
	view({ (float)xSize / 2.0f, (float)ySize / -2.0f }, { (float)xSize, (float)ySize }) {

	this->windowObj.create(sf::VideoMode(xSize, ySize), windowTitle, sf::Style::Close);
	this->windowObj.setFramerateLimit(refreshRate);
	this->windowObj.setVerticalSyncEnabled(verticalSync);
	this->windowObj.setMouseCursorVisible(false);
	this->windowObj.setView(view);
}

const sf::RenderWindow &Game::getWindowObj() {
	return windowObj;
}

float Game::getTime() {
	return clock.getElapsedTime().asSeconds();
}

void Game::addCollisionObjectToCollisionVector(PhysicalObject* obj) {
	collisionVector.push_back(obj);
}

void Game::deleteCollisionObjectFromCollisionVector(PhysicalObject* obj) {
	for (std::vector<PhysicalObject*>::iterator i = collisionVector.begin(); i != collisionVector.end(); i++) {
		if (*i == obj) {
			collisionVector.erase(i);
			break;
		}
	}
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

void Game::startGameplay() {
	gameplay = new Gameplay;
}

void Game::manageWindowEvents() {
	while (windowObj.pollEvent(_event)) {
		if (_event.type == sf::Event::Closed) {
			windowObj.close();
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
		windowObj.draw(*o);
	}
}

void Game::run() {
	while (windowObj.isOpen()) {
		windowObj.clear();
		manageWindowEvents();
		updateObjects();
		drawObjects();
		windowObj.display();


		tests();
		frameClock.restart();


	}
}

void Game::tests() {
	gameplay->objectsTest();
}

Game::~Game() {
	windowObj.close();
	collisionVector.clear();
	updateVector.clear();
	drawVector.clear();
	delete gameplay;
}
