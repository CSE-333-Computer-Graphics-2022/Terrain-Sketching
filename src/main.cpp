#include "utils/utils.hpp"
#include "globals.hpp"
#include "drawable.hpp"
#include <camera/camera.hpp>

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include <terrain/terrain.hpp>
#include <stroke/sillhouette/sillhouette.hpp>



int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H);
	ImGuiIO &io = ImGui::GetIO(); // Create IO

	unsigned int shader_program = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	//Get handle to color variable in shader
	glUseProgram(shader_program);

	// Camera cam = Camera(glm::vec3(80.0f,80.0f,80.0f),glm::vec3(0.0f,0.0f,0.0f),45.0f,0.1f,1000.0f,shader_program);
	Camera cam = Camera(glm::vec3(100.0f,80.0f,0.0f),glm::vec3(0.0f,0.0f,0.0f),45.0f,0.1f,1000.0f,shader_program);

	Terrain *base_terrain = new Terrain(100,100,glm::vec3(0,0,0),200,200);
	base_terrain->setup(shader_program);

	Sillhouette *test_sillhouette = new Sillhouette();
	test_sillhouette->setup(shader_program);
	
	unsigned int lightPosWorld_uniform = getUniform(shader_program,"lightPosWorld");
	glUniform3f(lightPosWorld_uniform, 10, 20, 0);
	unsigned int lightColor_uniform = getUniform(shader_program,"lightColor");
	glUniform3f(lightColor_uniform, 1, 1, 1);	

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
		base_terrain->draw(shader_program);
		// render stroke
		test_sillhouette->draw(shader_program);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	// Cleanup
	cleanup(window);

	return 0;
}