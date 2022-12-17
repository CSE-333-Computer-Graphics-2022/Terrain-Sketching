#include "silhouettemode.hpp"
#include <globals.hpp>

void SilhouetteMode::process_input(GLFWwindow *window, float delta_time)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double x_pos, y_pos;
        glfwGetCursorPos(window, &x_pos, &y_pos);
        //Get x,y,z add it to the stroke to render
        glm::vec3 pos = getWorldPos(x_pos, y_pos);
        stroke->addSilhouetteVertex(pos);
        drawing = true;
    }
    else
    {
        //Done with stroke, render its shadow and boundary and start new stroke.
        drawing = false;
    }
}
glm::vec3 SilhouetteMode::getWorldPos(double x, double y)
{
    glm::mat4 invVP = glm::inverse(cam->getProjection()*cam->getView());
    glm::vec4 near = glm::vec4((x/(SCREEN_W/2.0) - 1.0),-1*(y/(SCREEN_H/2.0) - 1.0), -1, 1.0);
    glm::vec4 far = glm::vec4((x/(SCREEN_W/2.0) - 1.0),-1*(y/(SCREEN_H/2.0) - 1.0), 1, 1.0);
    glm::vec4 nearR = invVP*near;
    glm::vec4 farR = invVP*far;
    nearR /= nearR.w;
    farR /= farR.w;
    glm::vec3 dir = glm::normalize(glm::vec3(farR - nearR));
    glm::vec3 n = glm::normalize(glm::vec3(cam->getOrigin() - glm::vec3(0,0,0)));
    n.y = 0;
    float t = glm::dot((glm::vec3(0,0,0) - glm::vec3(nearR)),n)/glm::dot(dir,n);
    return glm::vec3(nearR) + t*dir;
}

