#ifndef STROKE_H
#define STROKE_H

#include <drawable.hpp>

class Stroke : Drawable
{

protected:
	GLuint NUM_EXPANDED_VERTICES;
	GLfloat* expanded_vertices;
	void setupStroke();

private:
	

public:
	Stroke() {}


	//Drawable functions
	void setup(unsigned int &shader_program);

	void draw(unsigned int &shader_program);
};


#endif