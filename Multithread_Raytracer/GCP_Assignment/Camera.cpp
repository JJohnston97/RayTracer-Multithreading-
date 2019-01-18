#include "Camera.h"
#include "Ray.h"
#include <memory>

Ray Camera::createRayFromCoordinate(int _x, int _y)
{

	Ray myRay;
	
	myRay.Direction = glm::vec3(0.0f, 0.0f, -2.0f);
	myRay.Direction = glm::vec3(glm::mat4(1.0f) * glm::vec4(myRay.Direction, 1));
	myRay.Origin = glm::vec3(_x, _y, 0);



	return myRay;
}