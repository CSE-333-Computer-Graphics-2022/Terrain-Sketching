#include "silhouette.hpp"

void Silhouette::computeShadowBoundaryCurve()
{
	//If time constraint allows modify coordToIndex such that u can binterp the height value for better
	GLuint idx;
	float y_eps = 0.5;
	int N = silhouette_stroke->getSize();
	for(int i = 0; i <N; i++) {
		glm::vec3 coord = silhouette_stroke->getVertex(i);
		idx = base_terrain->coordToIndex(coord.x, coord.z);
		if(idx != -1) {
			coord.y = base_terrain->getHeight(idx) + y_eps;
		}
		shadow_curve->addVertex(coord);
	}

	int lm = 0, rm = N-1;
	float thresh = 0.1;
	while(lm < N-1 && silhouette_stroke->getVertex(lm+1).y - silhouette_stroke->getVertex(lm).y > thresh)lm++; 
	while(rm > 1 && silhouette_stroke->getVertex(rm-1).y - silhouette_stroke->getVertex(rm).y > thresh)rm--; 
	float dl = glm::distance(shadow_curve->getVertex(0),shadow_curve->getVertex(lm));
	float dr = glm::distance(shadow_curve->getVertex(shadow_curve->getSize()-1),shadow_curve->getVertex(rm));
	float d = (dl+dr)*0.5;
	glm::vec3 n = glm::normalize(glm::cross(glm::vec3(0,1,0),shadow_curve->getVertex(1) - shadow_curve->getVertex(0)));
	for(int i = 0; i < lm; i++)boundary_curve->addVertex(n*(d*i/(lm-1)) + shadow_curve->getVertex(i));
	for(int i = lm; i <= rm; i++)boundary_curve->addVertex(n*d + shadow_curve->getVertex(i));
	for(int i = rm; i < N; i++)boundary_curve->addVertex(n*(d*(N-i-1)/(N-rm-1)) + shadow_curve->getVertex(i));
	for(int i = N; i > rm; i--)boundary_curve->addVertex(-n*(d*(N-i-1)/(N-rm-1)) + shadow_curve->getVertex(i));
	for(int i = rm; i >= lm; i--)boundary_curve->addVertex(-n*d + shadow_curve->getVertex(i));
	for(int i = lm-1; i >= 0; i--)boundary_curve->addVertex(-n*(d*i/(lm-1)) + shadow_curve->getVertex(i));
}