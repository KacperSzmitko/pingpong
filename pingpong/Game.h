#pragma once

class Game {
private:

	sf::RenderWindow* windowObj;
	sf::Event* _event;
	static sf::Clock clock;
	static sf::Clock frameClock;
	static std::vector<sf::Drawable*> drawVector;

public:

	Game();

	void createWindow(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);
	static void addDrawableObjectToDrawVector(sf::Drawable* obj);
	static void deleteDrawableObjectFromDrawVector(sf::Drawable* obj);
	void manageWindowEvents();
	void updateObjects();
	void drawDrawableObjects();
	void run();
	void test();

	~Game();
};

