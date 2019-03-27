#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, false, "Ping-Pong");

	Physics *physics = new Physics(0.0068f, 1, sf::Vector2f(1, 1), 10);
	
	Racket rac(10, 100, 150, 150, 10, physics);
	Ball bal(20, 0, 600, 10, physics);
	

	game.run();

	return 0;
}