#include <glm.hpp> 

#ifndef _SHAPE_H_
#define _SHAPE_H_


class Shape  // Main shape class that all object inherit from
{
public:


	Shape();	//Empty Shape constructor for the init
	Shape(glm::vec3 _position, glm::vec3 _colour, glm::vec3 _normal);	// Shape function used to construct the shapes

	// Get functions allowing me to keep my variables private
	glm::vec3 getPosition() { return position; }
	glm::vec3 getColour() { return Colour; }
	glm::vec3 getNormal() { return normal; }

	// Set functions again to allows for a better coding standard over having my variables public
	void setPosition(glm::vec3 _position) { position = _position; }
	void setColour(glm::vec3 _colour) { Colour = _colour; }
	void setNormal(glm::vec3 _normal) { normal = _normal; }

	// Shape intersection and calculate normals functions, these are virtual meaning that these functions will change within the respected shapes own function
	virtual bool intersection(glm::vec3 rayOrigin, glm::vec3 rayDirection, float *t);
	virtual glm::vec3 calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour);

private:

	// Shape variables
	glm::vec3 position;
	glm::vec3 Colour;
	glm::vec3 normal;

};

#endif // !_SHAPE_H_

