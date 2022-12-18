#ifndef SILHOUETTE_MODE_H
#define SILHOUETTE_MODE_H

#include <stroke/silhouette/silhouette.hpp>
#include <camera/camera.hpp>
#include <vector>

class SilhouetteMode
{
private:
    bool drawing;
    Camera *cam;
    Silhouette *stroke;
    std::vector<GLfloat> coordinates;
    Terrain *base_terrain;
    void addSilhouette();
    glm::vec3 getWorldPos(double x, double y, int display_w, int display_h);

public:
    SilhouetteMode(Camera *_cam, Terrain *_terrain)
    {
        cam = _cam;
        base_terrain = _terrain;
        stroke = new Silhouette(_terrain);
        drawing = false;
    }
    void setupSilhouette(unsigned int &shader_program) { stroke->setup(shader_program); }
    void drawSilhouette(unsigned int &shader_program) { stroke->draw(shader_program); }
    void process_input(GLFWwindow *window, float delta_time);
};

#endif