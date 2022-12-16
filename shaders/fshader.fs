#version 330 core

uniform vec3 lightPosWorld; 
uniform vec3 lightColor;
uniform vec3 eye_pos; // camera pos 
uniform float alpha;

in vec4 fColor;
out vec4 outColor;

in vec3 fragNorm;
in vec3 fragPos;

vec3 ks = vec3(0.5, 0.5, 0.5);
vec3 kd = vec3(0.7, 0.7, 0.7);
vec3 ka = vec3(0.25, 0.25, 0.25);

float spec_exp = 32.0;



void main(void) {

        vec3 light_dir = normalize(lightPosWorld - fragPos);
	vec3 Ia = ka * lightColor;
	vec3 Id = kd * (max(0, dot(light_dir, fragNorm))*lightColor);
	
	vec3 v = normalize(eye_pos - fragPos);
	vec3 h = normalize(light_dir + v);
	vec3 Is = ks * (max(pow(dot(fragNorm, h), spec_exp), 0) * lightColor);
	
        vec3 fColorResult = (Ia + Id + Is); //Interpolate color


        outColor = fColor * vec4(fColorResult, alpha);
}
