#include "Ground.h"
#include <glm.hpp>


Ground::Ground()
{
	groundNormal = glm::vec3(0, 0, 0); // Initialise the grounds normals to 0

}

Ground::Ground(glm::vec3 _position, glm::vec3 _normal, glm::vec3 _colour)
{
	setPosition(_position);  // Set its position to the position passed in
	groundNormal = _normal;	 // Set the ground normals to be the normals passed in
	setColour(_colour);		 // Set the colour to be colour
}

// Refs for intersection:
// https://stackoverflow.com/questions/23975555/how-to-do-ray-plane-intersection

bool Ground::intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float *t) // Intersection function
{
	float Ry = dot(rayDirection, groundNormal); // Calculate the dot product of the rays direction and the ground normal

	if (abs(Ry) < 1e-6) // If the results is less than 1e-6 (1*10^6) 0.0000001
	{
		return false; // An intersection hasnt happened
	}
	else
	{
		float result = dot((getPosition() - rayOrigin), groundNormal) / Ry; // Calcualte the intersections
		*t = result;
		return *t >= 0;
	}
}

glm::vec3 Ground::calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour)
{
	*shininess = 50; // Set the shininess to be 50
	*diffuseColour = glm::vec3(0.3, 0.3, 0.3); // Set the diffuse colour to 0.3 in x y and z
	*specularColour = getColour();	// Set the colour to be the colour set 
	return groundNormal;	// Return everything as a whole through groundNormal vec 3 

}