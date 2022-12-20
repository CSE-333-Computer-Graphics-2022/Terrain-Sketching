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
#include <mode/regionmode/regionmode.hpp>
#include <mode/aerialmode/aerialmode.hpp>
#include <terrain/terrain.hpp>
#include <ui/ui.hpp>

int main(int, char **)
{
	// Setup window
	GLFWwindow *window = setupWindow(SCREEN_W, SCREEN_H);
	ImGuiIO &io = ImGui::GetIO(); // Create IO
	UI ui = UI();

	double last_time = 0;
	double delta_time = 0;

	//Simple Blinn Phong Shader
	unsigned int shader_program = createProgram("../shaders/vshader.vs", "../shaders/fshader.fs");
	//Shader for thick lines. Taken from https://github.com/vicrucann/shader-3dcurve
	unsigned int shader_program_2 = createProgram("../shaders/polyline.vert", "../shaders/polyline.geom", "../shaders/polyline.frag");


	Camera *cam = new Camera(glm::vec3(-500.0f, 300.0f, 350.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
							 45.0f, 0.1f, 10000.0f, window);

	//Creating a base_terrain of 100*100 vertices at 0,0,0 with width and depth as 500.0
	Terrain *base_terrain = new Terrain(100, 100, glm::vec3(0, 0, 0), (double)500.0, (double)500.0);

	//Setting up terrain
	glUseProgram(shader_program);
	base_terrain->setup(shader_program);

	//Lighting for shader 1.
	unsigned int lightPosWorld_uniform = getUniform(shader_program, "lightPosWorld");
	glUniform3f(lightPosWorld_uniform, 100, 200, 100);
	unsigned int lightColor_uniform = getUniform(shader_program, "lightColor");
	glUniform3f(lightColor_uniform, 1, 1, 1);

	cam->setProjectionTransformation(shader_program);
	cam->setViewTransformation(shader_program);

	//Initializing different sketch modes.
	SilhouetteMode *smode = new SilhouetteMode(cam,base_terrain,shader_program_2);
	RegionMode *rmode = new RegionMode(cam,base_terrain,shader_program_2);
	AerialMode *amode = new AerialMode(cam,base_terrain,shader_program_2);

	//Setting up thick line shader.
	glUseProgram(shader_program_2);
	unsigned int thicknessUniform = getUniform(shader_program_2, "Thickness");
	glUniform1f(thicknessUniform, 2.5);
	unsigned int miterLimitUniform = getUniform(shader_program_2, "MiterLimit");
	glUniform1f(miterLimitUniform, 0.5);
	unsigned int viewPortUniform = getUniform(shader_program_2, "Viewport");
	glUniform2f(viewPortUniform, (GLdouble)SCREEN_H, (GLdouble)SCREEN_W);

	cam->setProjectionTransformation(shader_program_2);
	cam->setViewTransformation(shader_program_2);


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	while (!glfwWindowShouldClose(window))
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ui.sidebar();
		}

		double curr_time = static_cast<double>(glfwGetTime());
		delta_time = curr_time - last_time;
		last_time = curr_time;

		if (!io.WantCaptureMouse)
		{
			// captures the input and calls the relevant input_process function of the selected mode
			switch (ui.get_mode())
			{
			case SILHOUETTE:
				smode->process_input(window, delta_time);
				break;

			case REGION:
				rmode->process_input(window,delta_time);
				break;

			case AERIAL:
				amode->process_input(window,delta_time);
				break;

			default: // camera fly mode
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
		
		// render sketches of the active mode
		glUseProgram(shader_program_2);
		switch (ui.get_mode())
		{
		case SILHOUETTE:
			smode->drawSilhouette();
			break;
		case REGION:
			rmode->drawRegion();
			break;

		case AERIAL:
			amode->drawAerial();
			break;

		default:
			break;
		}
		
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	cleanup(window);

	return 0;
}
