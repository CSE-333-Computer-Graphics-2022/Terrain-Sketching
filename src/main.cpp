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
#include <stroke/shadow/shadow.hpp>
#include <ui/ui.hpp>


int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H);
	ImGuiIO &io = ImGui::GetIO(); // Create IO
	UI ui = UI();
	

	float lastTime = 0;
	float deltaTime = 0;

	unsigned int shader_program = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	//Get handle to color variable in shader
	glUseProgram(shader_program);

	Camera cam = Camera(glm::vec3(-500.0f, 300.0f, 350.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
						45.0f, 0.1f, 10000.0f, shader_program, window);

	Terrain *base_terrain = new Terrain(100, 100, glm::vec3(0, 0, 0), 500, 500);
	base_terrain->setup(shader_program);

	unsigned int lightPosWorld_uniform = getUniform(shader_program, "lightPosWorld");
	glUniform3f(lightPosWorld_uniform, 10, 20, 0);
	unsigned int lightColor_uniform = getUniform(shader_program, "lightColor");
	glUniform3f(lightColor_uniform, 1, 1, 1);

	while (!glfwWindowShouldClose(window))
	{

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ui.sidebar();
		}

		glUseProgram(shader_program);

		float currTime = static_cast<float>(glfwGetTime());
		deltaTime = currTime - lastTime;
		lastTime = currTime;

		if(!io.WantCaptureMouse && ui.get_mode() == FLY)
		{
			cam.process_input(window, deltaTime);
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(WHITE.x, WHITE.y, WHITE.z, WHITE.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// render terrain
		base_terrain->draw(shader_program);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	cleanup(window);

	return 0;
}

