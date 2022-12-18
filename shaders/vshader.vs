#version 330 core

layout (location = 0)in vec3 vVertex;
layout (location = 1)in vec3 vNormal; 

uniform mat4 vModel;
uniform mat4 vView;
uniform mat4 vProjection;
uniform vec4 vColor;

const vec3 palette[21] = vec3[21](
	vec3(9.0,9.0,121.0),
	vec3(0.0,194.0,182.0),
	vec3(0.0,220.0,104.0),
	vec3(49.0,237.0,95.0),
	vec3(66.0,251.0,75.0),
	vec3(105.0,255.0,54.0),
	vec3(188.0,255.0,50.0),
	vec3(239.0,252.0,19.0),
	vec3(250.0,251.0,50.0),
	vec3(255.0,221.0,0.0),
	vec3(255.0,196.0,0.0),
	vec3(255.0,170.0,0.0),
	vec3(255.0,149.0,0.0),
	vec3(255.0,128.0,0.0),
	vec3(236.0,127.0,19.0),
	vec3(193.0,114.0,36.0),
	vec3(149.0,101.0,53.0),
	vec3(130.0,89.0,48.0),
	vec3(111.0,77.0,43.0),
	vec3(60.0,45.0,30.0),
	vec3(240.0,240.0,240.0)
);

out vec3 fragNorm;
out vec3 fragPos;

out vec4 fColor;

void main() {
	vec3 test = vNormal;
	fragNorm = normalize(vec3(transpose(inverse(vModel)) * vec4(vNormal, 1.0)));
	fragPos = vec3(vModel * vec4(vVertex, 1.0));
	gl_Position = vProjection * vView * vModel * vec4(vVertex, 1.0);
	float p = (vVertex.y + 20.0)/200;
	int s = int(p/0.05);
	if(s >= 20)fColor = vColor*vec4(palette[20]/255.0,1.0);
	else if(s <= 0)fColor = vColor*vec4(palette[0]/255.0,1.0);
	else
	{
	float t = (p-s*0.05)/0.05;
	vec3 col = (1-t)*(palette[s]/255.0) + t*(palette[s+1]/255.0);
	fColor = vColor*vec4(col,1.0); //Interpolate color
	}
		
}
