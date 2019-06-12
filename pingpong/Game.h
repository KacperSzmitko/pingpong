#pragma once

#include "ObjectsVector.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "ModeSelectMenu.h"
#include "BackgroundSelectMenu.h"
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
	static BackgroundSelectMenu *backgroundSelectMenu;
	static PhysicsSettingsMenu *physicsSettingsMenu;
	
	static const int simPerFrame;
	static float lastTime;
	static float elapsedTime;
	static float simTime;

	sf::View view;
	static sf::Event _event;

	static sf::RectangleShape background;
	static sf::Texture backgroundTexture1;
	static sf::Texture backgroundTexture2;
	static sf::Texture backgroundTexture3;
	

	static void calcTimes();

public:
	static bool mousePress;
	static float timeForBall;
	static bool reset_ball;
	static sf::Font font;
	static sf::Texture sb1, sb2, sb3;

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
	static void startBackgroundSelectMenu(int mode);
	static void startPhysicsSettingsMenu();
	static void startGameplay(int mode, int backgroundNumber);
	void manageEvents();
	void updateObjects();
	void drawObjects();
	void run();
	void tests();

	~Game();
};

