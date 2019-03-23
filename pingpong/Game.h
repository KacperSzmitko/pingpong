#pragma once

class Game {
private:

	sf::RenderWindow* windowObj;
	static std::vector<sf::Drawable*> drawVector;

public:

	Game();

	void createWindow(int xSize, int ySize, int refreshRate, bool verticalSync, std::string windowTitle);
	static void addDrawableObjectToDrawVector(sf::Drawable* obj);
	static void deleteDrawableObjectFromDrawVector(sf::Drawable* obj);
	void manageWindowEvents();
	void drawDrawableObjects();
	void display();
	void run();

	~Game();
};

