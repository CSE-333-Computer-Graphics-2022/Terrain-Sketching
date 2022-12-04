#include "terrain.h"
#include <random>

int Terrain::coordToIndex(float x, float z)
{
	int idx = ((x - MIN_X) / XF) * NUM_Z + (z - MIN_Z) / ZF;
	if (idx < 0 || idx >= NUM_V)
		return -1;
	return idx;
}

void Terrain::updateNormals(float x, float z)
{
	int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	int dz[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int index = coordToIndex(x, z);
	if (index == -1)
		return;
	int h = index / NUM_Z;

	glm::vec3 res = glm::vec3();
	glm::vec3 prev = glm::vec3();
	bool first = true;
	for (int i = 0; i < 8; i++)
	{
		if ((i == 1 || i == 7) && (h % 2))
			continue;
		if ((i == 3 || i == 5) && (h % 2 == 0))
			continue;
		int idx = index + NUM_Z * dx[i] + dz[i];
		if (idx < 0 || idx >= NUM_V || abs(idx % NUM_Z - index % NUM_Z) > 1)
		{
			first = true;
			continue;
		}
		glm::vec3 curr = glm::vec3(height_map[idx * DIM], height_map[idx * DIM + 1], height_map[idx * DIM + 2]) - glm::vec3(x, height_map[index * DIM + 1], z);
		if (first)
		{
			first = false;
			prev = curr;
		}
		else
		{
			res += glm::cross(prev, curr);

			prev = curr;
		}
	}
	res = glm::normalize(res);

	normal_map[index * DIM] = res.x;
	normal_map[index * DIM + 1] = res.y;
	normal_map[index * DIM + 2] = res.z;
}

void Terrain::setupTerrain()
{
	//Populating height_map
	int index = 0;
	for (int x = 0; x < NUM_X; x++)
	{
		for (int z = 0; z < NUM_Z; z++)
		{
			//x y z vertex coord
			height_map[index++] = x * XF + MIN_X;
			height_map[index++] = 1.0f;
			height_map[index++] = z * ZF + MIN_Z;
		}
	}

	//Populating normal_map
	index = 0;
	for (; index < NUM_V; index++)
		updateNormals(height_map[index * DIM], height_map[index * DIM + 2]);

			for(int i = 0; i < NUM_V; i++)
	{
		height_map[NUM_V*DIM + i*DIM] = normal_map[i*DIM];
		height_map[NUM_V*DIM + i*DIM+1] = normal_map[i*DIM+1];
		height_map[NUM_V*DIM + i*DIM+2] = normal_map[i*DIM+2];
	}

	//Populating index_map
	index = 0;
	for (int h = 0; h < NUM_X - 1; h++)
	{
		for (int v = 0; v < NUM_Z; v++)
		{
			if (h % 2)
			{
				index_map[index++] = (h + 1) * NUM_Z - v - 1;
				index_map[index++] = (h + 2) * NUM_Z - v - 1;
			}
			else
			{
				index_map[index++] = h * NUM_Z + v;
				index_map[index++] = (h + 1) * NUM_Z + v;
			}
		}
	}
}

void Terrain::addNoise()
{
	std::mt19937 gen(42);
	// mean, std
	std::normal_distribution<> d(10, 1);

	for (int i = 0; i < NUM_V; i++)

		height_map[i * DIM + 1] += d(gen);
	for (int i = 0; i < NUM_V; i++)
		updateNormals(height_map[i * DIM], height_map[i * DIM + 2]);
	for(int i = 0; i < NUM_V; i++)
	{
		height_map[NUM_V*DIM + i*DIM] = normal_map[i*DIM];
		height_map[NUM_V*DIM + i*DIM+1] = normal_map[i*DIM+1];
		height_map[NUM_V*DIM + i*DIM+2] = normal_map[i*DIM+2];
	}
}

void Terrain::setup(unsigned int &shader_program)
{
	vao = new GLuint;
	vbo = new GLuint[2];

	setupTerrain();
	addNoise();

	glUseProgram(shader_program);
	unsigned int vVertex_attrib = getAttrib(shader_program, "vVertex");
	unsigned int vNormal_attrib = getAttrib(shader_program, "vNormal");

	// generate terrain VAO object
	// 1: number of vertex array objects
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);

	// create VBO for the VAO
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, 2*NUM_V * DIM * sizeof(GLfloat), height_map, GL_STATIC_DRAW);

	glEnableVertexAttribArray(vVertex_attrib);
	glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(vNormal_attrib);
	glVertexAttribPointer(vNormal_attrib, 3, GL_FLOAT, GL_FALSE, 0, (void *)(NUM_V*DIM*sizeof(float)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); //Unbind the VAO to disable changes outside this function.
}

void Terrain::draw(unsigned int &shader_program)
{
	unsigned int vColor_uniform = getUniform(shader_program, "vColor");
	glUniform4f(vColor_uniform, 0.5, 0.5, 0.5, 1.0);

	unsigned int vModel_uniform = getUniform(shader_program, "vModel");
	glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));

	glBindVertexArray(*vao);
	glDrawElements(GL_TRIANGLE_STRIP, NUM_I, GL_UNSIGNED_INT, index_map);

	// glUniform4f(vColor_uniform, 1.0, 0.0, 0.0, 1.0);
	// glDrawElements(GL_LINE_STRIP, NUM_I, GL_UNSIGNED_INT, index_map);
}