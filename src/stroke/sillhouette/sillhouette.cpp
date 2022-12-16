#include "sillhouette.hpp"
#include <iostream>
#include <vector>

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

Sillhouette::Sillhouette(Terrain* _terrain):
terrain(_terrain)
 {
	// std::vector <glm::vec3 > sample_coords;
	std::ifstream input_fstream("/run/media/lot1aus/hdd_2/CG Class/project/Terrain-Sketching/src/stroke/sillhouette/point-samples.txt");
	// std::ifstream input_fstream("/Users/vibster/Developer/CSE333-CG/Project/Terrain-Sketching/src/stroke/sillhouette/point-samples.txt");
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
	setupShadow();
	setupBoundary();
}	


void Sillhouette::setupShadow() {
	float y;
	GLuint idx;
	std::vector<glm::vec3 > shadow_coordinates;
	float y_eps = 0.5;
	for(int i = 0; i < NUM_V; i++) {
		y = y_eps;
		idx = terrain->coordToIndex(coordinates[i].x, coordinates[i].z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}
		shadow_coordinates.push_back(glm::vec3(coordinates[i].x, y, coordinates[i].z));
	}

	shadow = new Shadow(shadow_coordinates);
}

void Sillhouette::setupBoundary() {
	std::vector<glm::vec3 > boundary_coordinates;
	float y_eps = 0.5;
	// float z =
	float y;
	// phase dl to dr: straight 
	GLuint idx_delta = 50;
	float left_x = coordinates[idx_delta].x;
	float left_z = coordinates[idx_delta].z;
	float right_x = coordinates[NUM_V - idx_delta].x + 50;
	float right_z = coordinates[NUM_V - idx_delta].z - 50;

	int num_div = 500 - 2*idx_delta;
	float del_x = (right_x - left_x)/num_div;
	float del_z = (right_z - left_z)/num_div;

	float curr_x = left_x + 50;
	float curr_z = left_z - 50; 

	for(int i = 0; i < num_div; i++) {
		y = y_eps;
		int idx = terrain->coordToIndex(curr_x, curr_z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}

		boundary_coordinates.push_back(glm::vec3(curr_x, y, curr_z));
		curr_x += del_x;
		curr_z += del_z;
	}

	// phase 2: curve from right side to major

	left_x = curr_x;
	left_z = curr_z;
	right_x = coordinates[NUM_V-1].x;
	right_z = coordinates[NUM_V-1].z;

	num_div = idx_delta;

	del_x = (right_x - left_x)/num_div;
	del_z = (right_z - left_z)/num_div;

	for(int i = 0; i < num_div; i++) {
		y = y_eps;
		int idx = terrain->coordToIndex(curr_x, curr_z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}

		boundary_coordinates.push_back(glm::vec3(curr_x, y, curr_z));
		curr_x += del_x;
		curr_z += del_z;	
	}


	// phase 3 curve from 
	left_x = curr_x;
	left_z = curr_z;
	right_x = coordinates[NUM_V - idx_delta].x - 50;
	right_z = coordinates[NUM_V - idx_delta].z + 50;

	num_div = idx_delta;

	del_x = (right_x - left_x)/num_div;
	del_z = (right_z - left_z)/num_div;

	for(int i = 0; i < num_div; i++) {
		y = y_eps;
		int idx = terrain->coordToIndex(curr_x, curr_z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}

		boundary_coordinates.push_back(glm::vec3(curr_x, y, curr_z));
		curr_x += del_x;
		curr_z += del_z;
	}

	// phase 4 straight line right to left 
	left_x = curr_x;
	left_z = curr_z;
	right_x = coordinates[idx_delta].x - 50;
	right_z = coordinates[idx_delta].z + 50;

	num_div = NUM_V - idx_delta;
		
	del_x = (right_x - left_x)/num_div;
	del_z = (right_z - left_z)/num_div;

	for(int i = 0; i < num_div; i++) {
		y = y_eps;
		int idx = terrain->coordToIndex(curr_x, curr_z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}

		boundary_coordinates.push_back(glm::vec3(curr_x, y, curr_z));
		curr_x += del_x;
		curr_z += del_z;	
	}	

	// phase 5 left most point to major axis
	left_x = curr_x;
	left_z = curr_z;
	right_x = coordinates[0].x;
	right_z = coordinates[0].z;	

	num_div = idx_delta;

	del_x = (right_x - left_x)/num_div;
	del_z = (right_z - left_z)/num_div;

	for(int i = 0; i < num_div; i++) {
		y = y_eps;
		int idx = terrain->coordToIndex(curr_x, curr_z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}

		boundary_coordinates.push_back(glm::vec3(curr_x, y, curr_z));
		curr_x += del_x;
		curr_z += del_z;
	}

	// phase 6 major axis to rejoin start of phase 1
	left_x = curr_x;
	left_z = curr_z;	
	right_x = coordinates[idx_delta].x + 50;
	right_z = coordinates[idx_delta].z - 50;

	num_div = idx_delta;

	del_x = (right_x - left_x)/num_div;
	del_z = (right_z - left_z)/num_div;	

	for(int i = 0; i < num_div; i++) {
		y = y_eps;
		int idx = terrain->coordToIndex(curr_x, curr_z);
		if(idx != -1) {
			y = terrain->getHeight(idx) + y_eps;
		}

		boundary_coordinates.push_back(glm::vec3(curr_x, y, curr_z));
		curr_x += del_x;
		curr_z += del_z;
	}



	boundary = new Boundary(boundary_coordinates);

}