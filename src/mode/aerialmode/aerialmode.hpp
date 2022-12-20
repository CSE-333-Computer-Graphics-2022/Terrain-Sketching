#ifndef AERIAL_MODE_H
#define AERIAL_MODE_H

#include <camera/camera.hpp>
#include "stroke/silhouette/silhouette.hpp"
#include <vector>

/*
Aerial Mode:
    Implementation of the Aerial Mode. 
    Works by drawing the base plane shadow first and then silhouette on top.
*/


class AerialMode
{
    int drawing_stage; //0 new 1 drawing shadow 2 drawing silhouette
    std::vector<Silhouette *>strokes; //Multiple Strokes
    Silhouette *current_stroke;
    Terrain *base_terrain;
    Camera *cam;
    unsigned int shader_program;
    glm::vec3 getWorldPos(double x, double y, int display_w, int display_h, glm::vec3 anchor);
    void noisePropagate();
    GLfloat getDeformationWeight(glm::vec3 point, glm::vec3 shadow_point, glm::vec3 boundary_point);
    void computeBoundaryCurve();

public:
    AerialMode(Camera *_cam, Terrain *_terrain, unsigned int &_shader_program)
    {
        base_terrain = _terrain;
        current_stroke = new Silhouette(_terrain);
        strokes.push_back(current_stroke);
        cam = _cam;
        shader_program = _shader_program;
        setupAerial();
        drawing_stage = 0;
    }
    void setupAerial()
    {
        current_stroke->setup(shader_program);
    }

    void drawAerial()
    {
        for (auto &stroke : strokes)
            stroke->draw(shader_program);
    }
    void process_input(GLFWwindow *window, float delta_time);
    void deformTerrain();
};

#endif