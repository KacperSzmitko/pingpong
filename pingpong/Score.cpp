#include "pch.h"
#include "Score.h"

#include "Game.h"

Score::Score() {
	player1ScoreValue.setPosition(600.0f, -700.0f);
	middleThing.setPosition(640.0f, -700.0f);
	player2ScoreValue.setPosition(680.0f, -700.0f);
	player1ScoreValue.setString(std::to_string(Gameplay::player1Score));
	player2ScoreValue.setString(std::to_string(Gameplay::player2Score));
	player1ScoreValue.setFont(Game::font);
	player2ScoreValue.setFont(Game::font);
	player1ScoreValue.setCharacterSize(25);
	player2ScoreValue.setCharacterSize(25);
	middleThing.setFont(Game::font);
	middleThing.setString(":");
	middleThing.setOrigin(middleThing.getLocalBounds().width / 2.0f, middleThing.getLocalBounds().height / 2.0f);
	player2ScoreValue.setOrigin(player2ScoreValue.getLocalBounds().width, 0.0f);
	Game::getDrawVector()._add(&this->player1ScoreValue);
	Game::getDrawVector()._add(&this->player2ScoreValue);
	Game::getDrawVector()._add(&this->middleThing);
	
}

void Score::update() {
	player1ScoreValue.setString(std::to_string(Gameplay::player1Score));
	player2ScoreValue.setString(std::to_string(Gameplay::player2Score));
	player2ScoreValue.setOrigin(player2ScoreValue.getLocalBounds().width, 0.0f);
}


Score::~Score() {
	Game::getDrawVector()._delete(&this->player1ScoreValue);
	Game::getDrawVector()._delete(&this->player2ScoreValue);
	Game::getDrawVector()._delete(&this->middleThing);
}
