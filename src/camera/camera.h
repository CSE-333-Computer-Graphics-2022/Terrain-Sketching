#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
private:
    glm::vec3 cam_position, look_atPosition;
    glm::mat4 view_t, projection_t;
    float fov, near, far;
    
public:
    Camera(glm::vec3 pos, glm::vec3 look_at, float _fov, float near_clip, float far_clip, unsigned int & shader_program):
        cam_position(pos), look_atPosition(look_at), fov(_fov), near(near_clip), far(far_clip){
            setupViewTransformation(shader_program);
            setupProjectionTransformation(shader_program);
        }

    void setupViewTransformation(unsigned int &shader_program);
    void setupProjectionTransformation(unsigned int &shader_program);
};
#endif