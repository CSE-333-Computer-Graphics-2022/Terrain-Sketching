#version 330

/* \brief Vertex GLSL shader that demonstrates how to draw basic thick and smooth lines in 3D.
 * This file is a part of shader-3dcurve example (https://github.com/vicrucann/shader-3dcurve).
 *
 * \author Victoria Rudakova
 * \date January 2017
 * \copyright MIT license
*/

uniform mat4 vModel;
uniform mat4 vView;
uniform mat4 vProjection;
uniform vec4 vColor;

layout(location = 0) in vec3 vVertex;

out VertexData{
    vec4 mColor;
} VertexOut;

void main(void)
{
    VertexOut.mColor = vColor;
    gl_Position = vProjection * vView * vModel * vec4(vVertex , 1.0);
}
