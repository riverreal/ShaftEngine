#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class MeshManager;

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		void Initialize();

		MeshManager& GetMeshManager();

	private:
		std::unique_ptr<MeshManager> m_meshManager;
	};
}