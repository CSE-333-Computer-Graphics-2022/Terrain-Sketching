#ifndef SILHOUETTE_MODE_H
#define SILHOUETTE_MODE_H

#include <stroke/silhouette/silhouette.hpp>


class SilhouetteMode
{
private:
    bool drawing;
    Silhouette *silhouette_stroke;
public:
    SilhouetteMode()
    {
        drawing = false;
        // silhouette_stroke = new Silhouette();
    }
    void process_input(GLFWwindow *window, float delta_time);
};

#endif