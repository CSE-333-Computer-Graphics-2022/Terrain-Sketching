#ifndef SILLHOUETTE_H
#define SILLHOUETTE_H

#include "../stroke.hpp"
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <iostream>
#include <fstream>
#include <string>


class Sillhouette : public Stroke
{
private:
	/* data */
	std::vector<glm::vec3 > coordinates; 
	GLfloat* expanded_vertices;
	int NUM_V;

public:
	Sillhouette(std::vector<glm::vec3 > _coordinates):
	coordinates(_coordinates)
	{	
		NUM_V = coordinates.size();
		NUM_EXPANDED_VERTICES = NUM_V * 3;
		expanded_vertices = new GLfloat[NUM_V * 3];
		setupSillhouette();
	}
	// temp 
	Sillhouette();
	~Sillhouette();
	void setupSillhouette();
	
};





#endif