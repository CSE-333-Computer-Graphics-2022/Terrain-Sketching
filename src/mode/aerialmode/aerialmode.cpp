#include "aerialmode.hpp"
#include <random>

void AerialMode::process_input(GLFWwindow *window, float delta_time)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        double x_pos, y_pos;
        glfwGetCursorPos(window, &x_pos, &y_pos);
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        if (drawing_stage <= 1)
        {
            glm::vec3 pos = getWorldPos(x_pos, y_pos, display_w, display_h, glm::vec3(0, 0, 0));
            int idx = base_terrain->coordToIndex(pos.x, pos.z);
            if (idx != -1)
            {
                glm::vec3 p = base_terrain->getCoord(idx);
                current_stroke->getShadowCurve()->addVertex(p);
                drawing_stage = 1;
            }
        }
        else if (drawing_stage == 2)
        {
            glm::vec3 anchor = current_stroke->getShadowCurve()->getCentroid();
            int idx1 = base_terrain->coordToIndex(anchor.x, anchor.z);
            glm::vec3 pos = getWorldPos(x_pos, y_pos, display_w, display_h, anchor);
            glm::vec3 closest_point = current_stroke->getShadowCurve()->getClosestPoint(pos);
            pos.x = closest_point.x;
            pos.z = closest_point.z;
            current_stroke->getSilhouetteCurve()->addVertex(pos);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
    {
        if (drawing_stage == 1 && current_stroke->getShadowCurve()->getSize() != 0)
        {
            current_stroke->computeBoundaryCurve();
            drawing_stage = 2;
        }
        else if (drawing_stage == 2 && current_stroke->getSilhouetteCurve()->getSize() != 0)
        {
            noisePropagate();
            deformTerrain();
            current_stroke = new Silhouette(base_terrain);
            strokes.push_back(current_stroke);
            setupAerial();
            drawing_stage = 0;
        }
    }
}

GLfloat AerialMode::getDeformationWeight(glm::vec3 point, glm::vec3 shadow_point, glm::vec3 boundary_point)
{
    GLfloat a = glm::distance(point, shadow_point) / glm::distance(boundary_point, shadow_point);
    a = std::min(a, 1.0f);
    return glm::pow(glm::pow(a, 2) - 1, 2);
}

glm::vec3 AerialMode::getWorldPos(double x, double y, int display_w, int display_h, glm::vec3 anchor)
{
    glm::mat4 invVP = glm::inverse(cam->getProjection() * cam->getView());
    glm::vec4 near = glm::vec4((x / (display_w / 2.0) - 1.0), -1 * (y / (display_h / 2.0) - 1.0), -1, 1.0);
    glm::vec4 far = glm::vec4((x / (display_w / 2.0) - 1.0), -1 * (y / (display_h / 2.0) - 1.0), 1, 1.0);
    glm::vec4 nearR = invVP * near;
    glm::vec4 farR = invVP * far;
    nearR /= nearR.w;
    farR /= farR.w;
    glm::vec3 dir = glm::normalize(glm::vec3(farR - nearR));
    glm::vec3 n = glm::vec3(0, 1, 0);
    if (!(anchor.x == 0 && anchor.y == 0 && anchor.z == 0))
    {
        n = glm::normalize(glm::vec3(cam->getOrigin() - anchor));
        n.y = 0;
        n = glm::normalize(n);
    }
    float t = glm::dot((anchor - glm::vec3(cam->getOrigin())), n) / glm::dot(dir, n);
    return glm::vec3(nearR) + t * dir;
}


void AerialMode::noisePropagate()
{
    // sample point from terrain
    int max_terrain_points = base_terrain->getNumV();
    std::mt19937 gen(42);
    // mean, std
    float var = std::sqrt(current_stroke->getSilhouetteCurve()->getVariance());
    std::normal_distribution<> d(0, var);
    for (int i = 0; i < max_terrain_points; i++)
    {
        glm::vec3 terrain_point = base_terrain->getCoord(i);
        glm::vec3 shadow_point = this->current_stroke->getShadowCurve()->getClosestPoint(terrain_point);
        glm::vec3 silhouette_point = this->current_stroke->getSilhouetteCurve()->getVertex(this->current_stroke->getShadowCurve()->coordToIndex(shadow_point));
        glm::vec3 boundary_point = this->current_stroke->getBoundaryCurve()->getClosestPoint(terrain_point);

        // if(this->current_stroke->getBoundaryCurve()->insideBoundary(terrain_point) == false) {
        //     continue;
        // }
        GLfloat deform_weight = getDeformationWeight(terrain_point, shadow_point, boundary_point);
        if (deform_weight == 0.0)
            continue;
        GLfloat curr_height = base_terrain->getHeight(i);
        GLfloat del_terrain = ((1 - deform_weight) * (curr_height)) + ((deform_weight)*d(gen)) - curr_height;
        if (-del_terrain > 1.0)
            continue;
        base_terrain->addHeight(del_terrain, i);
    }

    base_terrain->update();
    // draw or update xD
}

// deforms terrain
void AerialMode::deformTerrain()
{
    // sample point from terrain
    int max_terrain_points = base_terrain->getNumV();

    for (int i = 0; i < max_terrain_points; i++)
    {
        glm::vec3 terrain_point = base_terrain->getCoord(i);
        glm::vec3 shadow_point = this->current_stroke->getShadowCurve()->getClosestPoint(terrain_point);
        glm::vec3 silhouette_point = this->current_stroke->getSilhouetteCurve()->getVertex(this->current_stroke->getShadowCurve()->coordToIndex(shadow_point));
        glm::vec3 boundary_point = this->current_stroke->getBoundaryCurve()->getClosestPoint(terrain_point);

        // if(this->current_stroke->getBoundaryCurve()->insideBoundary(terrain_point) == false) {
        //     continue;
        // }

        GLfloat deform_weight = getDeformationWeight(terrain_point, shadow_point, boundary_point);

        GLfloat del_terrain = deform_weight * (silhouette_point.y - shadow_point.y);

        base_terrain->addHeight(del_terrain, i);
    }
    base_terrain->updateNormals();

    base_terrain->update();
    // draw or update xD
}