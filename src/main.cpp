#include "utils/utils.h"
#include "globals.h"

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include <terrain/terrain.h>

GLint vModel_uniform, vView_uniform, vProjection_uniform;
GLint vColor_uniform;
glm::mat4 modelT, viewT, projectionT; //The model, view and projection transformations
glm::vec4 camPosition, lookAtPosition, camPositionView;
glm::mat4x4 camSpaceT = glm::identity<glm::mat4x4>();
char textKeyStatus[256];

void createCubeObject(unsigned int &, unsigned int &);
void createAxesLine(unsigned int &, unsigned int &);

void setupModelTransformationCube(unsigned int &);
void setupModelTransformationAxis(unsigned int &program, float rot_angle, glm::vec3 rot_axis);
void setupViewTransformation(unsigned int &);
void setupProjectionTransformation(unsigned int &);
void setupProjectionTransformationO(unsigned int &);


int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H);
	ImGuiIO &io = ImGui::GetIO(); // Create IO
	ImVec4 clearColor = WHITE;
	camPosition = glm::vec4(20.0, 40.0, 80.0, 1.0);
	lookAtPosition = glm::vec4(0.0, 0.0, 0.0, 1.0);

	unsigned int shader_program = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	//Get handle to color variable in shader
	vColor_uniform = getUniform(shader_program,"vColor");
	glUseProgram(shader_program);

	// Modelling transformation is setup in the display loop
	setupViewTransformation(shader_program);
	setupProjectionTransformation(shader_program);

	unsigned int terrain_vao;
	Terrain base_terrain(100, 100, glm::vec3(0, 0, 0), 10, 10);
	base_terrain.setupTerrain(shader_program, terrain_vao);

	createCubeObject(shader_program, terrain_vao);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glUseProgram(shader_program);

		

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// render terrain 
		base_terrain.render(shader_program, terrain_vao);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	// Cleanup
	cleanup(window);

	return 0;
}

void createCubeObject(unsigned int &program, unsigned int &cube_VAO)
{
	glUseProgram(program);

	//Bind shader variables
	int vVertex_attrib = glGetAttribLocation(program, "vVertex");
	if (vVertex_attrib == -1)
	{
		fprintf(stderr, "Could not bind location: vVertex\n");
		exit(0);
	}

	//Cube data
	GLfloat cube_vertices[] = {10, 10, -10, -10, 10, -10, -10, -10, -10, 10, -10, -10, //Front
							   10, 10, 10, -10, 10, 10, -10, -10, 10, 10, -10, 10};	   //Back
	GLushort cube_indices[] = {
		0, 1, 2, 0, 2, 3, //Front
		4, 7, 5, 5, 7, 6, //Back
		1, 6, 2, 1, 5, 6, //Left
		0, 3, 4, 4, 7, 3, //Right
		0, 4, 1, 4, 5, 1, //Top
		2, 6, 3, 3, 6, 7  //Bottom
	};

	//Generate VAO object
	glGenVertexArrays(1, &cube_VAO);
	glBindVertexArray(cube_VAO);

	//Create VBOs for the VAO
	//Position information (data + format)
	int nVertices = (6 * 2) * 3; //(6 faces) * (2 triangles each) * (3 vertices each)
	GLfloat *expanded_vertices = new GLfloat[nVertices * 3];
	for (int i = 0; i < nVertices; i++)
	{
		expanded_vertices[i * 3] = cube_vertices[cube_indices[i] * 3];
		expanded_vertices[i * 3 + 1] = cube_vertices[cube_indices[i] * 3 + 1];
		expanded_vertices[i * 3 + 2] = cube_vertices[cube_indices[i] * 3 + 2];
	}
	GLuint vertex_VBO;
	glGenBuffers(1, &vertex_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
	glBufferData(GL_ARRAY_BUFFER, nVertices * 3 * sizeof(GLfloat), expanded_vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(vVertex_attrib);
	glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
	delete[] expanded_vertices;

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); //Unbind the VAO to disable changes outside this function.
}

void createAxesLine(unsigned int &program, unsigned int &axis_VAO)
{
	glUseProgram(program);

	//Bind shader variables
	int vVertex_attrib_position = glGetAttribLocation(program, "vVertex");
	if (vVertex_attrib_position == -1)
	{
		fprintf(stderr, "Could not bind location: vVertex\n");
		exit(0);
	}

	//Axes data
	GLfloat axis_vertices[] = {0, 0, 0, 20, 0, 0}; //X-axis
	glGenVertexArrays(1, &axis_VAO);
	glBindVertexArray(axis_VAO);

	//Create VBO for the VAO
	int nVertices = 2; // 2 vertices
	GLuint vertex_VBO;
	glGenBuffers(1, &vertex_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
	glBufferData(GL_ARRAY_BUFFER, nVertices * 3 * sizeof(GLfloat), axis_vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(vVertex_attrib_position);
	glVertexAttribPointer(vVertex_attrib_position, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); //Unbind the VAO to disable changes outside this function.
}

void setupModelTransformationCube(unsigned int &program)
{
	//Modelling transformations (Model -> World coordinates)
	modelT = glm::scale(glm::mat4(1.0f), glm::vec3(1.0, 2.0, 1.0));
	modelT = glm::translate(modelT, glm::vec3(0.0f, 10.0f, 0.0f));

	//Pass on the modelling matrix to the vertex shader
	glUseProgram(program);
	vModel_uniform = glGetUniformLocation(program, "vModel");
	if (vModel_uniform == -1)
	{
		fprintf(stderr, "Could not bind location: vModel\n");
		exit(0);
	}
	glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));
}

void setupModelTransformationAxis(unsigned int &program, float rot_angle, glm::vec3 rot_axis)
{
	//Modelling transformations (Model -> World coordinates)
	modelT = glm::rotate(glm::mat4(1.0f), rot_angle, rot_axis);

	//Pass on the modelling matrix to the vertex shader
	glUseProgram(program);
	vModel_uniform = glGetUniformLocation(program, "vModel");
	if (vModel_uniform == -1)
	{
		fprintf(stderr, "Could not bind location: vModel\n");
		exit(0);
	}
	glUniformMatrix4fv(vModel_uniform, 1, GL_FALSE, glm::value_ptr(modelT));
}

void setupViewTransformation(unsigned int &program)
{
	//Viewing transformations (World -> Camera coordinates
	viewT = glm::lookAt(glm::vec3(camPosition), glm::vec3(lookAtPosition), glm::vec3(0.0, 1.0, 0.0));
	viewT = camSpaceT * viewT;
	auto matInverse = glm::inverse(viewT);
	camPositionView = matInverse[3];
	//Pass-on the viewing matrix to the vertex shader
	glUseProgram(program);
	vView_uniform = getUniform(program, "vView");
	glUniformMatrix4fv(vView_uniform, 1, GL_FALSE, glm::value_ptr(viewT));
}

void setupProjectionTransformation(unsigned int &program)
{
	//Projection transformation
	projectionT = glm::perspective(45.0f, (GLfloat)SCREEN_W / (GLfloat)SCREEN_H, 0.1f, 1000.0f);

	//Pass on the projection matrix to the vertex shader
	glUseProgram(program);
	vProjection_uniform = getUniform(program, "vProjection");
	glUniformMatrix4fv(vProjection_uniform, 1, GL_FALSE, glm::value_ptr(projectionT));
}

void setupProjectionTransformationO(unsigned int &program)
{
	//Projection transformation
	GLfloat scale = 0.15f - 0.002f * camSpaceT[3][2];
	GLfloat left = -(scale * (GLfloat)SCREEN_W) / 2.0f;
	GLfloat right = scale * (GLfloat)SCREEN_W / 2.0f;
	GLfloat bottom = -(scale * (GLfloat)SCREEN_H) / 2.0f;
	GLfloat top = scale * (GLfloat)SCREEN_H / 2.0f;
	projectionT = glm::ortho(left, right, bottom, top, 0.01f, 1000.0f);

	//Pass on the projection matrix to the vertex shader
	glUseProgram(program);
	vProjection_uniform = getUniform(program, "vProjection");
	glUniformMatrix4fv(vProjection_uniform, 1, GL_FALSE, glm::value_ptr(projectionT));
}
