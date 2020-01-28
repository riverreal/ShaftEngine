#include "Renderer.h"
#include "../../System/Misc/EngineConfig.h"
#include "../Engine/World.h"
#include "../Engine/System/ResourceManager.h"
#include "../Engine/System/MeshManager.h"
#include "../Engine/System/ShaderManager.h"
#include "../Engine/Graphics/TextureManager.h"
#include "../Engine/Graphics/MaterialManager.h"
#include <bx/math.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Shaft;

Renderer::Renderer(const RendererConfig & renderConfig)
	:m_config(renderConfig),
	m_width(renderConfig.width),
	m_height(renderConfig.height),
	m_debugFlags(0),
	m_resetFlags(0)
{
}

Renderer::~Renderer()
{
	Destroy();
}

void Renderer::Initialize(World* world, ResourceManager* resourceManager)
{
	m_world = world;
	m_resourceManager = resourceManager;
	auto bgfxRenderRype = ConvertRendererTypeToBGFX(m_config.rendererType);
	m_debugFlags = BGFX_DEBUG_TEXT;
	uint32 vsyncFlag = m_config.fpsConfig.vsync ? BGFX_RESET_VSYNC : 0;
	m_resetFlags = vsyncFlag;
	if (!bgfx::init(bgfxRenderRype, 0))
	{
		throw std::runtime_error("bgfx init failed");
		return;
	}
	bgfx::reset(m_config.width, m_config.height, m_resetFlags);
	bgfx::setDebug(m_debugFlags);

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0);
}

void Renderer::Draw()
{
	auto cam = m_world->GetMainCamera();

	if(cam == nullptr)
	{
		float at[3] = { 0.0f, 0.0f, 0.0f };
		float eye[3] = { 0.0f, 0.0f, -10.0f };
		float view[16];
		bx::mtxLookAt(view, eye, at);

		float proj[16];
		bx::mtxProj(proj, 60.0f, float(m_width) / float(m_height), 0.1f, 1000.0f, bgfx::getCaps()->homogeneousDepth);
		bgfx::setViewTransform(0, view, proj);
	}
	else
	{
		auto camComp = cam->GetEntity().component<CameraComponent>();

		bgfx::setViewTransform(0, (float*)&camComp->viewMatrix, (float*)&camComp->projMatrix);
	}
	
	bgfx::setViewRect(0, 0, 0, m_width, m_height);

	bgfx::touch(0);
	
	auto mins = m_resourceManager->GetMaterialManager().GetMaterialInstances();
	auto mats = m_resourceManager->GetMaterialManager().GetMaterials();
	auto constVecUni = m_resourceManager->GetMaterialManager().GetConstVecUniforms();
	auto texUni = m_resourceManager->GetMaterialManager().GetTexUniforms();
	auto shaders = m_resourceManager->GetShaderManager().GetShaderTypes();
	auto meshes = m_resourceManager->GetMeshManager().GetMeshTypes();
	auto textures = m_resourceManager->GetTextureManager().GetTextures();

	for (auto& idActor : m_world->GetActors())
	{
		auto actor = idActor.actor.get();
		auto meshComp = actor->GetEntity().component<MeshComponent>();
		auto transform = actor->GetEntity().component<Transform>();
		if (meshComp != nullptr && transform != nullptr)
		{
			auto& meshType = meshes[meshComp->meshId];
			if (!meshType.created)
			{
				continue;
			}

			glm::mat4 mat4 = transform->worldMatrix.GetMat();
			float* mat = glm::value_ptr(mat4);
			bgfx::setTransform(mat);
			bool interrupt = false;
			//Texture uniforms
			for (uint32 i = 0; i < mats[mins[meshComp->matInstanceId].materialID].enabledTextureCount; ++i)
			{
				auto& texture = textures[mins[meshComp->matInstanceId].textures[i]];
				if (!texture.created)
				{
					std::cout << "Texture not created yet! Load it first before using." << std::endl;
					bgfx::setTexture(i, texUni[i], textures[0].tex);
				}
				else
				{
					bgfx::setTexture(i, texUni[i], texture.tex);
				}
			}

			if (interrupt)
			{
				continue;
			}

			//Const vec uniforms
			for (uint32 i = 0; i < mats[mins[meshComp->matInstanceId].materialID].enabledConstVecCount; ++i)
			{
				bgfx::setUniform(constVecUni[i], (float*)&mins[meshComp->matInstanceId].constVec[i]);
			}

			bgfx::setVertexBuffer(0, meshType.vb);
			bgfx::setIndexBuffer(meshType.ib);

			bgfx::setState(0
				| BGFX_STATE_WRITE_RGB 
				| BGFX_STATE_WRITE_A
				| BGFX_STATE_WRITE_Z 
				| BGFX_STATE_DEPTH_TEST_LESS
				| BGFX_STATE_MSAA 
				| (uint32)meshComp->states.culling
			);

			bgfx::submit(0, shaders[mats[mins[meshComp->matInstanceId].materialID].shaderType].programHandle);
		}
	}

	bgfx::frame();
}

void Renderer::Destroy()
{
	bgfx::shutdown();
}
