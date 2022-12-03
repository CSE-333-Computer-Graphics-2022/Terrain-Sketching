#include "utils/utils.h"
#include "globals.h"
#include <camera/camera.h>

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include <terrain/terrain.h>



int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H);
	ImGuiIO &io = ImGui::GetIO(); // Create IO

	unsigned int shader_program = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	//Get handle to color variable in shader
	glUseProgram(shader_program);

	Camera cam = Camera(glm::vec3(80.0f,80.0f,80.0f),glm::vec3(0.0f,0.0f,0.0f),45.0f,0.1f,1000.0f,shader_program);
	unsigned int terrain_vao;
	Terrain base_terrain(100, 100, glm::vec3(0, 0, 0), 200, 200);
	base_terrain.bindTerrain(shader_program, terrain_vao);
	unsigned int lightPosWorld = getUniform(shader_program,"lightPosWorld");
	glUniform3f(lightPosWorld, 10, 20, 0);
	unsigned int lightColor = getUniform(shader_program,"lightColor");
	glUniform3f(lightColor, 1, 1, 1);	

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
		glClearColor(WHITE.x, WHITE.y, WHITE.z, WHITE.w);
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