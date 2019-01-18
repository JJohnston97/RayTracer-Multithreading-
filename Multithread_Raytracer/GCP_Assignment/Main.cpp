/// \Main.cpp
/// \Handles the program

//File includes
#include <iostream>			// Allows for the use of cin, cout
#include <memory>			// used for pointers
#include <fstream>
#include <algorithm>
#include <thread>
#include <vector>
#include <string>
#include <ctime>

// Referances for multithreading
//https://www.boost.org/doc/libs/1_35_0/doc/html/thread/thread_management.html#thread.thread_management.thread
//https://sourceware.org/pthreads-win32/
//http://www.cplusplus.com/reference/thread/thread/

//Lib includes
#include <glm.hpp>

#include "Sphere.h"								
#include "Ground.h"								
#include "Triangle.h"							
#include "Soft_Shadows.h"

#define WINDOW_WIDTH 840		// Define the window width so it can be used anywhere in program as a form of global variable
#define WINDOW_HEIGHT 840		// Define the window height

// Function Prototypes
void RayTracer();
std::vector<std::shared_ptr<Shape>> createOBJ(std::vector<std::shared_ptr<Shape>> _circleList);
void RenderTexture(glm::vec3 **_image);
glm::vec3** renderQuad(int _widthMin, int _widthMax, int _heightMin, int _heightMax, std::vector<std::shared_ptr<Shape> > circleList, float _as, glm::vec3 **_image);

int main()
{
	
	RayTracer();	// Calls main function to calculate the ray tracer

	system("PAUSE"); // Pause the program at the end so you can see the run time of the render

	return 0;
}

void RayTracer()
{
	std::clock_t timer = clock();	// Creates a timer using the std function clock

	std::vector<std::shared_ptr<Shape> > circleList = createOBJ(circleList); // Create a shared ptr vector of shapes called circle list and calls the create object function

	SoftShadows* light = new SoftShadows(glm::vec3(-2.5f, 20, -2.5f), glm::vec3(9, 0.1f, 9)); // Attempt of soft shadows but is broken

	float as = 1e-4f; // Equal to 10^-4 easier to declate than write each time

	// Loop through the screen and create an image for each pixel
	glm::vec3 **image = new glm::vec3*[WINDOW_WIDTH];
	for (int i = 0; i < WINDOW_WIDTH; i++) image[i] = new glm::vec3[WINDOW_HEIGHT];


	// UNCOMMENT FOR 4 THREADS
	/*std::thread r1 (renderQuad, 0, 420, 0, 420, circleList, as, image);
	std::thread r2 (renderQuad, 420, 840, 0, 420, circleList, as, image);
	std::thread r3 (renderQuad, 0, 420, 420, 840, circleList, as, image);
	std::thread r4 (renderQuad, 420, 840, 420, 840, circleList, as, image);*/
	
	// UNCOMMENT FOR 8 THREADS
	/*std::thread r1(renderQuad, 0, 210, 0, 420, circleList, as, image);
	std::thread r2(renderQuad, 210, 420, 0, 420, circleList, as, image);
	std::thread r3(renderQuad, 420, 630, 0, 420, circleList, as, image);
	std::thread r4(renderQuad, 630, 840, 0, 420, circleList, as, image);
	std::thread r5(renderQuad, 0, 210, 420, 840, circleList, as, image);
	std::thread r6(renderQuad, 210, 420, 420, 840, circleList, as, image);
	std::thread r7(renderQuad, 420, 630, 420, 840, circleList, as, image);
	std::thread r8(renderQuad, 630, 840, 420, 840, circleList, as, image);*/

	// UNCOMMENT FOR 12 THREADS
	std::thread r1(renderQuad, 0, 210, 0, 280, circleList, as, image);
	std::thread r2(renderQuad, 210, 420, 0, 280, circleList, as, image);
	std::thread r3(renderQuad, 420, 630, 0, 280, circleList, as, image);
	std::thread r4(renderQuad, 630, 840, 0, 280, circleList, as, image);
	std::thread r5(renderQuad, 0, 210, 280, 560, circleList, as, image);
	std::thread r6(renderQuad, 210, 420, 280, 560, circleList, as, image);
	std::thread r7(renderQuad, 420, 630, 280, 560, circleList, as, image);
	std::thread r8(renderQuad, 630, 840, 280, 560, circleList, as, image);
	std::thread r9(renderQuad, 0, 210, 560, 840, circleList, as, image);
	std::thread r10(renderQuad, 210, 420, 560, 840, circleList, as, image);
	std::thread r11(renderQuad, 420, 630, 560, 840, circleList, as, image);
	std::thread r12(renderQuad, 630, 840, 560, 840, circleList, as, image);

	// COMMENT / UNCOMMENT DEPENDING ON HOW MANY YOU WANT TO RUN
	r1.join();
	r2.join();
	r3.join();
	r4.join();
	r5.join();
	r6.join();
	r7.join();
	r8.join();
	r9.join();
	r10.join();
	r11.join();
	r12.join();


	// RENDER WITHIN THREADS 
	/*renderQuad(0, 420, 0, 420, circleList, as, image);
	renderQuad(420, 840, 0, 420, circleList, as, image);
	renderQuad(0, 420, 420, 840, circleList, as, image);
	renderQuad(420, 840, 420, 840, circleList, as, image);*/


	RenderTexture(image); // Sends the image array into the render text function that renders the image to a .ppm file

	std::clock_t end = clock();					// Creates an end for the timer
	std::clock_t timeTakenInTicks = end - timer; // Time taken calculation

	float timerInSec = timeTakenInTicks / (float)CLOCKS_PER_SEC;	// Change the number from clock function into seconds
	std::cout << "Render Time =" << timerInSec << std::endl;		// Output the render time to the console

}

std::vector<std::shared_ptr<Shape>> createOBJ(std::vector<std::shared_ptr<Shape>> _circleList)
{

	// Creates all the object that are pushed into the vector
	_circleList.push_back(std::make_shared<Ground>(glm::vec3(0, -5.5, 0), glm::vec3(0, 1, 0), glm::vec3(0.37, 0.64, 0.7)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(0, 1, -14), 3, glm::vec3(0.16, 0.0, 0.88)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(3, -3, -16), 2.8, glm::vec3(0.21, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(6, -3, -18), 2.5, glm::vec3(0.27, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(9, -3, -20), 2.2, glm::vec3(0.32, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(12, -3, -22), 2.0, glm::vec3(0.38, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(15, -3, -24), 1.8, glm::vec3(0.43, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(18, -3, -26), 1.6, glm::vec3(0.48, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(-3, -3, -16), 2.8, glm::vec3(0.16, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(-6, -3, -18), 2.5, glm::vec3(0.21, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(-9, -3, -20), 2.2, glm::vec3(0.27, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(-12, -3, -22), 2.0, glm::vec3(0.32, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(-15, -3, -24), 1.8, glm::vec3(0.38, 0.0, 0.64)));
	_circleList.push_back(std::make_shared<Sphere>(glm::vec3(-18, -3, -26), 1.6, glm::vec3(0.43, 0.0, 0.64)));
	//_circleList.push_back(std::make_shared<Triangle>(glm::vec3(0, 5, -25), glm::vec3(-1.9, 2.2, -5), glm::vec3(1.9, 2.2, -5), glm::vec3(0.37, 0.64, 0.7), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)));

	return _circleList; // Returns the vector
}

void RenderTexture(glm::vec3 **_image) // Function to draw the image takes the image array
{

	std::ofstream ofs("../Render_Image/render.ppm", std::ios::out | std::ios::binary); // Creates a directory as to where to save the file and name
	ofs << "P6\n" << WINDOW_WIDTH << " " << WINDOW_HEIGHT << "\n255\n";

	for (unsigned y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (unsigned x = 0; x < WINDOW_WIDTH; x++)
		{
			ofs << (unsigned char)(std::min((float)1, (float)_image[x][y].x) * 255) <<
				(unsigned char)(std::min((float)1, (float)_image[x][y].y) * 255) <<
				(unsigned char)(std::min((float)1, (float)_image[x][y].z) * 255);

		}
	}
	ofs.close();

}

glm::vec3** renderQuad(int _widthMin, int _widthMax, int _heightMin, int _heightMax, std::vector<std::shared_ptr<Shape> > circleList, float _as, glm::vec3 **_image) // Render funcion that will render a x , y image
{
	
	for (int x = _widthMin; x < _widthMax; x++)			// Loop through the x and y of the screen			
	{														
		for (int y = _heightMin; y < _heightMax; y++)		
		{
		
			// Create a float for the normal x and y and make it equal to the center of each pixel
			float pixelNormalX = (x + 0.5) / WINDOW_WIDTH;
			float pixelNormalY = (y + 0.5) / WINDOW_HEIGHT;		
			

			// Create the camera and give each pizel a ray origin and direction
			float pixelRempX = (2 * pixelNormalX - 1);
			float pixelRemapY = 1 - 2 * pixelNormalY;
			float pixelCameraX = pixelRempX * tan(glm::radians(90.0) / 2);
			float pixelCameraY = pixelRemapY * tan(glm::radians(90.0) / 2);
			glm::vec3 pixCameraSpace = glm::vec3(pixelCameraX, pixelCameraY, -1);
			glm::vec3 rayOrigin = glm::vec3(0, 0, 0);
			glm::vec3 rayDirection = glm::normalize(pixCameraSpace - rayOrigin);

			// Define some regularly used variables
			float minT = INFINITY;
			int sphereHit = -1;
			float t0 = 0.0f;

			// Go through the list of objects within the circle list and check if they have had an intersection
			for (int j = 0; j < circleList.size(); j++)
			{
				bool hit = circleList[j]->intersection(rayOrigin, rayDirection, &t0); // Send to the intersection function

				if (hit && t0 < minT)
				{
					minT = t0;
					sphereHit = j;
				}
			}

			// If a shape has been hit
			if (sphereHit != -1)
			{
				glm::vec3 p0 = rayOrigin + (minT * rayDirection);

				//Light values
				glm::vec3 lightPosition = glm::vec3(-5, 15, -4);
				glm::vec3 lightIntensity = glm::vec3(1.0, 1.0, 1.0);


				//Diffuse and Spect colour properties
				glm::vec3 diffuseColour = glm::vec3(0, 0, 0);
				glm::vec3 specularColour = glm::vec3(0, 0, 0);
				int shininess = 0;

				//Create the normals
				glm::vec3 normal = glm::normalize(circleList[sphereHit]->calculateNormal(p0, &shininess, &diffuseColour, &specularColour));


				//Ambient Lighting
				glm::vec3 ambient = circleList[sphereHit]->getColour() * glm::vec3(0.1, 0.1, 0.1);


				//Diffuse Lighting
				glm::vec3 lightRay = glm::normalize(lightPosition - p0);
				glm::vec3 diffuse = diffuseColour * lightIntensity * glm::max(0.0f, dot(lightRay, normal));

				////Specular lighting
				glm::vec3 reflection = glm::normalize(2 * (dot(lightRay, normal)) * normal - lightRay);
				float maxCalc = glm::max(0.0f, dot(reflection, glm::normalize(rayOrigin - p0)));
				glm::vec3 specular = specularColour * lightIntensity * pow(maxCalc, shininess);

				int lightShapeHit = -1;

				// Loop through the vector of shapes again and check intersection with lighting for shadows
				for (unsigned p = 0; p < circleList.size(); p++)
				{
					bool lightHit = circleList[p]->intersection(p0 + (_as * normal), lightRay, &t0);

					if (lightHit && t0 < minT)
					{
						minT = t0;
						lightShapeHit = 1;

					}
				}

				// If light is not false 
				if (lightShapeHit != -1)
				{
					_image[x][y] = circleList[lightShapeHit]->getColour() * ambient; // Calculate the light with shadows
				}
				else
				{
					//Combined lighting just diffuse and specular no lighting
					_image[x][y] = diffuse + specular;
				}
			}
			else
			{
				// If non of these just draw everything black
				_image[x][y] = glm::vec3(1.0, 1.0, 1.0);
			}
		}
	}


	return _image; // Return that rendered section
}