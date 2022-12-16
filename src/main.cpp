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

	unsigned int shaderProgram = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	unsigned int shaderProgram2 = createProgram("../shaders/polyline.vert", "../shaders/polyline.geom", "../shaders/polyline.frag");

	Camera cam = Camera(glm::vec3(-500.0f, 300.0f, 350.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
						45.0f, 0.1f, 10000.0f, window);

	Terrain *base_terrain = new Terrain(100, 100, glm::vec3(0, 0, 0), 500, 500);

	glUseProgram(shaderProgram);
	base_terrain->setup(shaderProgram);
	unsigned int lightPosWorld_uniform = getUniform(shaderProgram, "lightPosWorld");
	glUniform3f(lightPosWorld_uniform, 10, 20, 0);
	unsigned int lightColor_uniform = getUniform(shaderProgram, "lightColor");
	glUniform3f(lightColor_uniform, 1, 1, 1);

	cam.setProjectionTransformation(shaderProgram);
	cam.setViewTransformation(shaderProgram);

	glUseProgram(shaderProgram2);
	unsigned int thicknessUniform = getUniform(shaderProgram2, "Thickness");
	glUniform1f(thicknessUniform, 2.5);
	unsigned int miterLimitUniform = getUniform(shaderProgram2, "MiterLimit");
	glUniform1f(miterLimitUniform, 0.5);
	unsigned int viewPortUniform = getUniform(shaderProgram2, "Viewport");
	glUniform2f(viewPortUniform, (GLfloat)SCREEN_H, (GLfloat)SCREEN_W);

	cam.setProjectionTransformation(shaderProgram2);
	cam.setViewTransformation(shaderProgram2);

	Sillhouette *test_sillhouette = new Sillhouette(base_terrain);
	test_sillhouette->setup(shaderProgram2);
	Shadow *test_shadow = test_sillhouette->getShadow();
	test_shadow->setup(shaderProgram2);
	Boundary *test_boundary = test_sillhouette->getBoundary();
	test_boundary->setup(shaderProgram2);

	while (!glfwWindowShouldClose(window))
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ui.sidebar();
		}

		float currTime = static_cast<float>(glfwGetTime());
		deltaTime = currTime - lastTime;
		lastTime = currTime;

		if (!io.WantCaptureMouse && ui.get_mode() == FLY)
		{
			cam.process_input(window, deltaTime);
			
			cam.setCamPos(shaderProgram);
			cam.setViewTransformation(shaderProgram);

			cam.setViewTransformation(shaderProgram2);
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(WHITE.x, WHITE.y, WHITE.z, WHITE.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		// render terrain
		glUseProgram(shaderProgram);
		base_terrain->draw(shaderProgram);

		// render stroke
		glUseProgram(shaderProgram2);
		test_sillhouette->draw(shaderProgram2);
		test_shadow->draw(shaderProgram2);
		test_boundary->draw(shaderProgram2);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	cleanup(window);

	return 0;
}
