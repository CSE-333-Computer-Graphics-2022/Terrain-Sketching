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

#include <mode/silhouettemode/silhouettemode.hpp>
#include <terrain/terrain.hpp>
#include <ui/ui.hpp>

int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H);
	ImGuiIO &io = ImGui::GetIO(); // Create IO
	UI ui = UI();

	float last_time = 0;
	float delta_time = 0;

	unsigned int shader_program = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	unsigned int shader_program_2 = createProgram("../shaders/polyline.vert", "../shaders/polyline.geom", "../shaders/polyline.frag");

	Camera *cam = new Camera(glm::vec3(-500.0f, 300.0f, 350.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
							 45.0f, 0.1f, 10000.0f, window);

	Terrain *base_terrain = new Terrain(100, 100, glm::vec3(0, 0, 0), 500, 500);

	glUseProgram(shader_program);
	base_terrain->setup(shader_program);
	unsigned int lightPosWorld_uniform = getUniform(shader_program, "lightPosWorld");
	glUniform3f(lightPosWorld_uniform, 10, 20, 0);
	unsigned int lightColor_uniform = getUniform(shader_program, "lightColor");
	glUniform3f(lightColor_uniform, 1, 1, 1);

	cam->setProjectionTransformation(shader_program);
	cam->setViewTransformation(shader_program);

	SilhouetteMode *smode = new SilhouetteMode(cam,base_terrain);
	glUseProgram(shader_program_2);
	unsigned int thicknessUniform = getUniform(shader_program_2, "Thickness");
	glUniform1f(thicknessUniform, 2.5);
	unsigned int miterLimitUniform = getUniform(shader_program_2, "MiterLimit");
	glUniform1f(miterLimitUniform, 0.5);
	unsigned int viewPortUniform = getUniform(shader_program_2, "Viewport");
	glUniform2f(viewPortUniform, (GLfloat)SCREEN_H, (GLfloat)SCREEN_W);

	cam->setProjectionTransformation(shader_program_2);
	cam->setViewTransformation(shader_program_2);

	smode->setupSilhouette(shader_program_2);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	// glEnable(GL_CULL_FACE);
	while (!glfwWindowShouldClose(window))
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ui.sidebar();
		}

		float curr_time = static_cast<float>(glfwGetTime());
		delta_time = curr_time - last_time;
		last_time = curr_time;

		if (!io.WantCaptureMouse)
		{
			switch (ui.get_mode())
			{
			case SILHOUETTE:
				smode->process_input(window, delta_time);
				break;

			default:
				cam->process_input(window, delta_time);
				cam->setCamPos(shader_program);
				cam->setViewTransformation(shader_program);
				cam->setViewTransformation(shader_program_2);
				break;
			}
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(WHITE.x, WHITE.y, WHITE.z, WHITE.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// render terrain
		glUseProgram(shader_program);
		base_terrain->draw(shader_program);

		glUseProgram(shader_program_2);
			smode->drawSilhouette(shader_program_2);
		// switch (ui.get_mode())
		// {
		// case SILHOUETTE:
			// smode->drawSilhouette(shader_program_2);
			// break;
// 
		// default:
			// break;
		// }
// 
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	cleanup(window);

	return 0;
}
