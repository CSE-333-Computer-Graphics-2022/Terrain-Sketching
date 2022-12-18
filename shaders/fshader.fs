#version 330 core

uniform vec3 lightPosWorld; 
uniform vec3 lightColor;
uniform vec3 eye_pos; // camera pos 
uniform float alpha;

in vec4 fColor;
out vec4 outColor;

in vec3 fragNorm;
in vec3 fragPos;

vec3 ks = vec3(0.01, 0.01, 0.01);
vec3 kd = vec3(0.85, 0.85, 0.85);
vec3 ka = vec3(0.2, 0.2, 0.2);

float spec_exp = 64.0;



void main(void) {
	vec3 N = normalize(fragNorm);
    vec3 light_dir = normalize(lightPosWorld - fragPos);
	vec3 Ia = ka * lightColor;
	vec3 Id = kd * (max(0, dot(light_dir, N))*lightColor);
	
	vec3 v = normalize(eye_pos - fragPos);
	vec3 h = normalize(light_dir + v);
	vec3 Is = ks * (pow(max(dot(N, h), 0.0), spec_exp) * lightColor);
	
        vec3 fColorResult = (Ia + Id + Is); //Interpolate color
        outColor = fColor * vec4(fColorResult, 1.0);
}
