#include "pch.h"
#include "Ball.h"
#include "CountingFunctions.h"

Ball::Ball(float r, float posX, float posY, float mass, Physics *physics, float Vp) :
	UpdateObject(),
	DrawnObject(new sf::CircleShape(r)),
	PhysicalObject(physics, mass, posX, posY, { 0.0f, 0.0f }),
	r(r), Vp(Vp)
{
	Vx_p = CalculateVxStart(Vp, 45 * PI / 180);
	Vy_p = CalculateVyStart(Vp, 45 * PI / 180);
	dObject->setPosition(posX, posY);
	
}
void Ball::update()
{
	calcElapsedTime();
	Vx = Vx_p;
	Vy = Vy_p;
	
	newRealPos = (sf::Vector2f((CalculateSx(Game::getTime(),Vx,mass,physics->resistance)),
		(Vy*Game::getTime())-(5*pow(Game::getTime(),2))));
	Vx_p = CalculateVx(Vx, Game::getTime(), mass, physics->resistance);
	
	std::cout << Vy_p << "\n";
	
	dObject->setPosition(calcPixelPos(newRealPos));
}




