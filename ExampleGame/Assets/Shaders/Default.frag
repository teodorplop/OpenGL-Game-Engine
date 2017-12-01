// Fragment Shader 

#version 400

in DATA {
	vec2 uv;
	vec4 color;
} In;

uniform sampler2D mainTexture;

out vec4 outColor;

void main() {
	outColor = texture(mainTexture, In.uv);
}