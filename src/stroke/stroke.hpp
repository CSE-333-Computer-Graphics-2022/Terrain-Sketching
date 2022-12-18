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

	inline int getSize(){return expanded_vertices.size()/3;}
	inline glm::vec3 getVertex(int i){return glm::vec3(expanded_vertices[i*3],expanded_vertices[i*3+1],expanded_vertices[i*3+2]);}

	void addVertex(glm::vec3 vertex);

	glm::vec3 getClosestPoint(glm::vec3 point);

// :>><<<<<<
	bool insideBoundary(glm::vec3 point);
	GLint coordToIndex(glm::vec3 point);

	//Drawable functions
	void setup(unsigned int &shader_program);

	void draw(unsigned int &shader_program);
};


#endif