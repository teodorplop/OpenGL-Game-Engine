#version 400

uniform mat4 _Model;
uniform mat4 _View;
uniform mat4 _Proj;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 3) in vec2 inUV;

out DATA {
	vec4 position;
	vec3 normal;
	vec2 uv;
	vec3 toCamera;
} Out;

uniform float _TextureTiling;

void main() {
	vec4 worldPosition = _Model * inPosition;
	gl_Position = _Proj * _View * worldPosition;

	Out.position = gl_Position;
	Out.normal = (_Model * vec4(inNormal, 0)).xyz;
	Out.uv = inUV * _TextureTiling;
	Out.toCamera = (inverse(_View) * vec4(0, 0, 0, 1)).xyz - worldPosition.xyz;
}
