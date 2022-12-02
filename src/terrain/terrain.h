#ifndef TERRAIN_H
#define TERRAIN_H
#include<memory>
#include<glm/glm.hpp>
#include<vector>
#include<GL/glew.h> // gluseProgram etc.. render
#include <stdio.h>
#include <utils/utils.h>

class Terrain {
private:
	const int NUM_VER_X, NUM_VER_Z; 
	const float MIN_X, MAX_X;
	const float MIN_Z, MAX_Z;
	glm::mat4 modelT;

	// (x,z) -> y = 0 
	std::vector<std::vector<float> > height_map; 
	std::vector<std::vector<glm::vec3> > terrain_normals;


public:
	Terrain(const unsigned int no_ver_x, const unsigned int no_ver_y, const glm::vec3 center, float width, float depth):
		NUM_VER_X(no_ver_x), NUM_VER_Z(no_ver_y), MIN_X((center.x - (width*0.5))), MAX_X(center.x + (width*0.5)), 
		MIN_Z(center.z - (depth*0.5)), MAX_Z(center.z + (depth*0.5))
	{	
		height_map = std::vector<std::vector<float> >(no_ver_x, std::vector<float>(no_ver_y, 0.0f)); 
		addNoise();
		terrain_normals = std::vector<std::vector<glm::vec3> >(no_ver_x, std::vector<glm::vec3>(no_ver_y, glm::vec3(0.0))); 
		modelT = glm::identity<glm::mat4>();
		updateNormals();
	}


	void setupTerrain(unsigned int &shader_program, unsigned int &terrain_vao);

	
	void render(unsigned int &shader_program, unsigned int &terrain_vao);

	void updateNormals();

	void addNoise();

};

#endif