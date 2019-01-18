/// @Shape.cpp
/// @breif Handles the creation and intersection of shapes

#include "Shape.h"
#include <glm.hpp>


Shape::Shape()
{
	// Normalise everything to 0
	position = glm::vec3(0, 0, 0);
	Colour = glm::vec3(0, 0, 0);
	normal = glm::vec3(0, 0, 0);
}

// Assigning the shapes values to the value that has been passed in
Shape::Shape(glm::vec3 _position, glm::vec3 _colour, glm::vec3 _normal)
{
	position = _position;
	Colour = _colour;
	normal = _normal;

}

// Shape intersection and calculate normals functions, these are virtual meaning that these functions will change within the respected shapes own function
bool Shape::intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float* t)
{
	return false;
}

// Shape intersection and calculate normals functions, these are virtual meaning that these functions will change within the respected shapes own function
glm::vec3 Shape::calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour)
{
	return normal;

}