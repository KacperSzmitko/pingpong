#pragma once

#include "ObjectsVector.h"
#include "Gameplay.h"

class Game {
private:

	static sf::RenderWindow windowObj;
	static sf::Clock clock;
	static sf::Clock frameClock;
	static ObjectsVector<PhysicalObject*> collisionVector;
	static ObjectsVector<UpdateObject*> updateVector;
	static ObjectsVector<sf::Drawable*> drawVector;
	static Gameplay *gameplay;

	sf::View view;
	sf::Event _event;

public:

	Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);

	const static sf::RenderWindow &getWindowObj();
	static float getTime();
	static ObjectsVector<PhysicalObject*>* getCollisionVector();
	static ObjectsVector<UpdateObject*>* getUpdateVector();
	static ObjectsVector<sf::Drawable*>* getDrawVector();
	static void startGameplay();
	void manageWindowEvents();
	void updateObjects();
	void drawObjects();
	void run();
	void tests();

	~Game();
};

