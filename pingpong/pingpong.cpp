#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, true, "Ping-Pong");
	Physics *physics= new Physics(0.0068, 1, sf::Vector2f(1, 1), 10);
	
	Racket rac(10, 100, 150, 150, 10, physics);
	Ball bal(0, 600, 10, physics, 20);
	

	game.run();

	return 0;
}