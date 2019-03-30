#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, false, "Ping-Pong");

	Physics *physics = new Physics(0.0431,1, 10, {1,1});
	
	Ball ball(5,0,1000,0.5,physics,2);
	

	game.run();

	return 0;
}