#include <glm.hpp>
#include "Shape.h"

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_


// Triangle class included but not fully working, the shape will draw its shadow but it doesn't want to show the shape faces

class Triangle : public Shape
{
public:
	
	glm::vec3 a, b, c;						// Triangle 3 points
	glm::vec3 normalA, normalB, normalC;	// Normals for each point

	Triangle();	// Constructor
	Triangle(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c, glm::vec3 _colour, glm::vec3 _normalA, glm::vec3 _normalB, glm::vec3 _normalC); // Triangle calculation function

	glm::vec3 calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour);	// Calculate the normals for the triangle

	bool intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float *t);	// Intersection calculation function

	float u, v, w;	// Other Variables


};

#endif // !_TRIANGLE_H_
