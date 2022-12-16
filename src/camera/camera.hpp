#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <globals.hpp>
#include <utils/utils.hpp>

class Camera
{
private:
    glm::vec3 camPos, camFront, camUp;
    glm::mat4 view_t, projection_t;
    const float SENSITIVITY = 0.1f;
    const float SPEED = 50.0f;
    float fov, near, far;
    float pitch,yaw;
    bool dragging, first;
    double prevX, prevY;
    void mouse_motion(double xpos, double ypos);
    void process_keys(GLFWwindow *window, float deltaTime);

public:
    void process_input(GLFWwindow *window, float deltaTime);
    Camera(glm::vec3 pos, glm::vec3 look_at, glm::vec3 up, float _fov, float near_clip, 
    float far_clip, GLFWwindow *window) : camPos(pos), camFront(glm::normalize(look_at - pos)), camUp(up), fov(_fov), near(near_clip), far(far_clip)
    {
        dragging = false;
        first = true;
        prevX = (GLfloat) SCREEN_W/2;
        prevY = (GLfloat)SCREEN_H / 2;
        pitch = -35.1519f;
        yaw = -40.6623f;
    }

    void setViewTransformation(unsigned int &shaderProgram);
    void setProjectionTransformation(unsigned int &shaderProgram);
    void setCamPos(unsigned int &shaderProgram);
};
#endif