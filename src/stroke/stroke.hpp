#ifndef STROKE_H
#define STROKE_H

#include <drawable.hpp>
#include <glm/glm.hpp>
#include <vector>
#include <utils/utils.hpp>

// #include <GL/glew.h>

class Stroke : Drawable
{

protected:
	const GLuint MAX_VERTICES = 1000;
	std::vector<GLfloat> expanded_vertices;

private:
	glm::mat4 modelT;

public:
	Stroke() {
		modelT = glm::identity<glm::mat4>();
	}

	void update(glm::vec3 vertex);

	//Drawable functions
	void setup(unsigned int &shader_program);

	void draw(unsigned int &shader_program);
};


#endif