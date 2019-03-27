#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, true, "Ping-Pong");
	Physics *physics = new Physics(0.0431, 0, sf::Vector2f(0, 0));
	Ball bal(0, 600, 10, physics, 20);
	

	game.run();

	return 0;
}