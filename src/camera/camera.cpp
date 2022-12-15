#include "camera.hpp"
#include <utils/utils.hpp>
#include <globals.hpp>

bool Camera::dragging = false, Camera::firstMouse = false;
double Camera::prevX = (GLfloat)SCREEN_W / 2;
double Camera::prevY = (GLfloat)SCREEN_H / 2;
float Camera::pitch = -35.1519f, Camera::yaw = -40.6623f;
Camera *Camera::instance;

void Camera::setupViewTransformation()
{
    unsigned int eye_pos_uniform = getUniform(shaderProgram, "eye_pos");
    glUniform3f(eye_pos_uniform, camPos.x, camPos.y, camPos.z);
    view_t = glm::lookAt(glm::vec3(camPos), glm::vec3(camPos + camFront), camUp);
    glUseProgram(shaderProgram);
    unsigned int vView_uniform = getUniform(shaderProgram, "vView");
    glUniformMatrix4fv(vView_uniform, 1, GL_FALSE, glm::value_ptr(view_t));
}

void Camera::setupProjectionTransformation()
{

    projection_t = glm::perspective(fov, (GLfloat)SCREEN_W / (GLfloat)SCREEN_H, near, far);
    glUseProgram(shaderProgram);
    unsigned int vProjection_uniform = getUniform(shaderProgram, "vProjection");
    glUniformMatrix4fv(vProjection_uniform, 1, GL_FALSE, glm::value_ptr(projection_t));
}

void Camera::process_keys(GLFWwindow *window, float deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            instance->camPos += 10 * deltaTime * SPEED * instance->camFront;
        else
            instance->camPos += deltaTime * SPEED * instance->camFront;
        instance->setupViewTransformation();
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            instance->camPos -= 10 * deltaTime * SPEED * instance->camFront;
        else
            instance->camPos -= deltaTime * SPEED * instance->camFront;
        instance->setupViewTransformation();
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            instance->camPos -= 10 * deltaTime * SPEED * glm::normalize(glm::cross(instance->camFront, instance->camUp));
        else
            instance->camPos -= deltaTime * SPEED * glm::normalize(glm::cross(instance->camFront, instance->camUp));
        instance->setupViewTransformation();
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            instance->camPos += 10 * deltaTime * SPEED * glm::normalize(glm::cross(instance->camFront, instance->camUp));
        else
            instance->camPos += deltaTime * SPEED * glm::normalize(glm::cross(instance->camFront, instance->camUp));
        instance->setupViewTransformation();
    }
}

void Camera::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_RELEASE)
            dragging = false;
        else if (action == GLFW_PRESS)
        {

            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            prevX = xpos;
            prevY = ypos;
            dragging = true;
        }
    }
}

void Camera::mouse_motion_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMouse) // initially set to true
    {
        prevX = xpos;
        prevY = ypos;
        firstMouse = false;
    }
    if (dragging)
    {
        //Rotating
        float xoffset = xpos - prevX;
        float yoffset = prevY - ypos;
        prevX = xpos;
        prevY = ypos;

        xoffset *= SENSITIVITY;
        yoffset *= SENSITIVITY;

        yaw += xoffset;
        pitch += yoffset;

        //clips to -89 to 89
        pitch = std::max(std::min(pitch, 89.0f), -89.0f);

        glm::vec3 direction;
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        instance->camFront = glm::normalize(direction);
        instance->setupViewTransformation();
    }
}