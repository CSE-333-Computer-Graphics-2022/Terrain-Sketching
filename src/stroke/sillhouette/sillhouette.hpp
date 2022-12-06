#ifndef SILLHOUETTE_H
#define SILLHOUETTE_H

#include "../stroke.hpp"
#include "../shadow/shadow.hpp"
#include "../../terrain/terrain.hpp"
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
	int NUM_V;
	Terrain* terrain;
	Shadow* shadow;

public:
	Sillhouette(std::vector<glm::vec3 > _coordinates, Terrain* _terrain):
	coordinates(_coordinates), terrain(_terrain)
	{	
		NUM_V = coordinates.size();
		NUM_EXPANDED_VERTICES = NUM_V * 3;
		expanded_vertices = new GLfloat[NUM_V * 3];
		setupSillhouette();
		setupShadow();
	}
	void setupShadow();
	// temp 
	Sillhouette(Terrain* _terrain);
	~Sillhouette();
	void setupSillhouette();
	Shadow* getShadow() {
		return shadow;
	}
};





#endif