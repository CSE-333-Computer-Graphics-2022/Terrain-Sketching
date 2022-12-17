#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "../stroke.hpp"
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>


class Boundary: public Stroke
{
private:
	/* data */
	std::vector<glm::vec3 > coordinates; 
	int NUM_V;
	

public:
	Boundary(std::vector<glm::vec3 > _coordinates):
	coordinates(_coordinates)
	{	
		NUM_V = coordinates.size();
		setupBoundary();
	}
	~Boundary();
	void setupBoundary();
	
};





#endif