#include "pch.h"
#include "Game.h"

sf::RenderWindow Game::windowObj;
ObjectsVector<PhysicalObject*> Game::collisionVector;
ObjectsVector<UpdateObject*> Game::updateVector;
ObjectsVector<sf::Drawable*> Game::drawVector;
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

ObjectsVector<PhysicalObject*>* Game::getCollisionVector() {
	return &collisionVector;
}

ObjectsVector<UpdateObject*>* Game::getUpdateVector() {
	return &updateVector;
}

ObjectsVector<sf::Drawable*>* Game::getDrawVector() {
	return &drawVector;
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
	for (UpdateObject* obj : updateVector.get()) {
		obj->update();
	}
}

void Game::drawObjects() {
	for (sf::Drawable* o : drawVector.get()) {
		windowObj.draw(*o);
	}
}

void Game::run() {
	while (windowObj.isOpen()) {
		windowObj.clear();
		manageWindowEvents();
		updateObjects();
		if (gameplay != nullptr) gameplay->checkCollisions();
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
	delete gameplay;
}
