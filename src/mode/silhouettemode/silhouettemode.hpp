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
    void addSilhouette();
    glm::vec3 getWorldPos(double x, double y);

public:
    SilhouetteMode(Camera *_cam)
    {
        cam = _cam;
        stroke = new Silhouette();
        drawing = false;
    }
    void setupSilhouette(unsigned int &shader_program) { stroke->setup(shader_program); }
    void drawSilhouette(unsigned int &shader_program) { stroke->draw(shader_program); }
    void process_input(GLFWwindow *window, float delta_time);
};

#endif