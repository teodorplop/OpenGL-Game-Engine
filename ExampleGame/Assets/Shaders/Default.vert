#version 400

uniform mat4 _Model;
uniform mat4 _View;
uniform mat4 _Proj;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec4 inColor;
layout (location = 3) in vec2 inUV;

uniform vec4 _ClipPlane;

out DATA {
	vec3 position;
	vec3 normal;
	vec4 color;
	vec2 uv;
	vec3 toCamera;
} Out;

void main() {
	vec4 worldPosition = _Model * inPosition;
	gl_Position = _Proj * _View * worldPosition;
	gl_ClipDistance[0] = dot(worldPosition, _ClipPlane);

	Out.position = worldPosition.xyz;
	Out.normal = (_Model * vec4(inNormal, 0)).xyz;
	Out.color = inColor;
	Out.uv = inUV;
	Out.toCamera = (inverse(_View) * vec4(0, 0, 0, 1)).xyz - worldPosition.xyz;
}
