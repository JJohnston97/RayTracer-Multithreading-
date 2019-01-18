#include <glm.hpp>

#ifndef _RAY_H_
#define _RAY_H_


class Ray
{

public:


	/*Ray(glm::vec3 _origin, glm::vec3 _direction) { Origin = _origin, Direction = _direction; }
	glm::vec3 getOrigin() { return Origin; }
	glm::vec3 getDirection() { return Direction; }*/

	glm::vec3 Origin;
	glm::vec3 Direction;


};
#endif // !_RAY_H
