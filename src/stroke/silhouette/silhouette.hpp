#ifndef SILHOUETTE_H
#define SILHOUETTE_H

#include "../stroke.hpp"
#include "../shadow/shadow.hpp"
#include "../boundary/boundary.hpp"
#include "../../terrain/terrain.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>


/*
Class that defines instances of silhouettes in Silhouette Mode.
silhouette_stroke = the silhouette curve drawn by the user.
shadow_curve = shadow curve automatically computed as silhouette subtended over the terrain.
boundary_curve = boundary curve automatically computed as a function of shadow with constant distance in between tapering off to the edges
*/

class Silhouette
{
private:
	Stroke *silhouette_stroke, *shadow_curve, *boundary_curve; 
	Terrain *base_terrain;
public:
	void computeShadowBoundaryCurve();
	void computeBoundaryCurve();
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

	Stroke* getShadowCurve() {
		return shadow_curve;
	}

	Stroke* getBoundaryCurve() {
		return boundary_curve;
	}

	Stroke* getSilhouetteCurve() {
		return silhouette_stroke;
	}

};





#endif