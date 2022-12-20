#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <GL/glew.h>

/*
Abstract drawable interface for all the elements drawn on the screen.
vao, vbo - respective vertex array object and vertex buffer object.
setup() - sets up the vbo for rendering
draw() - calls gl_draw for the vao.
*/

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