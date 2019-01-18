#include <glm.hpp>
#include "Shape.h"

#ifndef _GROUND_H_
#define _GROUND_H_


class Ground : public Shape		// Ground (Plane) object class, inherits from shape as all objects do
{
public:

	glm::vec3 groundNormal;		// Vec3 to hold the ground normals x,y,z
	Ground();					// Empty Constructor for on init
	Ground(glm::vec3 _position, glm::vec3 _normal, glm::vec3 _colour);		  // Constructor used to draw the object

	bool intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float *t); // Intersection function to check if an intersection between ray and ground has been met
	
	glm::vec3 calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour); // Calcuate normal is used to calculate the lighting normals for the ground



};
#endif // !_GROUND_H