#version 400

#include "Lighting.txt"

in DATA {
	vec3 position;
	vec3 normal;
	vec4 color;
	vec2 uv;
	vec3 toCamera;
} In;

uniform sampler2D _MainTexture;

out vec4 outColor;

void main() {
	outColor = texture(_MainTexture, In.uv);
	outColor = ApplyLight(_Lights[0], outColor, In.position, In.normal, In.toCamera);
}
