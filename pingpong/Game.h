#pragma once

#include "ObjectsVector.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "ModeSelectMenu.h"
#include "PhysicsSettingsMenu.h"

class Game {
private:
	float licz;
	static sf::RenderWindow windowObj;
	static sf::Clock clock,clock1;
	
	static sf::Clock frameClock;
	static ObjectsVector<UpdateObject*> updateVector;
	static ObjectsVector<sf::Drawable*> drawVector;

	static MainMenu *mainMenu;
	static ModeSelectMenu *modeSelectMenu;
	static PhysicsSettingsMenu *physicsSettingsMenu;
	
	static const int simPerFrame;
	static float lastTime;
	static float elapsedTime;
	static float simTime;

	sf::View view;
	static sf::Event _event;

	static void calcTimes();

public:
	static bool mousePress;
	static float timeForBall;
	static sf::Font font;

	Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);

	static Gameplay *gameplay;
	static sf::RenderWindow &getWindowObj();
	static sf::Event &getEvent();
	static float getTime();
	static int getSimPerFrame();
	static float getElapsedTime();
	static float getSimTime();
	static float getTimeForBall();
	static ObjectsVector<UpdateObject*>& getUpdateVector();
	static ObjectsVector<sf::Drawable*>& getDrawVector();
	static void startMainMenu();
	static void startModeSelectMenu();
	static void startPhysicsSettingsMenu();
	static void startGameplay(int mode);
	void manageEvents();
	void updateObjects();
	void drawObjects();
	void run();
	void tests();

	~Game();
};

