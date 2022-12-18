#ifndef REGION_MODE_H
#define REGION_MODE_H

#include "stroke/region/region.hpp"
#include <camera/camera.hpp>
#include <vector>

class RegionMode
{
private:
    int drawing_stage; //0 new 1 drawing region 2 drawing noise
    bool first;
    std::vector<Region *> strokes;
    Region *current_stroke;
    Terrain *base_terrain;
    Camera *cam;
    unsigned int shader_program;
    glm::vec3 getWorldPos(double x, double y, int display_w, int display_h, glm::vec3 anchor);
    glm::vec3 first_vertex,centroid_point;
    void noisePropagate();
    GLfloat getDeformationWeight(glm::vec3 point, glm::vec3 shadow_point, glm::vec3 boundary_point);
public:
    RegionMode(Camera *_cam, Terrain *_terrain, unsigned int &_shader_program)
    {
        base_terrain = _terrain;
        current_stroke = new Region(_terrain);
        strokes.push_back(current_stroke);
        cam = _cam;
        shader_program = _shader_program;
        setupRegion();
        drawing_stage = 0;
        first = true;
    }
    void setupRegion()
    {
        current_stroke->setup(shader_program);
    }

    void drawRegion()
    {
        for (auto &stroke : strokes)
            stroke->draw(shader_program);
    }
    void process_input(GLFWwindow *window, float delta_time);
    void deformTerrain();
};

#endif