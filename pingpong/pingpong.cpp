#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, false, "Ping-Pong");

	Physics *physics = new Physics(1, 1, 1, { 1, 1 });
	
	Racket rac(physics, 100.0f, 100.0f);
	

	game.run();

	return 0;
}