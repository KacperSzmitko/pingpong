#include "pch.h"
#include "Game.h"

sf::RenderWindow Game::windowObj;
ObjectsVector<UpdateObject*> Game::updateVector;
ObjectsVector<sf::Drawable*> Game::drawVector;
sf::Clock Game::clock;
sf::Clock Game::clock1;
sf::Clock Game::frameClock;
Gameplay *Game::gameplay;
const int Game::simPerFrame = 15;
float Game::lastTime = 0.0f;
float Game::timeForBall = 0.0f;
float Game::elapsedTime = Game::getTime();
float Game::simTime = Game::elapsedTime / (float)Game::simPerFrame;

Game::Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle) : 
	view({ (float)xSize / 2.0f, (float)ySize / -2.0f }, { (float)xSize, (float)ySize }) {

	this->windowObj.create(sf::VideoMode(xSize, ySize), windowTitle, sf::Style::Close);
	this->windowObj.setFramerateLimit(refreshRate);
	this->windowObj.setVerticalSyncEnabled(verticalSync);
	this->windowObj.setMouseCursorVisible(false);
	this->windowObj.setView(view);
	this->licz = 0;
	
}

sf::RenderWindow &Game::getWindowObj() {
	return windowObj;
}

float Game::getTime() {
	return clock.getElapsedTime().asSeconds();
}

int Game::getSimPerFrame() {
	return simPerFrame;
}

float Game::getElapsedTime() {
	return elapsedTime;
}

float Game::getTimeForBall()
{
	return timeForBall;
}

void Game::calcTimes() {
	elapsedTime = Game::getTime() - lastTime;
	lastTime = Game::getTime();
	simTime = elapsedTime / (float)simPerFrame;
}

float Game::getSimTime() {
	return simTime;
}

ObjectsVector<UpdateObject*> &Game::getUpdateVector() {
	return updateVector;
}

ObjectsVector<sf::Drawable*> &Game::getDrawVector() {
	return drawVector;
}

void Game::startGameplay() {
	gameplay = new Gameplay;
}



void Game::manageWindowEvents() {
	
	while (windowObj.pollEvent(_event)) {
		if (_event.type == sf::Event::Closed) {
			windowObj.close();
		}
		if (_event.type == sf::Event::KeyPressed && licz==0)
		{
			clock1.restart();
			licz = 1;
			clock1.restart();
			break;
		}
		else timeForBall = 0;
		if (_event.type == sf::Event::KeyReleased)
		{
			timeForBall = clock1.getElapsedTime().asSeconds();
			clock1.restart();
			licz = 0;
			break;
		}
		else timeForBall = 0;
		
	}
	
}

void Game::updateObjects() {
	updateVector.forEach([](UpdateObject* &obj) {
		obj->update();
	});
}

void Game::drawObjects() {
	drawVector.forEach([](sf::Drawable* &obj) {
		windowObj.draw(*obj);
	});
}

void Game::run() {
	while (windowObj.isOpen()) {
		windowObj.clear();
		manageWindowEvents();
		calcTimes();
		updateObjects();
		for (int i = 0; i < simPerFrame; i++) gameplay->simulate();
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
