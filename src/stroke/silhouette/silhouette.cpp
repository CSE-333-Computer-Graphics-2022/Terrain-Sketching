#include "silhouette.hpp"

void Silhouette::computeShadowBoundaryCurve()
{
	//If time constraint allows modify coordToIndex such that u can binterp the height value for better
	GLuint idx;
	float y_eps = 0.5;
	GLfloat hght = 0;
	int N = silhouette_stroke->getSize();
	for(int i = 0; i <N; i++) {
		glm::vec3 coord = silhouette_stroke->getVertex(i);
		hght = std::max(hght,coord.y);
		idx = base_terrain->coordToIndex(coord.x, coord.z);
		if(idx != -1) {
			coord.y = base_terrain->getHeight(idx) + y_eps;
		}
		shadow_curve->addVertex(coord);
	}

	int lm = (N-1)/5, rm = 4*(N-1)/5;
	float d = hght*0.5;
	glm::vec3 x = shadow_curve->getVertex(N-1) - shadow_curve->getVertex(0);
	x.y = 0;
	float eps = 0.0;
	glm::vec3 n = glm::normalize(glm::cross(glm::vec3(0,1,0),x));
	for(int i = 0; i < lm; i++)boundary_curve->addVertex(n*(d*(i+eps)/(lm-1)) + shadow_curve->getVertex(i));
	for(int i = lm; i <= rm; i++)boundary_curve->addVertex(n*d + shadow_curve->getVertex(i));
	for(int i = rm; i < N; i++)boundary_curve->addVertex(n*(d*(N-i-1+eps)/(N-rm-1)) + shadow_curve->getVertex(i));
	for(int i = N-1; i > rm; i--)boundary_curve->addVertex(-n*(d*(N-i-1+eps)/(N-rm-1)) + shadow_curve->getVertex(i));
	for(int i = rm; i >= lm; i--)boundary_curve->addVertex(-n*d + shadow_curve->getVertex(i));
	for(int i = lm-1; i >= 0; i--)boundary_curve->addVertex(-n*(d*(i+eps)/(lm-1)) + shadow_curve->getVertex(i));
}

void Silhouette::computeBoundaryCurve()
{
	GLfloat hght = 0;
	int N = shadow_curve->getSize();
	int lm = (N-1)/5, rm = 4*(N-1)/5;
	glm::vec3 x = shadow_curve->getVertex(N-1) - shadow_curve->getVertex(0);
	float d = glm::length(x)*0.25;
	x.y = 0;
	float eps = 0.0;
	glm::vec3 n = glm::normalize(glm::cross(glm::vec3(0,1,0),x));
	for(int i = 0; i < lm; i++)boundary_curve->addVertex(n*(d*(i+eps)/(lm-1)) + shadow_curve->getVertex(i));
	for(int i = lm; i <= rm; i++)boundary_curve->addVertex(n*d + shadow_curve->getVertex(i));
	for(int i = rm; i < N; i++)boundary_curve->addVertex(n*(d*(N-i-1+eps)/(N-rm-1)) + shadow_curve->getVertex(i));
	for(int i = N-1; i > rm; i--)boundary_curve->addVertex(-n*(d*(N-i-1+eps)/(N-rm-1)) + shadow_curve->getVertex(i));
	for(int i = rm; i >= lm; i--)boundary_curve->addVertex(-n*d + shadow_curve->getVertex(i));
	for(int i = lm-1; i >= 0; i--)boundary_curve->addVertex(-n*(d*(i+eps)/(lm-1)) + shadow_curve->getVertex(i));



}