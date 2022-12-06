#include "stroke.hpp"
#include<utils/utils.hpp>

void Stroke::draw(unsigned int &shader_program) {
	unsigned int vColor_uniform = getUniform(shader_program, "vColor");
	glUniform4f(vColor_uniform, 1, 0, 0, 1.0);

	unsigned int vModel_uniform = getUniform(shader_program, "vModel");
	glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(300);
	glBindVertexArray(*vao);
	glDrawArrays(GL_LINE_STRIP, 0, NUM_EXPANDED_VERTICES/3);
	glDisable(GL_LINE_SMOOTH);
}

void Stroke::setup(unsigned int &shader_program) {
	glUseProgram(shader_program);
	vao = new GLuint;
	vbo = new GLuint;
	unsigned int vVertex_attrib = getAttrib(shader_program, "vVertex");
	// unsigned int vNormal_attrib = getAttrib(shader_program, "vNormal");


	// generate VAO objects
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);

	// genereate VBOs for VAO
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, NUM_EXPANDED_VERTICES * sizeof(GLfloat), expanded_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vVertex_attrib);
	glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// unbind VAO to disable changes outside this fn
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



}

