#pragma once

#include "UpdateObject.h"
#include "PhysicalObject.h"
#include "Gameplay.h"

class Game {
private:

	static sf::RenderWindow windowObj;
	static sf::Clock clock;
	static sf::Clock frameClock;
	static std::vector<PhysicalObject*> collisionVector;
	static std::vector<UpdateObject*> updateVector;
	static std::vector<sf::Drawable*> drawVector;
	static Gameplay *gameplay;

	sf::View view;
	sf::Event _event;

public:

	Game(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);

	const static sf::RenderWindow &getWindowObj();
	static float getTime();
	static const std::vector<PhysicalObject*>* getCollisionVector();
	static void addCollisionObjectToCollisionVector(PhysicalObject* obj);
	static void deleteCollisionObjectFromCollisionVector(PhysicalObject* obj);
	static void addUpdateObjectToUpdateVector(UpdateObject* obj);
	static void deleteUpdateObjectFromUpdateVector(UpdateObject* obj);
	static void addDrawableObjectToDrawVector(sf::Drawable* obj);
	static void deleteDrawableObjectFromDrawVector(sf::Drawable* obj);
	static void startGameplay();
	void manageWindowEvents();
	void updateObjects();
	void drawObjects();
	void run();
	void tests();

	~Game();
};

