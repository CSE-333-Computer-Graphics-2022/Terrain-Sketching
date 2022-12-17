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
	static Terrain *base_terrain;
	void computeShadowCurve();
	void computeBoundaryCurve();
public:
	Silhouette()
	{
		silhouette_stroke =  new Stroke();
		// shadow_curve =  new Stroke();
		// boundary_curve =  new Stroke();
	}
	static void setTerrain(Terrain *_terrain){base_terrain = _terrain;}
	
	void setup(unsigned int &shader_program){
		silhouette_stroke->setup(shader_program);
	}
	void draw(unsigned int &shader_program){
		silhouette_stroke->draw(shader_program);
	}
	void addSilhouetteVertex(glm::vec3 vertex){
		silhouette_stroke->update(vertex);
	}
};





#endif