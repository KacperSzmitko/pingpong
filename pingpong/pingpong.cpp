#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, false, "Ping-Pong");

	Physics *physics = new Physics(1, 1, 1, { 1, 1 });
	
	Racket rac(10, 100, 150, 150, 10, physics);
	Ball bal(20, 0, 600, 10, physics);
	

	game.run();

	return 0;
}