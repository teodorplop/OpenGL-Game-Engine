#pragma once

#include "Export.h"
#include "Mesh.h"
#include "Material.h"
#include "Component.h"

class MeshRenderer : public Component {
	Mesh* mesh;
	Material* sharedMat;
	Material* mat;

protected:
	OPENGL_ENGINE_API void Deserialize(const std::string& serializedState);

public:
	MeshRenderer();
	virtual ~MeshRenderer();

	OPENGL_ENGINE_API void SetMesh(Mesh* mesh);
	OPENGL_ENGINE_API void SetMaterial(Material* material);

	OPENGL_ENGINE_API Mesh* GetMesh();
	OPENGL_ENGINE_API Material* GetMaterial();
	OPENGL_ENGINE_API Material* GetSharedMaterial();

	bool RendersWater();
};
