#include "pch.h"
#include "Game.h"
#include "Racket.h"
#include "Ball.h"

int main() {

	Game game(1280, 720, 60, true, "Ping-Pong");
	Physics physics(0.0068, 1, sf::Vector2f(1, 1), 10);
	std::shared_ptr<Physics> physic = std::make_shared<Physics>(physic);

	Ball bal(0, 600, 10, physics, 20);
	

	game.run();

	return 0;
}