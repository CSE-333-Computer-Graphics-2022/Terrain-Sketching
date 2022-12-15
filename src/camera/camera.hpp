#ifndef CAMERA_H
#define CAMERA_H
#include <utils.hpp>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Camera
{
private:
    glm::vec3 camPos, camFront, camUp;
    glm::mat4 view_t, projection_t;
    static Camera *instance;
    static constexpr float SENSITIVITY = 0.1f;
    static constexpr float SPEED = 50.0f;
    unsigned int shaderProgram;
    float fov, near, far;
    static float pitch,yaw;
    static bool dragging;
    static double prevX, prevY;
    static bool firstMouse;
    static void mouse_motion_callback(GLFWwindow *window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

public:
    static void process_keys(GLFWwindow *window, float deltaTime);
    Camera(glm::vec3 pos, glm::vec3 look_at, glm::vec3 up, float _fov, float near_clip, 
    float far_clip, unsigned int &shader_program, GLFWwindow *window) : camPos(pos), camFront(glm::normalize(look_at - pos)), camUp(up), fov(_fov), near(near_clip), far(far_clip), shaderProgram(shader_program)
    {
        setupViewTransformation();
        setupProjectionTransformation();
        // camera pos = eye pos in shader
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetCursorPosCallback(window, mouse_motion_callback);
        instance = this;
    }

    void setupViewTransformation();
    void setupProjectionTransformation();
};
#endif