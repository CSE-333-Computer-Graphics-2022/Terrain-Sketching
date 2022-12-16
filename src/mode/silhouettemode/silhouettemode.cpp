#include "silhouettemode.hpp"

void SilhouetteMode::process_input(GLFWwindow *window, float delta_time)
{
    if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double x_pos, y_pos;
        glfwGetCursorPos(window,&x_pos,&y_pos);
        drawing = true;
    }
    else
    {
        drawing = false;
    }
}
