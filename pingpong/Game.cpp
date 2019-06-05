#include "pch.h"
#include "Game.h"

sf::RenderWindow Game::windowObj;
sf::Event Game::_event;
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
sf::Font Game::font;
MainMenu *Game::mainMenu;
ModeSelectMenu *Game::modeSelectMenu;
PhysicsSettingsMenu *Game::physicsSettingsMenu;
bool Game::mousePress = false;

Game::Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle) : 
	view({ (float)xSize / 2.0f, (float)ySize / -2.0f }, { (float)xSize, (float)ySize }) {

	this->windowObj.create(sf::VideoMode(xSize, ySize), windowTitle, sf::Style::Close);
	this->windowObj.setFramerateLimit(refreshRate);
	this->windowObj.setVerticalSyncEnabled(verticalSync);
	if (!this->BackgroundTexture.loadFromFile("b.png"))
	{
		std::cout << "er";
	}
	this->background.setTexture(BackgroundTexture);
	this->background.setPosition(0, 0);
	this->windowObj.setView(view);
	this->licz = 0;
	font.loadFromFile("opensans.ttf");
	this->rectangle.setTexture(&BackgroundTexture);
}

sf::RenderWindow &Game::getWindowObj() {
	return windowObj;
}

sf::Event &Game::getEvent() {
	return _event;
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

void Game::startMainMenu() {
	mainMenu = new MainMenu;
}

void Game::startModeSelectMenu() {
	modeSelectMenu = new ModeSelectMenu;
}

void Game::startPhysicsSettingsMenu() {
	physicsSettingsMenu = new PhysicsSettingsMenu;
}

void Game::startGameplay(int mode) {
	gameplay = new Gameplay(mode);
}



void Game::manageEvents() {
	
	mousePress = false;
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
		if (_event.type == sf::Event::MouseButtonPressed) {
			mousePress = true;
		}
		windowObj.draw(background);
		
		
		
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
		windowObj.clear(sf::Color(51, 119, 255));
		manageEvents();
		calcTimes();
		updateObjects();
		for (int i = 0; i < simPerFrame; i++) gameplay->simulate();
		drawObjects();
		windowObj.draw(background);
		windowObj.display();
		tests();
		frameClock.restart();


	}
}

void Game::tests() {
	if (gameplay != nullptr) gameplay->objectsTest();
	
}

Game::~Game() {
	windowObj.close();
}
