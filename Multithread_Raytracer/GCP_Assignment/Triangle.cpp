/// @Triangle.cpp
/// @Handles all triangle object functions


#include "Triangle.h"
#include <glm.hpp>

Triangle::Triangle()
{
	// Set everything to 0 apon creation
	a = glm::vec3(0, 0, 0);
	b = glm::vec3(0, 0, 0);
	c = glm::vec3(0, 0, 0);
	normalA = glm::vec3(0, 0, 0);
	normalB = glm::vec3(0, 0, 0);
	normalC = glm::vec3(0, 0, 0);

}

Triangle::Triangle(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c, glm::vec3 _colour, glm::vec3 _normalA, glm::vec3 _normalB, glm::vec3 _normalC)
{
	// Set all values to be what is passed into the constructor

	a = _a;
	b = _b;
	c = _c;
	normalA = _normalA;
	normalB = _normalB;
	normalC = _normalC;
	
	setColour(_colour);

	
}

// Ref
// https://stackoverflow.com/questions/28112091/ray-triangle-intersection-in-c
// https://stackoverflow.com/questions/28165548/ray-triangle-intersection-c

bool Triangle::intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float *t)
{
	glm::vec3 e1 = b - a;
	glm::vec3 e2 = c - a;

	u = dot((rayOrigin - a), cross(rayDirection, e2)) / dot(e1, (cross(rayDirection, e2)));
	v = dot(rayDirection, (cross((rayOrigin - a), e1)) / dot(e1, cross(rayDirection, e2)));
	w = 1 - u - v;
	float t0 = dot(e2, cross((rayOrigin - a), e1)) / dot(e1, cross(rayDirection, e2));


	if ((u < 0) || (u > 1))
	{
		return false;
	}

	else if ((v < 0) || (u + v > 1))
	{
		return false;
	}
	else
	{
		float t0 = dot(e2, cross((rayOrigin - a), e1)) / dot(e1, cross(rayDirection, e2));
		*t = t0;
		return true;
	}
}

glm::vec3 Triangle::calculateNormal(glm::vec3 _p0, int * shininess, glm::vec3 * diffuseColour, glm::vec3 * specularColour)
{
	// Default values
	*shininess = 100;
	*diffuseColour = getColour();
	*specularColour = glm::vec3(0.7, 0.7, 0.7);

	return (w * normalA) + (u * normalB) + (v * normalC);
}
