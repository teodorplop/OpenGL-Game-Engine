#version 400

#include "Lighting.txt"

in DATA {
	vec4 position;
	vec3 normal;
	vec2 uv;
	vec3 toCamera;
} In;

uniform float _Time;
uniform float _CameraNear;
uniform float _CameraFar;
uniform sampler2D _WaterFBO_ReflectionSampler;
uniform sampler2D _WaterFBO_RefractionSampler;
uniform sampler2D _WaterFBO_RefractionDepthSampler;

uniform sampler2D _DUDVSampler;
uniform sampler2D _NormalSampler;

uniform float _MoveFactor;
uniform float _DistorsionStrength;
uniform float _SpecularPower;

out vec4 outColor;

void main() {
	vec2 normalizedDeviceCoord = (In.position.xy / In.position.w) / 2.0 + 0.5;
	vec2 reflectionTextureCoord = vec2(normalizedDeviceCoord.x, -normalizedDeviceCoord.y);
	vec2 refractionTextureCoord = vec2(normalizedDeviceCoord.x, normalizedDeviceCoord.y);

	float terrainDepth = texture(_WaterFBO_RefractionDepthSampler, refractionTextureCoord).r;
	float terrainDistance = 2.0 * _CameraNear * _CameraFar / (_CameraFar + _CameraNear - (2.0 * terrainDepth - 1.0) * (_CameraFar - _CameraNear));

	float fragmentDepth = gl_FragCoord.z;
	float fragmentDistance = 2.0 * _CameraNear * _CameraFar / (_CameraFar + _CameraNear - (2.0 * fragmentDepth - 1.0) * (_CameraFar - _CameraNear));

	float waterDepth = terrainDistance - fragmentDistance;

	vec2 distortedTexCoords = texture(_DUDVSampler, vec2(In.uv.x + _MoveFactor * _Time, In.uv.y)).rg * 0.1;
	distortedTexCoords = In.uv + vec2(distortedTexCoords.x, distortedTexCoords.y + _MoveFactor * _Time);
	vec2 totalDistortion = (texture(_DUDVSampler, distortedTexCoords).rg * 2.0 - 1.0) * _DistorsionStrength * clamp(waterDepth / 20.0, 0.0, 1.0);

	refractionTextureCoord += totalDistortion;
	refractionTextureCoord = clamp(refractionTextureCoord, 0.001, 0.999);

	reflectionTextureCoord += totalDistortion;
	reflectionTextureCoord.x = clamp(reflectionTextureCoord.x, 0.001, 0.999);
	reflectionTextureCoord.y = clamp(reflectionTextureCoord.y, -0.999, -0.001);

	vec4 reflectColor = texture(_WaterFBO_ReflectionSampler, reflectionTextureCoord);
	vec4 refractColor = texture(_WaterFBO_RefractionSampler, refractionTextureCoord);

	vec4 normalMapColor = texture(_NormalSampler, distortedTexCoords);
	vec3 normal = vec3(normalMapColor.r * 2.0 - 1.0, normalMapColor.b * 3.0, normalMapColor.g * 2.0 - 1.0);
	normal = normalize(normal);

	vec3 viewVector = normalize(In.toCamera);
	float refractiveFactor = dot(viewVector, normal);
	refractiveFactor = pow(refractiveFactor, 0.5);
	refractiveFactor = clamp(refractiveFactor, 0.001, 0.999);

	vec3 reflectedLight = reflect(normalize(FromLightVector(_Lights[0])), normal);
	float specular = max(dot(reflectedLight, viewVector), 0.0);
	specular = pow(specular, _SpecularPower);
	vec3 specularHighlights = _Lights[0].color.rgb * specular * 0.5;

	outColor = mix(reflectColor, refractColor, refractiveFactor);
	outColor = mix(outColor, vec4(0.0, 0.3, 0.5, 1.0), 0.2) + vec4(specularHighlights, 0);
	outColor.a = clamp(waterDepth / 5.0, 0.0, 1.0);
}