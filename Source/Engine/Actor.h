#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class Actor
	{
	public:
		Actor(EngineEntity entity);
		~Actor();
		void SetName(std::string name);
		const std::string& GetName() const;
		void AddChild(Actor* child);
		const std::vector<Actor*>& GetChilren() const;
		void SetParent(Actor* parent);

		EngineEntity& GetEntity();

	private:
		EngineEntity m_entity;
		Actor* m_parent;
		std::vector<Actor*> m_children;
		std::string m_name;
	};
}