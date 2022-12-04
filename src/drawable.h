#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <GL/glew.h>

class Drawable
{
    protected:
    GLuint *vao;
    GLuint *vbo;

    public:
    virtual void setup(unsigned int& shader_program) = 0;
    virtual void draw(unsigned int& shader_program) = 0;

};
#endif