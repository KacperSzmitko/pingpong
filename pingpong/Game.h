#pragma once
#include "UpdateObject.h"

class Game {
private:

	static sf::RenderWindow windowObj;
	static sf::Clock clock;
	static sf::Clock frameClock;
	static std::vector<UpdateObject*> updateVector;
	static std::vector<sf::Drawable*> drawVector;

	sf::Event _event;

public:

	Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);

	const static sf::RenderWindow& getWindowObj();
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

