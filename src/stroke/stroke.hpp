#ifndef STROKE_H
#define STROKE_H

#include <drawable.hpp>
#include <glm/glm.hpp>
#include <utils/utils.hpp>

// #include <GL/glew.h>

class Stroke : Drawable
{

protected:
	GLuint NUM_EXPANDED_VERTICES;
	GLfloat* expanded_vertices;
	void setupStroke();


private:
	glm::mat4 modelT;

public:
	Stroke() {
		modelT = glm::identity<glm::mat4>();
	}


	//Drawable functions
	void setup(unsigned int &shader_program);

	void draw(unsigned int &shader_program);
};


#endif