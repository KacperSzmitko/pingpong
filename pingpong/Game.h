#pragma once
#include "UpdateObject.h"

class Game {
private:

	sf::RenderWindow windowObj;
	sf::Event _event;
	static sf::Clock clock;
	static sf::Clock frameClock;
	static std::vector<UpdateObject*> updateVector;
	static std::vector<sf::Drawable*> drawVector;

public:

	Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);

	static float getTime();
	static void addUpdateObjectToUpdateVector(UpdateObject* obj);
	static void deleteUpdateObjectFromUpdateVector(UpdateObject* obj);
	static void addDrawableObjectToDrawVector(sf::Drawable* obj);
	static void deleteDrawableObjectFromDrawVector(sf::Drawable* obj);
	void manageWindowEvents();
	void updateObjects();
	void drawObjects();
	void run();
	void test();

	~Game();
};

