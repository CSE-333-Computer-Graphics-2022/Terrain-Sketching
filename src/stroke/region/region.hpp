#ifndef REGION_H
#define REGION_H

#include "stroke/stroke.hpp"
#include "terrain/terrain.hpp"

/*
Class that defines instances of strokes in Region mode.
region_stroke = boundary curve defined by user
noise_curve = noise curve defined by user
*/

class Region
{
    Stroke *region_stroke, *noise_curve;
    Terrain *base_terrain;

public:
    Region(Terrain *_terrain)
    {
        base_terrain = _terrain;
        region_stroke = new Stroke();
        noise_curve = new Stroke();
    }

    void setup(unsigned int &shader_program)
    {
        region_stroke->setup(shader_program);
        noise_curve->setup(shader_program);
    }

    void draw(unsigned int &shader_program)
    {
        region_stroke->draw(shader_program);
        noise_curve->draw(shader_program);
    }

    void addRegionVertex(glm::vec3 vertex)
    {
        region_stroke->addVertex(vertex);
    }

    void addNoiseVertex(glm::vec3 vertex)
    {
        noise_curve->addVertex(vertex);
    }

    Stroke *getNoiseCurve(){return noise_curve;}
    Stroke *getRegionStroke(){return region_stroke;}

};

#endif