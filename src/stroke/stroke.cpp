#include "stroke.hpp"
#include<utils/utils.hpp>

void Stroke::draw(unsigned int &shader_program) {
	glEnable(GL_LINE_SMOOTH);
	unsigned int vColor_uniform = getUniform(shader_program, "vColor");
	glUniform4f(vColor_uniform, 1, 0, 0, 1.0);

	unsigned int vModel_uniform = getUniform(shader_program, "vModel");
	glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));

	glBindVertexArray(*vao);
	glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, expanded_vertices.size()/3);
	glDisable(GL_LINE_SMOOTH);
}

void Stroke::addVertex(glm::vec3 vertex){
	if(expanded_vertices.size()/3 >= MAX_VERTICES)return;
	expanded_vertices.push_back(vertex.x);
	expanded_vertices.push_back(vertex.y);
	expanded_vertices.push_back(vertex.z);
	GLfloat temp[] = {vertex.x,vertex.y,vertex.z};
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferSubData(GL_ARRAY_BUFFER,(expanded_vertices.size()-3)*sizeof(GLfloat),3*sizeof(GLfloat),temp);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);
}

//Update this function for dynamic drawing
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
	glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES*3* sizeof(GLfloat), NULL, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vVertex_attrib);
	glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// unbind VAO to disable changes outside this fn
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

