#include "pch.h"
#include "CountingFunctions.h"
#include <cmath>

float CalculateSx(float time,float Vx,float mass,float resistance)
{
	return (mass / resistance)* Vx*(1 - exp((-resistance * time) / mass));
}
float CalculateSy(float Vyo,float time,float grav,float mass,float resistance)
{
	return ((-mass * grav*time) / resistance) + ((mass / resistance)*(Vyo + ((mass*grav) / resistance)))* (1 - exp((-resistance * time) / mass));
		
}


float CalculateVxStart(float Vp,float angle)
{
	return cos(angle)*Vp;
	
}
float CalculateVyStart(float Vp, float angle)
{
	return Vp * sin(angle);
}

float CalculateVx(float Vxo, float time, float mass, float resistance)
{
	return Vxo * exp((-resistance / mass)*time);
}
float CalculateVy(float Vyo, float time, float mass, float grav, float resistance)
{
	return (((-mass * grav) / resistance) + (exp((-resistance * time) / mass)*Vyo) + (exp((-resistance * time) / mass)*((mass * grav) / resistance)));
}