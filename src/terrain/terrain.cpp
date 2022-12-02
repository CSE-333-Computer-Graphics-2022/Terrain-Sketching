#include "terrain.h"
#include <random>

void Terrain::setupTerrain(unsigned int &shader_program, unsigned int &terrain_vao) 
{
	
	// update normals
	this->updateNormals();

	glUseProgram(shader_program);

	int vVertex_attrib = glGetAttribLocation(shader_program, "vVertex");
	if(vVertex_attrib == -1) {
		fprintf(stderr, "Terrain class setup: Could not bind location: vVertex\n");
		exit(0);
	}

	int vNormal_attrib = glGetAttribLocation(shader_program, "vNormal");
	if(vNormal_attrib == -1) {
		fprintf(stderr, "Terrain class setup: Could not bind location: vnormal\n");
		exit(0);
	}


	// get the vertices

	GLfloat terrain_vertices[2 * NUM_VER_X * NUM_VER_Z * 4 * 3];
	// GLfloat terrain_vNormals[NUM_VER_X * NUM_VER_Z * 4 * 3];
	int normal_offset = NUM_VER_X * NUM_VER_Z * 4 * 3; 
	int curr_terr_index = 0;
	bool x_phase = true;
	for(int z = 0; z < NUM_VER_Z-1; z++) {
	
		for(int x = 0; x < NUM_VER_X-1; x++) {
			// v1: x z
			terrain_vertices[curr_terr_index] = (x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x][z];
			terrain_vertices[curr_terr_index + 2] = (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;

			terrain_vertices[normal_offset + curr_terr_index] = this->terrain_normals[x][z].x; 
			terrain_vertices[normal_offset + curr_terr_index + 1] = this->terrain_normals[x][z].y; 
			terrain_vertices[normal_offset + curr_terr_index + 2] = this->terrain_normals[x][z].z; 
			
			curr_terr_index += 3;
			// v2: x+1 z
			terrain_vertices[curr_terr_index] = ((x+1)*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x+1][z];
			terrain_vertices[curr_terr_index + 2] = (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;

			terrain_vertices[normal_offset + curr_terr_index] = this->terrain_normals[x + 1][z].x; 
			terrain_vertices[normal_offset + curr_terr_index + 1] = this->terrain_normals[x + 1][z].y; 
			terrain_vertices[normal_offset + curr_terr_index + 2] = this->terrain_normals[x + 1][z].z; 
			
			curr_terr_index += 3;
			// v3: x z+1
			terrain_vertices[curr_terr_index] = (x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x][z+1];
			terrain_vertices[curr_terr_index + 2] = ((z+1)*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;
						
			terrain_vertices[normal_offset + curr_terr_index] = this->terrain_normals[x][z + 1].x; 
			terrain_vertices[normal_offset + curr_terr_index + 1] = this->terrain_normals[x][z + 1].y; 
			terrain_vertices[normal_offset + curr_terr_index + 2] = this->terrain_normals[x][z + 1].z; 


			curr_terr_index += 3;

			// v4: x+1 z+1
			terrain_vertices[curr_terr_index] = ((x+1)*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X;
			terrain_vertices[curr_terr_index + 1] = height_map[x+1][z+1];
			terrain_vertices[curr_terr_index + 2] = ((z+1)*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z;
			
			terrain_vertices[normal_offset + curr_terr_index] = this->terrain_normals[x+1][z+1].x; 
			terrain_vertices[normal_offset + curr_terr_index + 1] = this->terrain_normals[x+1][z+1].y; 
			terrain_vertices[normal_offset + curr_terr_index + 2] = this->terrain_normals[x+1][z+1].z; 

			curr_terr_index += 3;
		}
		
			
	}
	
	// generate terrain VAO object
	// 1: number of vertex array objects
	glGenVertexArrays(1, &terrain_vao);
	glBindVertexArray(terrain_vao);

	// create VBO for the VAO
	int num_terrain_vertices = curr_terr_index;
	GLuint terrain_vbo;
	glGenBuffers(1, &terrain_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, terrain_vbo);
	glBufferData(GL_ARRAY_BUFFER, 2 * num_terrain_vertices * sizeof(GLfloat), terrain_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vVertex_attrib);
	glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(vNormal_attrib);
	glVertexAttribPointer(vNormal_attrib, 3, GL_FLOAT, GL_FALSE, 0, (const void*) (normal_offset * sizeof(GLfloat)));

	// // terain vbo
	// GLuint terrain_normals_vbo;
	// glGenBuffers(1, &terrain_normals_vbo);
	// glBindBuffer(GL_ARRAY_BUFFER, terrain_normals_vbo);
	// glBufferData(GL_ARRAY_BUFFER, num_terrain_vertices * sizeof(GLfloat), terrain_vNormals, GL_STATIC_DRAW);

	// glEnableVertexAttribArray(vNormal_attrib);
	// glVertexAttribPointer(vNormal_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); //Unbind the VAO to disable changes outside this function.



}


void Terrain::render(unsigned int &shader_program, unsigned int &terrain_vao) {
	unsigned int vColor_uniform = getUniform(shader_program,"vColor");
	glUniform4f(vColor_uniform, 0.5, 0.5, 0.5, 1.0);

	unsigned int vModel_uniform = getUniform(shader_program,"vModel");
	glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));

	glBindVertexArray(terrain_vao); 
	glDrawArrays(GL_TRIANGLE_STRIP, 0, (NUM_VER_X-1)* (NUM_VER_Z-1) * 4);
}


void Terrain::updateNormals() 
{
	for(int z = 0; z < NUM_VER_Z; z++) {
		for(int x = 0; x < NUM_VER_X; x++) {
			glm::vec3 new_normal = glm::vec3(0.0f);
			glm::vec3 xz_vec = glm::vec3((x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x][z], (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z); 
			int num_faces = 0;
			if(x < NUM_VER_X - 1) {
				// x+1 z
				glm::vec3 B = glm::vec3(((x+1)*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x+1][z], (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z) - xz_vec;

				if(z > 0) {
					// x z-1
					glm::vec3 A = glm::vec3((x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x][z-1], ((z-1)*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z) - xz_vec;
					new_normal = new_normal + glm::cross(B, A);
					// num_faces++;
				}
				
				if(z < NUM_VER_Z - 1) {
					// x z+1
					glm::vec3 A = glm::vec3((x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x][z+1], ((z+1)*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z) - xz_vec;
					new_normal = new_normal +  glm::cross(A, B);
					// num_faces++;					
				}
			}

			if(x > 0) {
				// x-1 z
				glm::vec3 B = glm::vec3(((x-1)*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x-1][z], (z*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z) - xz_vec;

				if(z > 0) {
					// x z-1
					glm::vec3 A = glm::vec3((x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x][z-1], ((z-1)*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z);
					new_normal = new_normal + glm::cross(A, B);
					// num_faces++;
				}
				
				if(z < NUM_VER_Z - 1) {
					// x z+1
					glm::vec3 A = glm::vec3((x*(MAX_X - MIN_X)/(NUM_VER_X - 1)) + MIN_X, height_map[x][z+1], ((z+1)*(MAX_Z - MIN_Z)/(NUM_VER_Z - 1)) + MIN_Z);
					new_normal = new_normal + glm::cross(B, A);
					// num_faces++;					
				}
			}

			new_normal = glm::normalize(new_normal);
			terrain_normals[x][z] = new_normal;
			// printf("%f, %f, %f\n", terrain_normals[x][z].x, terrain_normals[x][z].y, terrain_normals[x][z].z);
			// if(terrain_normals[x][z].y < 0) {
			// 	printf("%d, %d\n", x, z);
			// }
		}
	}
}


void Terrain::addNoise() {
	// std::random_device rd{};
	// std::mt19937 gen{rd()};

	// std::random_device rd{};
	std::mt19937 gen(42);

	// mean, std	
	std::normal_distribution<> d(10, 0.75);

	for(int z = 0; z < NUM_VER_Z; z++) {
		for(int x = 0; x < NUM_VER_X; x++) {
			height_map[x][z] += d(gen);
		}
	}

}