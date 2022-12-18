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
        glm::vec3 pos = getWorldPos(x_pos, y_pos, display_w, display_h);
        int idx = base_terrain->coordToIndex(pos.x, pos.z);
        if (idx != -1 && base_terrain->getHeight(idx) <= pos.y)
            stroke->addSilhouetteVertex(pos);
        drawing = true;
    }
    else
    {
        // if(drawing)computeShadowBoundary(); //Done with stroke, render its shadow and boundary and start new stroke.
        if (drawing)
        {
            stroke->computeShadowBoundaryCurve();
        }
        drawing = false;
    }
    if(glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS && !drawing)
    {
        deformTerrain();
    }
}
glm::vec3 SilhouetteMode::getWorldPos(double x, double y, int display_w, int display_h)
{
    glm::mat4 invVP = glm::inverse(cam->getProjection() * cam->getView());
    glm::vec4 near = glm::vec4((x / (display_w / 2.0) - 1.0), -1 * (y / (display_h / 2.0) - 1.0), -1, 1.0);
    glm::vec4 far = glm::vec4((x / (display_w / 2.0) - 1.0), -1 * (y / (display_h / 2.0) - 1.0), 1, 1.0);
    glm::vec4 nearR = invVP * near;
    glm::vec4 farR = invVP * far;
    nearR /= nearR.w;
    farR /= farR.w;
    glm::vec3 dir = glm::normalize(glm::vec3(farR - nearR));
    glm::vec3 n = glm::normalize(glm::vec3(cam->getOrigin() - glm::vec3(0, 0, 0)));
    n.y = 0;
    n = glm::normalize(n);
    float t = glm::dot((glm::vec3(0, 0, 0) - glm::vec3(nearR)), n) / glm::dot(dir, n);
    return glm::vec3(nearR) + t * dir;
}

// C1 blending functin
GLfloat SilhouetteMode::getDeformationWeight(glm::vec3 point, glm::vec3 shadow_point, glm::vec3 boundary_point) {
    GLfloat a = glm::distance(point, shadow_point)/glm::distance(boundary_point, shadow_point);
    a = std::min(a,1.0f);
    return glm::pow(glm::pow(a, 2) - 1, 2);
}

// deforms terrain
void SilhouetteMode::deformTerrain() {
    // sample point from terrain
    int max_terrain_points = base_terrain->getNumV();

    for(int i = 0; i < max_terrain_points; i++) {
        glm::vec3 terrain_point = base_terrain->getCoord(i);
        glm::vec3 shadow_point = this->stroke->getShadowCurve()->getClosestPoint(terrain_point);
        glm::vec3 silhouette_point = this->stroke->getSilhouetteCurve()->getVertex(this->stroke->getShadowCurve()->coordToIndex(shadow_point));
        glm::vec3 boundary_point = this->stroke->getBoundaryCurve()->getClosestPoint(terrain_point);

        // if(this->stroke->getBoundaryCurve()->insideBoundary(terrain_point) == false) {
        //     continue;
        // }

        GLfloat deform_weight = getDeformationWeight(terrain_point, shadow_point, boundary_point);


        GLfloat del_terrain = deform_weight * (silhouette_point.y - shadow_point.y);

        base_terrain->addHeight(del_terrain, i);
    }

    base_terrain->update();
    // draw or update xD
}