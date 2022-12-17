#include "silhouettemode.hpp"
#include <globals.hpp>

void SilhouetteMode::process_input(GLFWwindow *window, float delta_time)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double x_pos, y_pos;
        glfwGetCursorPos(window, &x_pos, &y_pos);
        //Get x,y,z add it to the stroke to render
        int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
        glm::vec3 pos = getWorldPos(x_pos, y_pos,display_w,display_h);
        stroke->addSilhouetteVertex(pos);
        drawing = true;
    }
    else
    {
        //Done with stroke, render its shadow and boundary and start new stroke.
        drawing = false;
    }
}
glm::vec3 SilhouetteMode::getWorldPos(double x, double y, int display_w, int display_h)
{
    glm::mat4 invVP = glm::inverse(cam->getProjection()*cam->getView());
    glm::vec4 near = glm::vec4((x/(display_w/2.0) - 1.0),-1*(y/(display_h/2.0) - 1.0), -1, 1.0);
    glm::vec4 far = glm::vec4((x/(display_w/2.0) - 1.0),-1*(y/(display_h/2.0) - 1.0), 1, 1.0);
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

