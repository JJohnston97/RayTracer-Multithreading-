#pragma once
#include <iostream>
#include <glm.hpp>
#include "Ray.h"
#include "Shape.h"

#ifndef _SPHERE_H_
#define _SPHERE_H_


class Sphere : public Shape		// Sphere class
{
public:
	
	float radius;	// Shapes raduis, used to calculate the size of the sphere

	Sphere();		// Shape consturctor
	Sphere(glm::vec3 _position, float _radius, glm::vec3 _colour);	//Shapes constructor thats used to create the shape

	bool intersection(glm::vec3 _rayOrigin, glm::vec3 _rayDirection, float *t);	// Intersection function to check if an intersection between ray and sphere has happened

	glm::vec3 calculateNormal(glm::vec3 _p0, int *shininess, glm::vec3* diffuseColour, glm::vec3* specularColour);	// Calcuate normal is used to calculate the lighting normals for the sphere
	

};

#endif // !_SPHERE_H_
