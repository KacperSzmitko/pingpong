#include "pch.h"
#include "Physics.h"

const float Physics::pixelToRealRatio = PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO;
float Physics::viscosity = PHYSICS_DEFAULT_VISCOSITY;
float Physics::grav = PHYSICS_DEFAULT_GRAV;
float Physics::wind = 0.0f;

const Physics::Material Physics::Materials::wood = { 1.0f, 1.0f };
const Physics::Material Physics::Materials::ball = { 1.0f, 1.0f };
const Physics::Material Physics::Materials::racket = { 1.0f, 1.0f };
const Physics::Material Physics::Materials::net = { 0.2f, 0.2f };

void Physics::resetValues() {
	viscosity = PHYSICS_DEFAULT_VISCOSITY;
	grav = PHYSICS_DEFAULT_GRAV;
	wind = 0.0f;
}

sf::Vector2i Physics::floatVectorToIntVector(const sf::Vector2f &floatVector) {
	return { (int)floatVector.x, (int)floatVector.y };
}

sf::Vector2f Physics::calcRealVector(const sf::Vector2f &pixelVector) {
	float ptrr = pixelToRealRatio;
	return { pixelVector.x * ptrr, pixelVector.y * ptrr };
}

//Przeci¹¿enie, aby dzia³a³o te¿ dla wektorów intowych
sf::Vector2f Physics::calcRealVector(const sf::Vector2i &pixelVector) {
	float ptrr = pixelToRealRatio;
	return { (float)pixelVector.x * ptrr, (float)pixelVector.y * ptrr };
}

sf::Vector2f Physics::calcPixelVector(const sf::Vector2f &realVector) {
	float ptrr = pixelToRealRatio;
	return { (float)realVector.x / ptrr, (float)realVector.y / ptrr };
}

float Physics::calcRealValue(const float &pixelValue) {
	return pixelValue * pixelToRealRatio;
}

float Physics::calcPixelValue(const float &realValue) {
	return realValue / pixelToRealRatio;
}

sf::Vector2f Physics::swapY(const sf::Vector2f &pos) {
	return { pos.x, -pos.y };
}

float Physics::calcDistanceBetweenTwoPoints(const sf::Vector2f &v1, const sf::Vector2f &v2) {
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}

float Physics::calcDirectionFactor(float x1, float y1, float x2, float y2)
{
	return (y2 - y1) / (x2 - x1);
}