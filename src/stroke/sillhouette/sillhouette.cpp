#include "sillhouette.hpp"
#include <iostream>

void Sillhouette::setupSillhouette() {
	// define expanded vertices lol
	for(int i = 0; i < NUM_V; i++) {
		expanded_vertices[i*3] = coordinates[i].x;
		expanded_vertices[(i*3) + 1] = coordinates[i].y;
		expanded_vertices[(i*3) + 2] = coordinates[i].z;
	}
}

// Sillhouette::Sillhouette(std::vector<glm::vec3 > _coordinates):
// coordinates(_coordinates)
// {	
// 	NUM_V = coordinates.size();
// 	NUM_EXPANDED_VERTICES = NUM_V * 3;
// 	expanded_vertices = new GLfloat[NUM_V * 3];
// 	setupSillhouette();
// }

Sillhouette::Sillhouette() {
	// std::vector <glm::vec3 > sample_coords;
	std::ifstream input_fstream("/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/sillhouette/point-samples.txt");
	float x,y,z;
	while(!input_fstream.eof()) {
		input_fstream >> x >> y >> z;
		if(x > 1.0)continue;
		x = (x*200) - 100;
		y = y*100;
		z = (z * 200) - 100;
		coordinates.push_back(glm::vec3(x, y, z));
		// this->Sillhouette(sample_coords);
	}

	input_fstream.close();
	NUM_V = coordinates.size();
	NUM_EXPANDED_VERTICES = NUM_V * 3;
	expanded_vertices = new GLfloat[NUM_V * 3];
	setupSillhouette();
}	
