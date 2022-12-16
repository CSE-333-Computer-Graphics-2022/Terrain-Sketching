#include "camera.hpp"


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

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        deltaTime = 10 * deltaTime;
    bool mod = glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        if (mod)
            camPos += deltaTime * SPEED * glm::vec3(0.0f, 1.0f, 0.0f);
        else
            camPos += deltaTime * SPEED * camFront;
        setupViewTransformation();
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        if (mod)
            camPos -= deltaTime * SPEED * glm::vec3(0.0f, 1.0f, 0.0f);
        else
            camPos -= deltaTime * SPEED * camFront;
        setupViewTransformation();
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camPos -= deltaTime * SPEED * glm::normalize(glm::cross(camFront, camUp));
        setupViewTransformation();
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camPos += deltaTime * SPEED * glm::normalize(glm::cross(camFront, camUp));
        setupViewTransformation();
    }
}

void Camera::mouse_motion(double xpos, double ypos)
{
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
        camFront = glm::normalize(direction);
        setupViewTransformation();
    }
}

void Camera::process_input(GLFWwindow *window, float deltaTime)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        if(!first) mouse_motion(xpos,ypos);
        else
        {
            prevX = xpos;
            prevY = ypos;
            first = false;
        }
        dragging = true;
    }
    else
        first = true;
    process_keys(window, deltaTime);
}