#include "terrain.h"

void Terrain::setupTerrain(unsigned int &shader_program, unsigned int &terrain_vao) 
{
	glUseProgram(shader_program);

	int vVertex_attrib = glGetAttribLocation(shader_program, "vVertex");
	if(vVertex_attrib == -1) {
		fprintf(stderr, "Terrain class render: Could not bind location: vVertex\n");
		exit(0);
	}

	// get the vertices

	GLfloat terrain_vertices[NUM_VER_X * NUM_VER_Z * 4 * 3];
	int curr_terr_index = 0;
	for(int z = 0; z < NUM_VER_Z; z++) {
		for(int x = 0; x < NUM_VER_X; x++) {
			// v1: x z
			terrain_vertices[curr_terr_index] = (x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x][z];
			terrain_vertices[curr_terr_index + 2] = (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;

			curr_terr_index += 3;
			// v2: x+1 z
			terrain_vertices[curr_terr_index] = (x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x+1][z];
			terrain_vertices[curr_terr_index + 2] = (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;
			
			curr_terr_index += 3;
			// v3: x z+1
			terrain_vertices[curr_terr_index] = (x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x][z+1];
			terrain_vertices[curr_terr_index + 2] = (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;
			
			curr_terr_index += 3;

			// v4: x+1 z+1
			terrain_vertices[curr_terr_index] = (x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x+1][z+1];
			terrain_vertices[curr_terr_index + 2] = (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;
			
			curr_terr_index += 3;
		}
	}
	
	// generate terrain VAO object
	// 1: number of vertex array objects
	glGenVertexArrays(1, &terrain_vao);
	glBindVertexArray(terrain_vao);

	// create VBO for the VAO
	int num_terrain_vertices = NUM_VER_X * NUM_VER_Z * 4 * 3;
	GLuint terrain_vbo;
	glGenBuffers(1, &terrain_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, terrain_vbo);
	glBufferData(GL_ARRAY_BUFFER, NUM_VER_X * NUM_VER_Z * 4 * 3 * sizeof(GLfloat), terrain_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vVertex_attrib);
	glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); //Unbind the VAO to disable changes outside this function.


}


void Terrain::render(unsigned int &shader_program, unsigned int &terrain_vao) {
	int vColor_uniform = glGetUniformLocation(shader_program, "vColor");
	if(vColor_uniform == -1){
		fprintf(stderr, "Terrain Render: Could not bind location: vColor\n");
		exit(0);
	}
	glBindVertexArray(terrain_vao); 
	glUniform4f(vColor_uniform, 0.5, 0.5, 0.5, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, NUM_VER_X * NUM_VER_Z * 4 * 3);
}