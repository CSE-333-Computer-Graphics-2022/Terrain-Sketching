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

// return the closest point to P
glm::vec3 Stroke::getClosestPoint(glm::vec3 point) {
	GLfloat closest_point = 0;
	GLfloat min_dis = glm::distance(getVertex(closest_point), point);
	for(int i = 1; i < expanded_vertices.size()/3; i++) {
		GLfloat dis = glm::distance(getVertex(i), point);
		if(dis < min_dis) {
			min_dis = dis;
			closest_point = i;
		}
	}

	return getVertex(closest_point);
}


// traverse line and find num of intersections xD
bool Stroke::insideBoundary(glm::vec3 point) {
	GLfloat del_z = 1e-3;
	GLfloat del_x = 1e-3;
	int num_steps = (500)/glm::min(del_x, del_z);
	
	int num_intersections = 0;
	glm::vec3 curr_point = point;
	GLfloat error_prec = 1e-3;
	for(int i = 0; i < num_steps; i++) {
		glm::vec3 closest_point = this->getClosestPoint(curr_point);
		// check only for x and z
		GLfloat diff_error = glm::max(glm::abs(closest_point.x - point.x), glm::abs(closest_point.z - point.z));
		if(diff_error < error_prec) {
			num_intersections++;
		}
		curr_point = glm::vec3(curr_point.x + del_x, curr_point.y, curr_point.z + del_z);
	}

	if(num_intersections % 2 == 0) {
		// outside boundary
		return false;
	}
	return true;
}


GLint Stroke::coordToIndex(glm::vec3 point) {
	int idx = -1;

	for(int i = 0; i < expanded_vertices.size()/3; i++) {
		glm::vec3 stroke_point = this->getVertex(i);
		if(stroke_point == point) {
			idx = i;
		}
	}

	return idx;
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


float Stroke::getVariance()
{
	float mean = 0;
	for(int i = 1; i < expanded_vertices.size()/3; i++)
		mean += (expanded_vertices[i*3+1]-expanded_vertices[(i-1)*3 + 1]);
	mean /= (expanded_vertices.size()/3 - 1);
	float var = 0;
	for(int i = 1; i < expanded_vertices.size()/3; i++)
		var += ((expanded_vertices[i*3+1]-expanded_vertices[(i-1)*3 + 1])- mean)*((expanded_vertices[i*3+1]-expanded_vertices[(i-1)*3 + 1])- mean);
	var /= (expanded_vertices.size()/3 - 1);
	return var;
}

float Stroke::getProperVariance()
{
	float mean = 0;
	for(int i = 0; i < expanded_vertices.size()/3; i++)
		mean += (expanded_vertices[i*3+1]);
	mean /= expanded_vertices.size()/3;
	float var = 0;
	for(int i = 0; i < expanded_vertices.size()/3; i++)
		var += (expanded_vertices[i*3+1]- mean)*(expanded_vertices[i*3+1]- mean);
	var /= expanded_vertices.size()/3;
	return var;
}

glm::vec3 Stroke::getCentroid()
{
	glm::vec3 cent = glm::vec3();
	for(int i = 0; i < expanded_vertices.size()/3; i++)
		cent += getVertex(i);
	cent /= (expanded_vertices.size()/3);
	return cent;
}
