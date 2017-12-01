// Vertex Shader

#version 400

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec4 inColor;
layout (location = 3) in vec2 inUV;

out DATA {
	vec2 uv;
	vec4 color;
} Out;

void main() {
	gl_Position = proj * view * model * inPosition;
	Out.uv = inUV;
	Out.color = inColor;
}