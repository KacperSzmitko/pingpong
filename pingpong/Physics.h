#pragma once

#define PHYSICS_DEFAULT_VISCOSITY 1.225f
#define PHYSICS_DEFAULT_GRAV 9.80665f
#define PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO 0.005f //Jeden piksel to 0,005 metra

#define PI 3.14159265359f

struct Physics {
	float viscosity, pressure, grav, wind;

	static const float pixelToRealRatio;

	struct Material {
		float friction;
		float elasticity;
	};

	struct Materials {

		static const Material wood;
		static const Material ball;
		static const Material racket;
	};

	Physics(float viscosity, float grav, float wind);
	Physics();

	void setViscosity(const float &viscosity);
	void setPressure(const float &pressure);
	void setGrav(const float &grav);
	void setWind(const float &win);

	static sf::Vector2f calcRealVector(const sf::Vector2f &pixelVector);
	static sf::Vector2f calcRealVector(const sf::Vector2i &pixelVector);
	static sf::Vector2f calcPixelVector(const sf::Vector2f &realVector);
	static float calcRealValue(const float &pixelValue);
	static float calcPixelValue(const float &realValue);
	static sf::Vector2f swapY(const sf::Vector2f &pos);
	static float calcDistanceBetweenTwoPoints(const sf::Vector2f &vector1, const sf::Vector2f &vector2);
};