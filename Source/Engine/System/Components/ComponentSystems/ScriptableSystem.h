#ifndef _SCRIPTABLE_SYSTEM_H_
#define _SCRIPTABLE_SYSTEM_H_
#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class ScriptableSystem
	{
	public:
		ScriptableSystem(EngineEntityManager* eManager);
		~ScriptableSystem();

		void UpdateScripts(float deltaTime);
		void DelayedUpdateScripts(float deltaTime);
		void FixedUpdateScripts(float deltaTime);

	private:
		EngineEntityManager::View* m_cachedEntities;
		EngineEntityManager* m_entityManager;
	};
}

#endif //_SCRIPTABLE_SYSTEM_H_