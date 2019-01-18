/// @Soft_Shadows.cpp
/// @Handles soft shadows, doesn't work

#include "Soft_Shadows.h"
#include <glm.hpp>


SoftShadows::SoftShadows()
{
	// Normalise everything to 0
	position = glm::vec3(0, 0, 0); 
	size = glm::vec3(0, 0, 0);

}

SoftShadows::SoftShadows(glm::vec3 _position, glm::vec3 _size)
{
	// Set values to be what has been passed in
	position = _position;
	size = _size;

}


SoftShadows::~SoftShadows()
{

}