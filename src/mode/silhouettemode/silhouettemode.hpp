#ifndef SILHOUETTE_MODE_H
#define SILHOUETTE_MODE_H

#include <stroke/silhouette/silhouette.hpp>
#include <camera/camera.hpp>
#include <vector>

class SilhouetteMode
{
private:
    bool drawing,terrain_drawn;
    Camera *cam;
    Silhouette* current_stroke;
    std::vector<Silhouette *>strokes;
    unsigned int shader_program;
    std::vector<GLfloat> coordinates;
    Terrain *base_terrain;
    void addSilhouette();
    glm::vec3 getWorldPos(double x, double y, int display_w, int display_h);

public:
    SilhouetteMode(Camera *_cam, Terrain *_terrain, unsigned int &_shader_program)
    {
        shader_program = _shader_program;
        cam = _cam;
        base_terrain = _terrain;
        current_stroke = new Silhouette(_terrain);
        strokes.push_back(current_stroke);
        setupSilhouette();
        drawing = false;
        terrain_drawn = false;
    }
    void setupSilhouette() { 
        current_stroke->setup(shader_program); 
    }
    void drawSilhouette() { 
        for(auto &stroke : strokes)
            stroke->draw(shader_program); 
    }
    void process_input(GLFWwindow *window, float delta_time);
    void deformTerrain();
    void noisePropagate();
    GLfloat getDeformationWeight(glm::vec3 point, glm::vec3 shadow_point, glm::vec3 boundary_point);
};

#endif