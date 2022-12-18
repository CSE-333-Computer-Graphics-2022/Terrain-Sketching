#ifndef SILHOUETTE_H
#define SILHOUETTE_H

#include "../stroke.hpp"
#include "../shadow/shadow.hpp"
#include "../boundary/boundary.hpp"
#include "../../terrain/terrain.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>


class Silhouette
{
private:
	Stroke *silhouette_stroke, *shadow_curve, *boundary_curve; 
	Terrain *base_terrain;
public:
	void computeShadowBoundaryCurve();
	Silhouette(Terrain * _terrain)
	{
		base_terrain = _terrain;
		silhouette_stroke =  new Stroke();
		shadow_curve =  new Stroke();
		boundary_curve =  new Stroke();
	}
	
	void setup(unsigned int &shader_program){
		silhouette_stroke->setup(shader_program);
		shadow_curve->setup(shader_program);
		boundary_curve->setup(shader_program);
	}
	void draw(unsigned int &shader_program){
		silhouette_stroke->draw(shader_program);
		shadow_curve->draw(shader_program);
		boundary_curve->draw(shader_program);
	}
	void addSilhouetteVertex(glm::vec3 vertex){
		silhouette_stroke->addVertex(vertex);
	}
};





#endif