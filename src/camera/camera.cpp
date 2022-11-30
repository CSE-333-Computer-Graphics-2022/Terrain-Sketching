#include "camera.h"
#include <utils/utils.h>
#include <globals.h>

void Camera::setupViewTransformation(unsigned int &shader_program)
{

    view_t = glm::lookAt(glm::vec3(cam_position), glm::vec3(look_atPosition), glm::vec3(0.0, 1.0, 0.0));
    glUseProgram(shader_program);
    unsigned int vView_uniform = getUniform(shader_program, "vView");
    glUniformMatrix4fv(vView_uniform, 1, GL_FALSE, glm::value_ptr(view_t));
}

void Camera::setupProjectionTransformation(unsigned int &shader_program)
{

	projection_t = glm::perspective(fov, (GLfloat)SCREEN_W / (GLfloat)SCREEN_H, near, far);
	glUseProgram(shader_program);
	unsigned int vProjection_uniform = getUniform(shader_program, "vProjection");
	glUniformMatrix4fv(vProjection_uniform, 1, GL_FALSE, glm::value_ptr(projection_t));
}