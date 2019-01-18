/// @Sphere.h
/// @Handles sphere object information

#include "Sphere.h"
#include <glm.hpp>

Sphere::Sphere()
{
	// Normalise everything to 0 on creation
	setPosition (glm::vec3(0, 0, 0));
	radius = 0;
	setColour(glm::vec3(0, 0, 0));
}


Sphere::Sphere(glm::vec3 _position, float _radius, glm::vec3 _colour)
{
	// Set values to be what has been passed
	setPosition (_position);
	radius = _radius;
	setColour(_colour);
}

// Refs for intersection:
// https://stackoverflow.com/questions/27511128/ray-tracing-geometric-sphere-intersection-intersection-function-returns-true
// https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
bool Sphere::intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float *t)
{
	glm::vec3 L = getPosition() - rayOrigin; // Get the position and take away the rays origin

	float tca = dot(L, rayDirection); // Calc the dot product of L and ray direction

	if (tca < 0) // If that is less than 0
	{
		return false; // Return

	}
	else
	{
		float s2 = (dot(L, L)) - (tca * tca);
		float s = sqrt(s2);
		if (s > radius)	// If the location of the ray is greater than the radius of the circle its not hit
		{
			return false; // False
		}
		else
		{
			float thc = sqrt((radius * radius) - s2); // If the ray is within the circle caculations then a hit has been made
			float t0 = tca - thc;
			*t = t0;
			return true; // True
		}

	}

}

glm::vec3 Sphere::calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour)
{
	*shininess = 28;							// Hard coded values for shininess
	*diffuseColour = getColour();				// The colour is taken from its stored value
	*specularColour = glm::vec3(0.7, 0.7, 0.7); // Specular colour set to 0.7 by default

	return (_p0 - getPosition());  // Return that colours / light point

}

