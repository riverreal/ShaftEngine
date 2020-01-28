#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class CameraSystem
	{
	public:
        CameraSystem(EngineEntityManager* manager);
        ~CameraSystem();

        void Initialize(float w, float h);
        void Update();
    
    private:
        EngineEntityManager* m_entityManager;
        // Screen width and height
        float m_width;
        float m_height;
    };
}