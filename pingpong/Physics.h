#pragma once

#define PHYSICS_DEFAULT_VISCOSITY 1.225f
#define PHYSICS_DEFAULT_GRAV 9.81f
#define PHYSICS_DEFAULT_PIXEL_TO_REAL_RATIO 0.005f //Jeden piksel to 0,005 metra

#define PI 3.14159265359f

struct Physics {
	static float viscosity, grav, wind;

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

	void setViscosity(const float &viscosity);
	void setPressure(const float &pressure);
	void setGrav(const float &grav);
	void setWind(const float &win);

	
	


	static float calcDirectionFactor(float x1, float y1, float x2, float y2);
	static sf::Vector2f calcRealVector(const sf::Vector2f &pixelVector);
	static sf::Vector2f calcRealVector(const sf::Vector2i &pixelVector);
	static sf::Vector2f calcPixelVector(const sf::Vector2f &realVector);
	static float calcRealValue(const float &pixelValue);
	static float calcPixelValue(const float &realValue);
	static sf::Vector2f swapY(const sf::Vector2f &pos);
	static float calcDistanceBetweenTwoPoints(const sf::Vector2f &vector1, const sf::Vector2f &vector2);
};