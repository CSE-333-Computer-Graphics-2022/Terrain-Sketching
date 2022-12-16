#ifndef SILHOUETTE_H
#define SILHOUETTE_H

#include "../stroke.hpp"
#include "../shadow/shadow.hpp"
#include "../boundary/boundary.hpp"
#include "../../terrain/terrain.hpp"
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <iostream>
#include <fstream>
#include <string>


class Silhouette : public Stroke
{
private:
	/* data */
	std::vector<glm::vec3 > coordinates; 
	int NUM_V;
	Terrain* terrain;
	Shadow* shadow;
	Boundary* boundary;

public:
	Silhouette(std::vector<glm::vec3 > _coordinates, Terrain* _terrain):
	coordinates(_coordinates), terrain(_terrain)
	{	
		NUM_V = coordinates.size();
		NUM_EXPANDED_VERTICES = NUM_V * 3;
		expanded_vertices = new GLfloat[NUM_V * 3];
		setupSilhouette();
		setupShadow();
		setupBoundary();
	}
	void setupShadow();
	void setupBoundary();
	// temp 
	Silhouette(Terrain* _terrain);
	~Silhouette();
	void setupSilhouette();
	Shadow* getShadow() {
		return shadow;
	}
	Boundary* getBoundary() {
		return boundary;
	}
};





#endif