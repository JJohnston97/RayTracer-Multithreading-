#include <glm.hpp>

#ifndef _SOFT_SHADOWS_H_
#define _SOFT_SHADOWS_H_

// NOT WORKING BUT ATTEMPTED

class SoftShadows	// Softshadows class
{
public:

	// Get functions again allowing me to hold private variables, these would work fine as public varables but am trying to get use to
	// using a more professional structured approach
	glm::vec3 getPosition() { return position; }
	glm::vec3 getSize() { return size; }

	// Set functions
	void setPosition(glm::vec3 _position) { position = _position; }
	void setSize(glm::vec3 _size) { size = _size; }


	SoftShadows();	// Constructor
	~SoftShadows(); // Destructor

	SoftShadows(glm::vec3 _position, glm::vec3 size); // Create function

private:

	// Other variables
	glm::vec3 position;
	glm::vec3 size;


};

#endif // !_SOFT_SHADOWS_H_

