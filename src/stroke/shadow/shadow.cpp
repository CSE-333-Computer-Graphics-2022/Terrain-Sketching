#include "shadow.hpp"

void Shadow::setupShadow() {
	// define expanded vertices lol
	for(int i = 0; i < NUM_V; i++) {
		expanded_vertices[i*3] = coordinates[i].x;
		expanded_vertices[(i*3) + 1] = coordinates[i].y;
		expanded_vertices[(i*3) + 2] = coordinates[i].z;
	}
}

