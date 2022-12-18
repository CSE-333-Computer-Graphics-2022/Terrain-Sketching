#ifndef TERRAIN_H
#define TERRAIN_H

#include "drawable.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <GL/glew.h> // gluseProgram etc.. render
#include <stdio.h>
#include <utils/utils.hpp>

class Terrain : Drawable
{
private:
	const int NUM_X, NUM_Z;
	const double MIN_X, MAX_X;
	const double MIN_Z, MAX_Z;
	const double XF, ZF;
	static const int DIM = 3;
	const int NUM_V, NUM_I;
	glm::mat4 modelT;

	GLuint *ebo;

	GLfloat *height_map;
	GLuint *index_map;
	GLfloat *normal_map;
	void setupTerrain();
	void updateNormals(double x, double z);

public:
	void updateNormals();
	Terrain(const unsigned int num_x, const unsigned int num_y, const glm::vec3 center, double width, double depth) : NUM_X(num_x), NUM_Z(num_y), MIN_X((center.x - (width * 0.5))), MAX_X(center.x + (width * 0.5)),
																													MIN_Z(center.z - (depth * 0.5)), MAX_Z(center.z + (depth * 0.5)), XF((MAX_X - MIN_X) / (NUM_X - 1)), ZF((MAX_Z - MIN_Z) / (NUM_Z - 1)), NUM_V(NUM_X * NUM_Z), NUM_I(2 * (NUM_X - 1) * NUM_Z)
	{
		height_map = new GLfloat[NUM_V * DIM];
		normal_map = new GLfloat[NUM_V * DIM];
		index_map = new GLuint[NUM_I];
		modelT = glm::identity<glm::mat4>();
	}

	void addNoise();
	GLfloat getHeight(GLuint idx) {
		return height_map[(idx*DIM) + 1];
	}

	glm::vec3 getCoord(GLuint idx) {
		return glm::vec3(height_map[(idx*DIM)], height_map[(idx*DIM) + 1], height_map[(idx*DIM) + 2]);
	}

	int coordToIndex(double x, double z);
	GLuint getNumV() {
		return NUM_V;
	}

	void addHeight(GLfloat del_height, GLuint idx) {
		height_map[(idx*DIM) + 1] += del_height;
	}

	//Drawable functions
	void setup(unsigned int &shader_program);

	void draw(unsigned int &shader_program);
	void update();
};

#endif