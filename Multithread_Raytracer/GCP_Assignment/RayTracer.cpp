#include "RayTracer.h"

glm::vec4 RayTracer::TraceRay(Ray _Ray)
{
	glm::vec4 col;

	int red = rand() % 255;
	int blue = rand() % 255;
	int green = rand() % 255;

	col.r = red;
	col.g = blue;
	col.b = green;

	return col;

}