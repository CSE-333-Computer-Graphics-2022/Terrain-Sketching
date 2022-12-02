#version 330 core

layout (location = 0)in vec3 vVertex;
layout (location = 1)in vec3 vNormal; 

uniform mat4 vModel;
uniform mat4 vView;
uniform mat4 vProjection;
uniform vec4 vColor;

out vec3 fragNorm;
out vec3 fragPos;

out vec4 fColor;

void main() {
	vec3 test = vNormal;
	fragNorm = normalize(vec3(transpose(inverse(vModel)) * vec4(vNormal, 1.0)));
	fragPos = vec3(vModel * vec4(vVertex, 1.0));
	gl_Position = vProjection * vView * vModel * vec4(vVertex, 1.0);
	fColor = vColor; //Interpolate color
}
