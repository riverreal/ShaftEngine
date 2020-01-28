#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
    class World;

	class BillboardSystem
	{
    public:
        BillboardSystem(EngineEntityManager* e, World* world);
        ~BillboardSystem();

        void Update();
        
    private:
        EngineEntityManager* m_entityManager;
        World* m_world;
    };    
}
