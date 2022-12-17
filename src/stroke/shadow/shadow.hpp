#ifndef SHADOW_H
#define SHADOW_H

#include "../stroke.hpp"
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>


class Shadow: public Stroke
{
private:
	/* data */
	std::vector<glm::vec3 > coordinates; 
	int NUM_V;
	

public:
	Shadow(std::vector<glm::vec3 > _coordinates):
	coordinates(_coordinates)
	{	
		NUM_V = coordinates.size();
		setupShadow();
	}
	~Shadow();
	void setupShadow();
	
};





#endif