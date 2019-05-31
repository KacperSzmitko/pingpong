#include "pch.h"
#include "Collision.h"
#include "Game.h"
#include <cmath>

ObjectsVector<Wall*> Collision::walls;
ObjectsVector<Racket*> Collision::rackets;
ObjectsVector<Ball*> Collision::balls;
ObjectsVector<Table*> Collision::tables;

ObjectsVector<Table*> &Collision::getTableCollisionVector()
{
	return tables;
}

ObjectsVector<Wall*> &Collision::getWallCollisionVector() {
	return walls;
}

ObjectsVector<Racket*> &Collision::getRacketCollisionVector() {
	return rackets;
}

ObjectsVector<Ball*> &Collision::getBallCollisionVector() {
	return balls;
}

void Collision::checkCollisions() {
	
	//Balls and walls
	balls.forEach([this](Ball *ball) {
		walls.forEach([this, ball](Wall *wall) {
			ballWallCol(ball, wall);
		});
	});

	//Balls and rackets
	balls.forEach([this](Ball *ball) {
		rackets.forEach([this, ball](Racket *racket) {
			ballRacketCol(ball, racket);
		});
	});

	//Balls and tables
	balls.forEach([this](Ball *ball) {
		tables.forEach([this, ball](Table *table) {
			ballTableCol(ball, table);
		});
	});
}

unsigned short Collision::ballRectCheck(Ball *ball, Rect *rect) {
	sf::Vector2f BP = ball->dObject->getPosition();
	sf::Transform trans = rect->dObject->getTransform();
	sf::Vector2f EP = trans * rect->localEP;
	sf::Vector2f SP = trans * rect->localSP;

	sf::Vector2f vSE = EP - SP;
	sf::Vector2f vBS = BP - SP;

	float lineLenghtPow = vSE.x * vSE.x + vSE.y * vSE.y;

	float t = std::max(0.0f, std::min(lineLenghtPow, vSE.x * vBS.x + vSE.y * vBS.y)) / lineLenghtPow;

	sf::Vector2f TP = SP + t * vSE;

	float distance = Physics::calcDistanceBetweenTwoPoints(TP, BP);
	
	//TEST
	//sf::Vertex line[] = { sf::Vertex(TP), sf::Vertex(BP) };
	//line[0].color = sf::Color::Red;
	//line[1].color = sf::Color::Red;
	//Game::getWindowObj().draw(line, 2, sf::Lines);
	//TEST

	if (distance <= ball->pixelRaidus + rect->pixelRadius) {
		if (t == 0 || t == 1) return 2;
		return 1;
		
	} else {
		return 0;
	}
}

void Collision::ballWallCol(Ball *ball, Wall *wall) {
	
	unsigned short side = ballRectCheck(ball, wall);
	if (side == 0) return;
	else
	{
		
	//Pilka nieodbita prez p2
	if (ball->p2 && ball->Colision!=3)
	{

		p1Point(ball);
	
	}

	//Pilka nieodbita prez p1
	else if (ball->p1 && ball->Colision != 3)
	{
		p2Point(ball);
	}

	//serwis w ktoras ze scian p1
	else if (ball->p1Serv == 1 && ball->Colision == 0)
	{
		p2Point(ball);
	}

	//serwis w ktoras ze scian p2
	else if (ball->p2Serv == 1 && ball->Colision == 0)
	{
		p1Point(ball);
	}

	//Nieodpicie pilki przy serwisie przez p1
	else if (ball->Colision == 3 && ball->p1Serv==2)
	{
		p2Point(ball);

	}

	//Nieodpicie pilki przy serwisie przez p2
	else if (ball->Colision == 3 && ball->p2Serv==2)
	{
		p1Point(ball);
	}

	//Serw odbicie od 1 czesci a potem sciana p1
	else if (ball->Colision = 1 && ball->p1==0 && ball->p1Serv==1)
	{
		p2Point(ball);
	}

	//Serw odbicie od 1 czesci a potem sciana p2
	else if (ball->Colision = 1 && ball->p2 == 0 && ball->p2Serv == 1)
	{
		p1Point(ball);
	}
	}
}

void Collision::ballRacketCol(Ball *ball, Racket *racket) {
	


	unsigned short side = ballRectCheck(ball, racket);
	if (side == 0) return;
	else 
	{
		
		if (ball->p1 &&ball->Colision==3)
		{
			calcballRacketCol(ball, racket);
			ball->p1Serv = 1;
			ball->p2Serv = 0;
			ball->Colision = 0;
			ball->p1 = false;
			ball->p2 = false;
		}

		else if (ball->p2 && ball->Colision == 3)
		{
			calcballRacketCol(ball, racket);
			ball->p1Serv = 0;
			ball->p2Serv = 1;
			ball->Colision = 0;
			ball->p1 = false;
			ball->p2 = false;
		}
		else if (ball->p2 && ball->Colision!=0)
		{
			ball->Colision = 0;
			ball->p1 = false;
			ball->p2 = false;
			calcballRacketCol(ball, racket);
		}
		else if (ball->p1 && ball->Colision != 0)
		{
			ball->Colision = 0;
			ball->p1 = false;
			ball->p2 = false;
			calcballRacketCol(ball, racket);
		}
		
	}
	
	


}

void Collision::ballTableCol(Ball *ball, Table *table)
{
	float time=0;
	unsigned short side = ballRectCheck(ball, table);
	if (side == 0) return;
	else

	
	{	
		std::cout << "p1Serw: " << ball->p1Serv << "  p2Serw" << ball->p2Serv << " p1  " << ball->p1 << "  p2  " << ball->p2 << "  Col  "<< ball->Colision<<" tab  " <<table->player<< "\n";
		//Serw pierwsze odbicie p1
		if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 0 && table->player == 1) 
		{
			time = ball->simTime;
			ball->Colision = 1;
			calcballTableCol(ball, table);
		}

		//Serw pierwsze odbicie p2
		if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 0 && table->player == 2)
		{
			time = ball->simTime;
			ball->Colision = 1;
			calcballTableCol(ball, table);
		}

		//Nieprawidlowo wykonany serw p1 odrazu na 2 polowe
		if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 0 && table->player == 2) 
		{
			p2Point(ball);
		}

		//Nieprawidlowo wykonany serw p2 odrazu na 2 polowe
		if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 0 && table->player == 1)
		{
			p1Point(ball);
		}

		//Nieprawidolwe podwojne odbicie p1 od tej samemj strony
		if (ball->p1Serv == 1 && ball->p1 == 0 && ball->Colision == 1 &&(time!=ball->simTime) && table->player == 1)
		{
			p2Point(ball);
		} 

		//Nieprawidolwe podwojne odbicie p2 od tej samemj strony
		if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 1 && (time != ball->simTime) && table->player == 2)
		{
			p2Point(ball);
		}

		//Drugie odbicie po serwie p1
		if ( ball->p1Serv==1 && ball->p1 == 0 && ball->Colision == 1 && table->player == 2)
		{
			ball->p2 = true;
			ball->p1Serv == 0;
			ball->Colision = 2;
			calcballTableCol(ball, table);
		}

		//Drugie odbicie po serwie p2
		if (ball->p2Serv == 1 && ball->p2 == 0 && ball->Colision == 1 && table->player == 1)
		{
			ball->p1 = true;
			ball->p2Serv == 0;
			ball->Colision = 2;
			calcballTableCol(ball, table);
		}

		//Nieodebrana pilka przez p1 
		if (ball->p1 && ball->Colision == 2 && table->player == 1)
		{
			p2Point(ball);
		}

		//Nieodebrana pilka przez p2 
		if (ball->p2 && ball->Colision == 2 && table->player == 2) 
		{
			p1Point(ball);
		}
		 
		
		
	}
}

void Collision::p1Point(Ball *ball)
{
	ball->dObject->setPosition(200, -300);
	ball->velocityVector = { 0.0f, 0.0f };
	ball->realPos = { Physics::calcRealValue(ball->dObject->getPosition().x),
	-Physics::calcRealValue(ball->dObject->getPosition().y) };
	ball->isballmove = false;
	ball->Colision = 0;
	ball->p1Serv = 2;
	ball->p2Serv = 0;
	ball->p1 = false;
	ball->p2 = true;
	Game::timeForBall = 0;
}

void Collision::p2Point(Ball *ball)
{
	ball->dObject->setPosition(1100, -300);
	ball->velocityVector = { 0.0f, 0.0f };
	ball->realPos = { Physics::calcRealValue(ball->dObject->getPosition().x),
	-Physics::calcRealValue(ball->dObject->getPosition().y) };
	ball->isballmove = false;
	ball->Colision = 0;
	ball->p2Serv = 2;
	ball->p1Serv = 0;
	ball->p1 = true;
	ball->p2 = false;
	Game::timeForBall = 0;
}


void Collision::calcballTableCol(Ball *ball, Table *table)
{
	float angle;
	angle = atan2(ball->realPos.y, ball->realPos.x);
	angle -= 1.57;
	ball->velocityVector = { 2 * ball->velocityVector.x * cos(angle),ball->velocityVector.y * sin(angle) };

}


void Collision::calcballRacketCol(Ball *ball, Racket *racket)
{
	sf::Transform trans = racket->dObject->getTransform();
	sf::Vector2f SP = trans * racket->localSP;
	sf::Vector2f EP = trans * racket->localEP;
	float angle;
	float tgalfa;
	ball->isballmove = true;

	float a2;
	if (ball->velocityVector.x == 0 && ball->velocityVector.y == 0)
		a2 = 0;
	else
	{
		sf::Vector2f oldBallPosPix = Physics::calcPixelVector(ball->oldRealPos);
		sf::Vector2f BallPosPix = Physics::calcPixelVector(ball->realPos);
		if (oldBallPosPix.x == BallPosPix.x || oldBallPosPix.y == BallPosPix.y)
		{
			a2 = 0;
		}
		else
			a2 = Physics::calcDirectionFactor(oldBallPosPix.x, oldBallPosPix.y, BallPosPix.x, BallPosPix.y);
	}


	if (SP.y == EP.y)
	{
		tgalfa = atan2(ball->dObject->getPosition().y, ball->dObject->getPosition().x);
		tgalfa = 1.57079- tgalfa;
	}
	else if (SP.x == EP.x)
	{
		tgalfa = atan2(ball->dObject->getPosition().y, ball->dObject->getPosition().x);
	}
	else
	{
		float a1 = Physics::calcDirectionFactor(SP.x, SP.y, EP.x, EP.y);
		tgalfa = abs(((a2 - a1) / (1 + a1 * a2)));
		tgalfa = atan(tgalfa);
		tgalfa = 1.570796 - tgalfa;
	}


	angle = tgalfa;
	

	
	if (angle > 1.4) angle = 1.3;
	else if (angle < -1.4) angle = -1.3;
	if (racket->velocityVector.x == 0 && racket->velocityVector.y == 0)
	{


		ball->velocityVector = { ball->velocity*cos(angle) , ball->velocity*sin(angle) };

	}
	else if ((ball->unitVector.x <= 0 && racket->unitVector.x >= 0) || ((ball->unitVector.x >= 0 && racket->unitVector.x <= 0)))
	{
		
		
		ball->velocityVector = { (((racket->velocityVector.x - ball->velocityVector.x)*racket->mass*cos(angle)
			+ (racket->velocityVector.x*racket->mass) + (ball->mass*ball->velocityVector.x)) / ((racket->mass + ball->mass)*cos(angle))) / 2,
			(((racket->velocityVector.y - ball->velocityVector.y)*racket->mass*sin(angle)
			+ (racket->velocityVector.y*racket->mass) + (ball->mass*ball->velocityVector.y)) / ((racket->mass + ball->mass)*sin(angle))) / 2

		};
		

		/*
		float r = acos(racket->velocityVector.x / racket->velocity);
		float b = acos(ball->velocityVector.x / ball->velocity);
		ball->velocityVector = { ((((racket->velocity*cos(r - angle)*(racket->mass - ball->mass) + 2 * ball->mass*ball->velocity*cos(b - angle))*cos(angle))
		/ (racket->mass + ball->mass)) + racket->velocity*sin(r - angle)*sin(angle)),
		(((racket->velocity*cos(r - angle)*(racket->mass - ball->mass) + 2 * ball->mass*ball->velocity*cos(b - angle))*sin(angle))
		/ (racket->mass + ball->mass)) + racket->velocity*sin(r - angle)*cos(angle) };
		*/
		

	}


}


Collision::~Collision() {
	walls.clear();
	rackets.clear();
	balls.clear();
	tables.clear();
}



