#ifndef TERRAIN_H
#define TERRAIN_H

#include "drawable.h"
#include <glm/glm.hpp>
#include <vector>
#include <GL/glew.h> // gluseProgram etc.. render
#include <stdio.h>
#include <utils/utils.h>

class Terrain : Drawable
{
private:
	const int NUM_X, NUM_Z;
	const float MIN_X, MAX_X;
	const float MIN_Z, MAX_Z;
	const float XF, ZF;
	static const int DIM = 3;
	const int NUM_V, NUM_I;
	glm::mat4 modelT;

	GLuint *ebo;

	GLfloat *height_map;
	GLuint *index_map;
	GLfloat *normal_map;
	GLuint coordToIndex(float x, float z);
	void updateNormals(float x, float z);
	void setupTerrain();

public:
	Terrain(const unsigned int num_x, const unsigned int num_y, const glm::vec3 center, float width, float depth) : NUM_X(num_x), NUM_Z(num_y), MIN_X((center.x - (width * 0.5))), MAX_X(center.x + (width * 0.5)),
																													MIN_Z(center.z - (depth * 0.5)), MAX_Z(center.z + (depth * 0.5)), XF((MAX_X - MIN_X) / (NUM_X - 1)), ZF((MAX_Z - MIN_Z) / (NUM_Z - 1)), NUM_V(NUM_X * NUM_Z), NUM_I(2 * (NUM_X - 1) * NUM_Z)
	{
		height_map = new GLfloat[NUM_V * DIM];
		normal_map = new GLfloat[NUM_V * DIM];
		index_map = new GLuint[NUM_I];
		modelT = glm::identity<glm::mat4>();
	}

	void addNoise();

	//Drawable functions
	void setup(unsigned int &shader_program);

	void draw(unsigned int &shader_program);
};

#endif