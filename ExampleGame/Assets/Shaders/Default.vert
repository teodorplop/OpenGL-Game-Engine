// Vertex Shader

#version 400

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec4 inColor;
layout (location = 3) in vec2 inUV;

out DATA {
	vec4 color;
} Out;

void main() {
	gl_Position = inPosition;
	Out.color = inColor;
}