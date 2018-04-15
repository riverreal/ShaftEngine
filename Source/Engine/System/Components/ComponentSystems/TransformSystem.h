#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class TransformSystem
	{
	public:
		TransformSystem(EngineEntityManager* eManager);
		~TransformSystem();

		void Initialize();
		void Update();

	private:
		void UpdateMatrix();
		void LocalMatrixPass();
		void WorldMatrixPass();

	private:
		EngineEntityManager* m_entityManager;
	};
}