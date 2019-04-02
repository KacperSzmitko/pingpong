#pragma once
#include "Ball.h"
#include "Racket.h"
#include "Table.h"

class Colision
{
protected:
	sf::CircleShape &pilka;
	sf::RectangleShape &obj;

public:
	Colision(Ball &ball);
	Colision(Table &tab);
	Colision(Racket &racket);

	bool CheckColision(Colision &OtherObj);

	~Colision();
};

